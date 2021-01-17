// Referenced http://www.cplusplus.com/reference/string/stod/ for converting string to double
#include "Start.h"
#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>
using namespace std;
Start::Start()
{
}

Start::Start(int startyear)
{
	year = startyear;

}
// this connects to the access database stored inside the project folder and accesses it to get the values for all the revenue variables
void Start::setRevenuevariables()
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
	string stSQL = "SELECT Individual_income_taxes, Payroll_taxes, Corporate_income_taxes, Sales_and_Excise_taxes, Property_taxes, Estate_and_gift_taxes, Severance_taxes,  ";
	stSQL += "Customs_Duties, Licenses, Other_taxes, Sales_of_government_resources, Federal_reserve_earnings, Earnings_losses, Other_non_tax_revenue ";
	stSQL += "FROM Revenue AS R, Start_of_year AS S ";
	stSQL += "WHERE S.Year = ";
	stSQL += yearstring;
	stSQL += " AND S.RevenueID = R.ID";
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
			Individual_income_taxes = stod(szData);
		}
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Payroll_taxes = stod(szData);
		}
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Corporate_income_taxes = stod(szData);
		}
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Sales_and_Excise_taxes = stod(szData);
		}
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Property_taxes = stod(szData);
		}
		if (SQLGetData(hstmt, 6, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Estate_and_gift_taxes = stod(szData);
		}
		if (SQLGetData(hstmt, 7, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Severance_taxes = stod(szData);
		}
		if (SQLGetData(hstmt, 8, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Customs_Duties = stod(szData);
		}
		if (SQLGetData(hstmt, 9, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Licenses = stod(szData);
		}
		if (SQLGetData(hstmt, 10, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Other_taxes = stod(szData);
		}
		if (SQLGetData(hstmt, 11, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Sales_of_government_resources = stod(szData);
		}
		if (SQLGetData(hstmt, 12, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Federal_reserve_earnings = stod(szData);
		}
		if (SQLGetData(hstmt, 13, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Earnings_losses = stod(szData);
		}
		if (SQLGetData(hstmt, 14, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Other_non_tax_revenue = stod(szData);
		}
	}
	/*cout << Individual_income_taxes << endl;
	cout << Payroll_taxes << endl;
	cout << Corporate_income_taxes << endl;
	cout << Sales_and_Excise_taxes << endl;
	cout << Property_taxes << endl;
	cout << Estate_and_gift_taxes << endl;
	cout << Severance_taxes << endl;
	cout << Customs_Duties << endl;
	cout << Licenses << endl;
	cout << Other_taxes << endl;
	cout << Sales_of_government_resources << endl;
	cout << Federal_reserve_earnings << endl;
	cout << Earnings_losses << endl;
	cout << Other_non_tax_revenue << endl;
	*/
}


// this connects to the access database stored inside the project folder and accesses it to get the values for all the spending variables
void Start::setSpendingvariables()
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
	string stSQL = "SELECT Establish_Justice, Common_Defense, Welfare, Liberty,  Government, Non_grant_assistance_other_countries, Discrepancy_between_state_and_local_receipts ";
	stSQL += "FROM Spending AS SP, Start_of_year AS S ";
	stSQL += "WHERE S.Year = ";
	stSQL += yearstring;
	stSQL += " AND S.SpendingID = SP.ID";
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
			Establish_Justice = stod(szData);
		}
		if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Common_Defense = stod(szData);
		}
		if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Welfare = stod(szData);
		}
		if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Liberty = stod(szData);
		}
		if (SQLGetData(hstmt, 5, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Government = stod(szData);
		}
		if (SQLGetData(hstmt, 6, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Non_grant_assistance_other_countries = stod(szData);
		}
		if (SQLGetData(hstmt, 7, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS)
		{
			Discrepancy_between_state_and_local_receipts = stod(szData);
		}

	}
	/*
	cout << Establish_Justice << endl;
	cout << Common_Defense << endl;
	cout << Welfare << endl;
	cout << Liberty << endl;
	cout << Government << endl;
	cout << Non_grant_assistance_other_countries << endl;
	cout << Discrepancy_between_state_and_local_receipts << endl;
	*/
}



void Start::setrevenue()
{
	revenue = Individual_income_taxes + Payroll_taxes + Corporate_income_taxes + Sales_and_Excise_taxes + Property_taxes + Estate_and_gift_taxes + Severance_taxes + Customs_Duties;
	revenue += Licenses + Other_taxes + Sales_of_government_resources + Federal_reserve_earnings + Earnings_losses + Other_non_tax_revenue;
}

void Start::setspending()
{
	spending = Establish_Justice + Common_Defense + Welfare + Liberty + Government + Non_grant_assistance_other_countries + Discrepancy_between_state_and_local_receipts;
}

void Start::setnetgain_loss()
{
	netgain_loss = revenue - spending;
}

void Start::updateIndividual_income_taxes(double change)
{
	//cout << change << endl;
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Individual_income_taxes = (1 + change) * Individual_income_taxes;
	}
	else
	{
		Individual_income_taxes = Individual_income_taxes + change;
	}
}

void Start::updatePayroll_taxes(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Payroll_taxes = Payroll_taxes * (1 + change);
	}
	else
	{
		Payroll_taxes = Payroll_taxes + change;
	}
}

void Start::updateCorporate_income_taxes(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Corporate_income_taxes = Corporate_income_taxes * (1 + change);
	}
	else
	{
		Corporate_income_taxes = Corporate_income_taxes + change;
	}
}

void Start::updateSales_and_Excise_taxes(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Sales_and_Excise_taxes = Sales_and_Excise_taxes * (1 + change);
	}
	else
	{
		Sales_and_Excise_taxes = Sales_and_Excise_taxes + change;
	}
}

