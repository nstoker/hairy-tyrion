/*
==============================================================================

Database.cpp
Created: 07 March 2013 14:10
Author:  stokern

==============================================================================
*/

#include "JuceHeader.h"
#include "database.h"

CDatabase::CDatabase(File dbPath)
{
	if (!dbPath.existsAsFile())
		DBG(TRANS("Database does not exist, so creating blank database"));

	int status = dbSqlite.connect(dbPath.getFullPathName().toUTF8());

	if (0 == status)
		DBG(TRANS("Database exists"));
	else
	{
		DBG(TRANS("Error ") + String(status) + TRANS(" trying to connect to database"));
		// TODO Fatal error - to terminate app?
	}

}

CDatabase::~CDatabase() {}

void CDatabase::initialise()
{
	// Get sqlite version
	int sqliteVersion = execSQLscalar("SELECT sqlite_version() as sqlite_version");
	DBG(TRANS("SQLite version ") + String(sqliteVersion));

	// Enable foreign key support TODO: database browser is reporting that foreign key support is enabled!?
	command cmd(dbSqlite, "PRAGMA foreign_keys = ON");
	if (cmd.execute() == SQLITE_OK)
		DBG(TRANS("Foreign keys ON"));
	else
		DBG(TRANS("Foreign keys OFF"));

	// Ensure that the versioning table exists
	int result = cmd.prepare("CREATE TABLE IF NOT EXISTS Schema (Item TEXT PRIMARY KEY, IntValue INT) ");
	result = cmd.execute();

	if (SQLITE_OK != result)
	{
		DBG(TRANS("Failed to create table. Error# ") + String(result) + ". " + getError(result));
		return; // TODO Improve on this
	}

	// And ensure the default value is added
	cmd.prepare("INSERT OR IGNORE INTO Schema (Item, IntValue) VALUES ('Schema',0)");
	result = cmd.execute();
	if (SQLITE_OK != result)
	{
		DBG(TRANS("Failed to insert default value. Error # ") + String(result) + ". " + getError(result));
		return;
	}

	// Check schema version for updates
	int schemaVersion = execSQLscalar("SELECT IntValue FROM Schema WHERE Item = 'Schema'");
	DBG(TRANS("Schema Version ") + String(schemaVersion));

	// Upgrade Schema
	bool bResult = true;
	// The updates are organised into blocks, separated by a 0. A number of updates can be added in a single set of up updates
	const char* const updates[] = {
		// Schema Version 1: 
		"CREATE TABLE Songs (SongID INTEGER PRIMARY KEY, Title TEXT, Artist TEXT, Duration TIMESTAMP, Year TEXT)",
		"CREATE TABLE Tunings(TuningID INTEGER PRIMARY KEY, Tuning TEXT)",
		"CREATE TABLE Arrangements(ArrangementID INTEGER PRIMARY KEY, SongID INTEGER, Arrangement TEXT, TuningID INTEGER, FOREIGN KEY(SongID) REFERENCES Songs(SongID), FOREIGN KEY(TuningID) REFERENCES Tunings(TuningID) )",
		"CREATE TABLE Users (UserID INTEGER PRIMARY KEY, UserName TEXT)",
		"CREATE TABLE UserPlays (UserPlayID INTEGER PRIMARY KEY, ArrangementID INTEGER, DateStamp DATETIME, Score NUMERIC, Streak INTEGER, Mastery NUMERIC, Overall NUMERIC"
		", FOREIGN KEY(ArrangementID) REFERENCES Arrangements(ArrangementID))",
		0,
		// Don't forget that there must be two 0 values at the end of the updates.
		0
	};

	int new_version = 1;
	for (int i = 0; updates[i]; ++i)
	{
		if (new_version > schemaVersion)
		{
			cmd.prepare(updates[i]);
			result = cmd.execute();
			bResult = (SQLITE_OK == result);
			if (!bResult)
			{
				DBG(TRANS("Error #") + String(result) + ": " + getError(result) + TRANS(" from ") + updates[i]);
				break;
			}
			DBG(updates[i]);
		}

		// Check to see if updates for this section are completed
		if (0 == updates[i + 1])
		{
			if (new_version > schemaVersion)
			{
				String sqlUpdate = "UPDATE Schema SET IntValue = " + String(new_version) + " WHERE Item = 'Schema'";
				cmd.prepare(sqlUpdate.toUTF8());
				result = cmd.execute();
				if (SQLITE_OK != result)
					DBG(TRANS("Failed to update schema version"));
				schemaVersion = new_version;
				DBG(TRANS("Updated local database to Schema Version ") + String(schemaVersion));
			}
			++new_version;
			++i;
		}
	}
}

