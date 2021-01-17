#include "End.h"
#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>
using namespace std;
End::End()
{
}

End::End(int endyear)
{
	year = endyear;
}

void End::setRevenue_Spending_Netgain_loss()
{
	const int MAX_DATA = 100;
	RETCODE rc;
	HENV henv;
	HDBC hdbc;
	HSTMT hstmt;
	char szData[MAX_DATA];
	SQLLEN cbData;
	char yearstring[10];
	_gcvt_s(yearstring, 10, year, 4);
	string stSQL = "SELECT Revenue, Spending, Netgain_loss  ";
	stSQL += "FROM  End_of_year ";
	stSQL += "WHERE Year = ";
	stSQL += yearstring;
	//cout << stSQL << endl;
	SQLAllocEnv(&henv);
	SQLAllocConnect(henv, &hdbc);
	SQLCHAR szConnectOut[1024];
	SQLSMALLINT cchConnect;
	string stConnect = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=.\\economic.accdb;UID=Admin;PWD=;";
	//cout << stConnect << endl;
	rc = SQLDriverConnect(hdbc, NULL, (SQLCHAR*)stConnect.c_str(), stConnect.length(), szConnectOut, 1024, &cchConnect, SQL_DRIVER_NOPROMPT);
	if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
	{
		SQLTCHAR state[255], error[255];
		SQLINTEGER code;
		SQLSMALLINT cb;
		SQLError(henv, hdbc, NULL, state, &code, error, 255, &cb);
		cout << error << endl;
		exit(0);
	}
	SQLAllocStmt(hdbc, &hstmt);
	rc = SQLExecDirect(hstmt, (SQLCHAR*)stSQL.c_str(), SQL_NTS);
	if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
	{
		SQLTCHAR state[255], error[255];
		SQLINTEGER code;
		SQLSMALLINT cb;
		SQLError(henv, hdbc, hstmt, state, &code, error, 255, &cb);
		cout << error << endl;
		exit(0);
	}

	while (rc == SQL_SUCCESS) // this should only succeed one time
	{
		rc = SQLFetch(hstmt);
		if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Revenue = stod(szData);
		}
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Spending = stod(szData);
		}
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Netgain_loss = stod(szData);
		}
			
	}
	cout << Revenue << endl;
	cout << Spending << endl;
	cout << Netgain_loss << endl;
}



double End::getrevenue()
{
	return Revenue;
}

double End::getspending()
{
	return Spending;
}

double End::getnetgain_loss()
{
	return Netgain_loss;
}