void Start::updateProperty_taxes(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Property_taxes = Property_taxes * (1 + change);
	}
	else
	{
		Property_taxes = Property_taxes + change;
	}
}

void Start::updateEstate_and_gift_taxes(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Estate_and_gift_taxes = Estate_and_gift_taxes * (1 + change);
	}
	else
	{
		Estate_and_gift_taxes = Estate_and_gift_taxes + change;
	}
}

void Start::updateSeverance_taxes(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Severance_taxes = Severance_taxes * (1 + change);
	}
	else
	{
		Severance_taxes = Severance_taxes + change;
	}
}

void Start::updateCustoms_Duties(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Customs_Duties = Customs_Duties * (1 + change);
	}
	else
	{
		Customs_Duties = Customs_Duties + change;
	}
}

void Start::updateLicenses(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Licenses = Licenses * (1 + change);
	}
	else
	{
		Licenses = Licenses + change;
	}
}

void Start::updateOther_taxes(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Other_taxes = Other_taxes * (1 + change);
	}
	else
	{
		Other_taxes = Other_taxes + change;
	}
}

void Start::updateSales_of_government_resources(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Sales_of_government_resources = Sales_of_government_resources * (1 + change);
	}
	else
	{
		Sales_of_government_resources = Sales_of_government_resources + change;
	}
}

void Start::updateFederal_reserve_earnings(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Individual_income_taxes = Individual_income_taxes * (1 + change);
	}
	else
	{
		Individual_income_taxes = Individual_income_taxes + change;
	}
}

void Start::updateEarnings_losses(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Earnings_losses = Earnings_losses * (1 + change);
	}
	else
	{
		Earnings_losses = Earnings_losses + change;
	}
}

void Start::updateOther_non_tax_revenue(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Other_non_tax_revenue = Other_non_tax_revenue * (1 + change);
	}
	else
	{
		Other_non_tax_revenue = Other_non_tax_revenue + change;
	}
}

void Start::updateEstablish_Justice(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Establish_Justice = Establish_Justice * (1 + change);
	}
	else
	{
		Establish_Justice = Establish_Justice + change;
	}
}