int CDatabase::execSQLscalar(String sql)
{
	int version = 0;

	query qry(dbSqlite, sql.toUTF8());

	for (query::iterator i = qry.begin(); i != qry.end(); ++i)
	{
		for (int j = 0; j < qry.column_count(); ++j)
		{
			std::tie(version) = (*i).get_columns<int>(0);
		}
	}

	return version;
}

String CDatabase::getError(int errNum)
{
	String rv = "";

	switch (errNum)
	{
	case SQLITE_OK:
		rv = TRANS("Successful");
		break;
	case SQLITE_ERROR:
		rv = TRANS("SQL error or missing database");
		break;
	case SQLITE_INTERNAL:
		rv = TRANS("Internal logic error in SQLite");
		break;
	case SQLITE_PERM:
		rv = TRANS("Access permission denied");
		break;
	case SQLITE_ABORT:
		rv = TRANS("Callback routine requested an abort");
		break;
	case SQLITE_BUSY:
		rv = TRANS("The database file is locked");
		break;
	case SQLITE_LOCKED:
		rv = TRANS("A table in the database is locked");
		break;
	case SQLITE_NOMEM:
		rv = TRANS("A malloc() failed");
		break;
	case SQLITE_READONLY:
		rv = TRANS("Attempt to write a readonly database");
		break;
	case SQLITE_INTERRUPT:
		rv = TRANS("Operation terminated by sqlite3_interrupt()");
		break;
	case SQLITE_IOERR:
		rv = TRANS("Some kind of disk I/O error occurred");
		break;
	case SQLITE_CORRUPT:
		rv = TRANS("The database disk image is malformed");
		break;
	case SQLITE_NOTFOUND:
		rv = TRANS("Unknown opcode in sqlite3_file_control()");
		break;
	case SQLITE_FULL:
		rv = TRANS("Insertion failed because database is full");
		break;
	case SQLITE_CANTOPEN:
		rv = TRANS("Unable to open the database file");
		break;
	case SQLITE_PROTOCOL:
		rv = TRANS("Database lock protocol error");
		break;
	case SQLITE_EMPTY:
		rv = TRANS("Database is empty");
		break;
	case SQLITE_SCHEMA:
		rv = TRANS("The database schema changed");
		break;
	case SQLITE_TOOBIG:
		rv = TRANS("String or BLOB exceeds size limit");
		break;
	case SQLITE_CONSTRAINT:
		rv = TRANS("Abort due to constraint violation");
		break;
	case SQLITE_MISMATCH:
		rv = TRANS("Data type mismatch"); break;
	case SQLITE_MISUSE:
		rv = TRANS("Library used incorrectly"); break;
	case SQLITE_NOLFS:
		rv = TRANS("Uses OS features not supported on host"); break;
	case SQLITE_AUTH:
		rv = TRANS("Authorization denied"); break;
	case SQLITE_FORMAT:
		rv = TRANS("Auxiliary database format error"); break;
	case SQLITE_RANGE:
		rv = TRANS("2nd parameter to sqlite3_bind out of range"); break;
	case SQLITE_NOTADB:
		rv = TRANS("File opened that is not a database file"); break;
	case SQLITE_NOTICE:
		rv = TRANS("Notifications from sqlite3_log()"); break;
	case SQLITE_WARNING:
		rv = TRANS("Warnings from sqlite3_log()"); break;
	case SQLITE_ROW:
		rv = TRANS("sqlite3_step() has another row ready"); break;
	case SQLITE_DONE:
		rv = TRANS("sqlite3_step() has finished executing"); break;
	default:
		rv = TRANS("Unknown error from sqlite3"); break;
	}
	return rv;
}