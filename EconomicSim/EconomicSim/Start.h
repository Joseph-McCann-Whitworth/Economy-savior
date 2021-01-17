#ifndef START_H
#define START_H
#include <iostream>
using namespace std;
// the start class gets the data for the starting year you choose

class Start {

private:
	//variable for year of simulation
	int year = 0;
	// revenue variables
	double Individual_income_taxes = 0;
	double Payroll_taxes = 0;
	double Corporate_income_taxes = 0;
	double Sales_and_Excise_taxes = 0;
	double Property_taxes = 0;
	double Estate_and_gift_taxes = 0;
	double Severance_taxes = 0;
	double Customs_Duties = 0;
	double Licenses = 0;
	double Other_taxes = 0;
	double Sales_of_government_resources = 0;
	double Federal_reserve_earnings = 0;
	double Earnings_losses = 0;
	double Other_non_tax_revenue = 0;
	// spending variables
	double Establish_Justice = 0;
	double Common_Defense = 0;
	double Welfare = 0;
	double Liberty = 0;
	double Government = 0;
	double Non_grant_assistance_other_countries = 0;
	double Discrepancy_between_state_and_local_receipts = 0;
	// total revenue,spending and netgain_loss variables
	double revenue = 0;
	double spending = 0;
	double netgain_loss = 0;


public: // holds the empty constructor, get and set year method to return the year for the queries and to set the year that the player chooses
	// each method of revenue or expense will have a set and get method that will set the amount for each through the database and an update method to update it as decisions happen 
	// affecting the number
	// there will also be a get, and set starting revenue, spending, and netgain_loss to compare with the 

	// Empty Constructor and Constructor that sets the year
	Start();
	Start(int startyear);

	//set functions for variables
	// sets the variables through a database
	// revenue, spending, and netgain_loss are calculated
	void setRevenuevariables();
	void setSpendingvariables();
	void setrevenue();
	void setspending();
	void setnetgain_loss();

	//update functions
	// this will update depending on the change
	// meaning if it is a percentage it will update it with number * (1 + percent)
	// or if it is a big number meaning percentage bigger than 1 (number + increase/decrease)
	// this is assuming no increase or decrease will be bigger or equal to 1 or -1 respectively
	void updateIndividual_income_taxes(double change);
	void updatePayroll_taxes(double change);
	void updateCorporate_income_taxes(double change);
	void updateSales_and_Excise_taxes(double change);
	void updateProperty_taxes(double change);
	void updateEstate_and_gift_taxes(double change);
	void updateSeverance_taxes(double change);
	void updateCustoms_Duties(double change);
	void updateLicenses(double change);
	void updateOther_taxes(double change);
	void updateSales_of_government_resources(double change);
	void updateFederal_reserve_earnings(double change);
	void updateEarnings_losses(double change);
	void updateOther_non_tax_revenue(double change);
	void updateEstablish_Justice(double change);
	void updateCommon_Defense(double change);
	void updateWelfare(double change);
	void updateLiberty(double change);
	void updateGovernment(double change);
	void updateNon_grant_assistance_other_countries(double change);
	void updateDiscrepancy_between_state_and_local_receipts(double change);
	// these updates don't take in a variable since they will just add up the corresponding values to get the number
	void updaterevenue();
	void updatespending();
	void updatenetgain_loss();

	//get functions
	double getIndividual_income_taxes();
	double getPayroll_taxes();
	double getCorporate_income_taxes();
	double getSales_and_Excise_taxes();
	double getProperty_taxes();
	double getEstate_and_gift_taxes();
	double getSeverance_taxes();
	double getCustoms_Duties();
	double getLicenses();
	double getOther_taxes();
	double getSales_of_government_resources();
	double getFederal_reserve_earnings();
	double getEarnings_losses();
	double getOther_non_tax_revenue();
	double getEstablish_Justice();
	double getCommon_Defense();
	double getWelfare();
	double getLiberty();
	double getGovernment();
	double getNon_grant_assistance_other_countries();
	double getDiscrepancy_between_state_and_local_receipts();
	int getyear();
	double getrevenue();
	double getspending();
	double getnetgain_loss();
};





#endif