void Start::updateCommon_Defense(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Common_Defense = Common_Defense * (1 + change);
	}
	else
	{
		Common_Defense = Common_Defense + change;
	}
}

void Start::updateWelfare(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Welfare = Welfare * (1 + change);
	}
	else
	{
		Welfare = Welfare + change;
	}
}

void Start::updateLiberty(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Liberty = Liberty * (1 + change);
	}
	else
	{
		Liberty = Liberty + change;
	}
}

void Start::updateGovernment(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Government = Government * (1 + change);
	}
	else
	{
		Government = Government + change;
	}
}

void Start::updateNon_grant_assistance_other_countries(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Non_grant_assistance_other_countries = Non_grant_assistance_other_countries * (1 + change);
	}
	else
	{
		Non_grant_assistance_other_countries = Non_grant_assistance_other_countries + change;
	}
}

void Start::updateDiscrepancy_between_state_and_local_receipts(double change)
{
	if (change > 0 && change < 1 || change < 0 && change > -1)
	{
		Discrepancy_between_state_and_local_receipts = Discrepancy_between_state_and_local_receipts * (1 + change);
	}
	else
	{
		Discrepancy_between_state_and_local_receipts = Discrepancy_between_state_and_local_receipts + change;
	}
}

void Start::updaterevenue()
{
	revenue = Individual_income_taxes + Payroll_taxes + Corporate_income_taxes + Sales_and_Excise_taxes + Property_taxes + Estate_and_gift_taxes + Severance_taxes + Customs_Duties;
	revenue += Licenses + Other_taxes + Sales_of_government_resources + Federal_reserve_earnings + Earnings_losses + Other_non_tax_revenue;
}

void Start::updatespending()
{
	spending = Establish_Justice + Common_Defense + Welfare + Liberty + Government + Non_grant_assistance_other_countries + Discrepancy_between_state_and_local_receipts;
}

void Start::updatenetgain_loss()
{
	netgain_loss = revenue - spending;
}

double Start::getIndividual_income_taxes()
{
	return Individual_income_taxes;
}

double Start::getPayroll_taxes()
{
	return Payroll_taxes;
}

double Start::getCorporate_income_taxes()
{
	return Corporate_income_taxes;
}

double Start::getSales_and_Excise_taxes()
{
	return Sales_and_Excise_taxes;
}

double Start::getProperty_taxes()
{
	return Property_taxes;
}

double Start::getEstate_and_gift_taxes()
{
	return Estate_and_gift_taxes;
}

double Start::getSeverance_taxes()
{
	return Severance_taxes;
}

double Start::getCustoms_Duties()
{
	return Customs_Duties;
}

double Start::getLicenses()
{
	return Licenses;
}

double Start::getOther_taxes()
{
	return Other_taxes;
}

double Start::getSales_of_government_resources()
{
	return Sales_of_government_resources;
}

double Start::getFederal_reserve_earnings()
{
	return Federal_reserve_earnings;
}

double Start::getEarnings_losses()
{
	return Earnings_losses;
}

double Start::getOther_non_tax_revenue()
{
	return Other_non_tax_revenue;
}

double Start::getEstablish_Justice()
{
	return Establish_Justice;
}

double Start::getCommon_Defense()
{
	return Common_Defense;
}

double Start::getWelfare()
{
	return Welfare;
}

double Start::getLiberty()
{
	return Liberty;
}

double Start::getGovernment()
{
	return Government;
}

double Start::getNon_grant_assistance_other_countries()
{
	return Non_grant_assistance_other_countries;
}

double Start::getDiscrepancy_between_state_and_local_receipts()
{
	return Discrepancy_between_state_and_local_receipts;
}

int Start::getyear()
{
	return year;
}

double Start::getrevenue()
{
	return revenue;
}

double Start::getspending()
{
	return spending;
}

double Start::getnetgain_loss()
{
	return netgain_loss;
}




