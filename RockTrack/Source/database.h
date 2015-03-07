/*
==============================================================================

Database.h
Created: 07 March 2013 14:10
Author:  Neil Stoker

==============================================================================
*/

#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include "JuceHeader.h"
#include "../sqlite3/sqlite3pp.h"
using namespace sqlite3pp;

class CDatabase
{
public:
	CDatabase(File dbPath);
	~CDatabase();
	void initialise();

	// Helper functions
	int execSQLscalar(String sql);

	String getError(int errNum);

private:
	database dbSqlite;
};



#endif  // DATABASE_H_INCLUDED