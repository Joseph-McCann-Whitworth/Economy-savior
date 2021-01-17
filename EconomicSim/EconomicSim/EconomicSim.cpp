// Made by: Joseph McCann
// Economy savior 
// CS374-1 Final project
#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include "Start.h"
#include "End.h"
#include <string>
void variablesetter(Start& simstart, End& simend); // this sets all the revenue, spending, and netgain_loss variables
void outputstartingvalues(Start& simstart); // outputs all the revenue spending, and total values to the screen at the start of the simulation
void outputfinalvalues(Start& simstart); // outputs all the revenue spending, and total values to the screen at the end of the simulation
void eventpicker(Start& simstart); // picks the event that will happen
void compare(Start& simstart, End& simend); // compares to how you did compared to the actual government
// all events that are possible and can happen
void inflationevent(Start& simstart);
void worldwarevent(Start& simstart);
void corporatepaybackevent(Start& simstart);
void greedgovernmentevent(Start& simstart);
void helpcountryevent(Start& simstart);
void oilproducingmachineevent(Start& simstart);
void welfareoverload(Start& simstart);
void taxevent(Start& simstart);
void governmentsaleevent(Start& simstart);
void errorwithnumbersevent(Start& simstart);
void estateevent(Start& simstart);
void propertyevent(Start& simstart);
void protectthecountyevent(Start& simstart);
void courtevent(Start& simstart);
void magicmoneyevent(Start& simstart);
void bigbankevent(Start& simstart);
void fattyfoodevent(Start& simstart);
void newtaxevent(Start& simstart);
void lotsoflicensesevent(Start& simstart);
void protectlibertyevent(Start& simstart);
//
string choice; // for the decisions the player makes
using namespace std;
int main()
{
	string year = "";
	double Year = 0;
	while (year != "2016" && year != "2015" && year != "2014")
	{
		cout << "What year would you like the economic simulation to take place? Options are 2016, 2015, and 2014." << endl;
		cin >> year;
		if (year == "2016" || year == "2015" || year == "2014")
		{
			Year = stod(year);
		}
		else
		{
			cout << "Not valid year or not put into database. Please try again" << endl;
			
		}
	}

	Start simstart(Year);
	End simend(Year);
	variablesetter(simstart, simend);
	outputstartingvalues(simstart);


	srand(time(NULL));
	for (int i = 0; i < 365; i++)
	{
		int eventchance;
		cout << "Day: " << i + 1 << endl;
		eventchance = rand() % 10 + 1;
		//cout << eventchance << endl;
		if (eventchance == 1)
		{
			eventpicker(simstart);
		}
		else
		{
			cout << "No major event occured today." << endl;
		}
	}
	outputfinalvalues(simstart);
	compare(simstart, simend);

	return 0;
}

void variablesetter(Start& simstart, End& simend)
{
	simstart.setRevenuevariables();
	simstart.setSpendingvariables();
	simstart.setrevenue();
	simstart.setspending();
	simstart.setnetgain_loss();
	simend.setRevenue_Spending_Netgain_loss();
}
// takes in a class and outputs text to the screen showing the revenue, spending, and total values for each variable in the class except for year
void outputstartingvalues(Start& simstart)
{
	cout << "Starting revenue values:" << endl;
	cout << "Starting Individual_income_taxes: " << simstart.getIndividual_income_taxes() << endl;
	cout << "Starting Payroll_taxes: " << simstart.getPayroll_taxes() << endl;
	cout << "Starting Corporate_income_taxes: " << simstart.getCorporate_income_taxes() << endl;
	cout << "Starting Sales_and_Excise_taxes: " << simstart.getSales_and_Excise_taxes() << endl;
	cout << "Starting Property_taxes: " << simstart.getProperty_taxes() << endl;
	cout << "Starting Estate_and_gift_taxes: " << simstart.getEstate_and_gift_taxes() << endl;
	cout << "Starting Severance_taxes: " << simstart.getSeverance_taxes() << endl;
	cout << "Starting Customs_Duties: " << simstart.getCustoms_Duties() << endl;
	cout << "Starting Licenses: " << simstart.getLicenses() << endl;
	cout << "Starting Other_taxes: " << simstart.getOther_taxes() << endl;
	cout << "Starting Sales_of_government_resources: " << simstart.getSales_of_government_resources() << endl;
	cout << "Starting Federal_reserve_earnings: " << simstart.getFederal_reserve_earnings() << endl;
	cout << "Starting Earnings_losses: " << simstart.getEarnings_losses() << endl;
	cout << "Starting Other_non_tax_revenue: " << simstart.getOther_non_tax_revenue() << endl;
	cout << "Starting spending values:" << endl;
	cout << "Starting Establish_Justice: " << simstart.getEstablish_Justice() << endl;
	cout << "Starting Common_Defense: " << simstart.getCommon_Defense() << endl;
	cout << "Starting Welfare: " << simstart.getWelfare() << endl;
	cout << "Starting Liberty: " << simstart.getLiberty() << endl;
	cout << "Starting Government: " << simstart.getGovernment() << endl;
	cout << "Starting Non_grant_assistance_other_countries: " << simstart.getNon_grant_assistance_other_countries() << endl;
	cout << "Starting Discrepancy_between_state_and_local_receiptss: " << simstart.getDiscrepancy_between_state_and_local_receipts() << endl;
	cout << "Starting total values:" << endl;
	cout << "Starting Revenue: " << simstart.getrevenue() << endl;
	cout << "Starting Spending: " << simstart.getspending() << endl;
	cout << "Starting netgain_loss: " << simstart.getnetgain_loss() << endl;
}
// takes in a class and outputs text to the screen showing the revenue, spending, and total values for each variable in the class except for year
void outputfinalvalues(Start& simstart)
{
	cout << "Final revenue values:" << endl;
	cout << "Final Individual_income_taxes: " << simstart.getIndividual_income_taxes() << endl;
	cout << "Final Payroll_taxes: " << simstart.getPayroll_taxes() << endl;
	cout << "Final Corporate_income_taxes: " << simstart.getCorporate_income_taxes() << endl;
	cout << "Final Sales_and_Excise_taxes: " << simstart.getSales_and_Excise_taxes() << endl;
	cout << "Final Property_taxes: " << simstart.getProperty_taxes() << endl;
	cout << "Final Estate_and_gift_taxes: " << simstart.getEstate_and_gift_taxes() << endl;
	cout << "Final Severance_taxes: " << simstart.getSeverance_taxes() << endl;
	cout << "Final Customs_Duties: " << simstart.getCustoms_Duties() << endl;
	cout << "Final Licenses: " << simstart.getLicenses() << endl;
	cout << "Final Other_taxes: " << simstart.getOther_taxes() << endl;
	cout << "Final Sales_of_government_resources: " << simstart.getSales_of_government_resources() << endl;
	cout << "Final Federal_reserve_earnings: " << simstart.getFederal_reserve_earnings() << endl;
	cout << "Final Earnings_losses: " << simstart.getEarnings_losses() << endl;
	cout << "Final Other_non_tax_revenue: " << simstart.getOther_non_tax_revenue() << endl;
	cout << "Final spending values:" << endl;
	cout << "Final Establish_Justice: " << simstart.getEstablish_Justice() << endl;
	cout << "Final Common_Defense: " << simstart.getCommon_Defense() << endl;
	cout << "Final Welfare: " << simstart.getWelfare() << endl;
	cout << "Final Liberty: " << simstart.getLiberty() << endl;
	cout << "Final Government: " << simstart.getGovernment() << endl;
	cout << "Final Non_grant_assistance_other_countries: " << simstart.getNon_grant_assistance_other_countries() << endl;
	cout << "Final Discrepancy_between_state_and_local_receiptss: " << simstart.getDiscrepancy_between_state_and_local_receipts() << endl;
	cout << "Final total values:" << endl;
	cout << "Final Revenue: " << simstart.getrevenue() << endl;
	cout << "Final Spending: " << simstart.getspending() << endl;
	cout << "Final netgain_loss: " << simstart.getnetgain_loss() << endl;
}

// takes in the class used for the simulation and returns nothing
// this function randomly chooses out of the events possible what event the player will get
void eventpicker(Start& simstart)
{
	int event;
	event = rand() % 20 + 1;
	//cout << "Event: " <<  event << endl;
	switch (event)
	{
	case 1: inflationevent(simstart);
		break;
	case 2: worldwarevent(simstart);
		break;
	case 3: corporatepaybackevent(simstart);
		break;
	case 4: greedgovernmentevent(simstart);
		break;
	case 5: helpcountryevent(simstart);
		break;
	case 6: oilproducingmachineevent(simstart);
		break;
	case 7: welfareoverload(simstart);
		break;
	case 8: taxevent(simstart);
		break;
	case 9: governmentsaleevent(simstart);
		break;
	case 10: errorwithnumbersevent(simstart);
		break;
	case 11: estateevent(simstart);
		break;
	case 12: propertyevent(simstart);
		break;
	case 13: protectthecountyevent(simstart);
		break;
	case 14: courtevent(simstart);
		break;
	case 15: magicmoneyevent(simstart);
		break;
	case 16: bigbankevent(simstart);
		break;
	case 17: fattyfoodevent(simstart);
		break;
	case 18: newtaxevent(simstart);
		break;
	case 19: lotsoflicensesevent(simstart);
		break;
	case 20: protectlibertyevent(simstart);
		break;
	default: cout << "uh oh" << endl;
		break;
	}
}
// takes in references to both start and end classes
// compares the revenue, spending, and netgain_loss of how you did compared to the government
void compare(Start& simstart, End& simend)
{
	if (simstart.getrevenue() > simend.getrevenue())
	{
		cout << "You made more money than the government by: " << simstart.getrevenue() - simend.getrevenue() << endl;
	}
	else
	{
		cout << "You made less money than the government by: " << simend.getrevenue() - simstart.getrevenue() << endl;
	}
	if (simstart.getspending() > simend.getspending())
	{
		cout << "You spent more money than the government by: " << simstart.getspending() - simend.getspending() << endl;
	}
	else
	{
		cout << "You spent less money than the government by: " << simend.getspending() - simstart.getspending() << endl;
	}
	if (simstart.getnetgain_loss() > simend.getnetgain_loss())
	{
		cout << "You had more profit than the government by: " << (simstart.getnetgain_loss()) - (simend.getnetgain_loss()) << endl;
	}
	else
	{
		cout << "You had more defecit than the government by: " << (simend.getnetgain_loss() - simstart.getnetgain_loss()) << endl;
	}
}

void inflationevent(Start& simstart)
{
	double change = 0;
	cout << "Uh oh inflation is happening prepare to carry around wheelbarrels full of money." << endl;
	cout << "All revenue and spending goes up by 5 percent" << endl;
	system("pause");
	change = 0.05;
	/*cout << simstart.getIndividual_income_taxes() << endl;
	cout << simstart.getPayroll_taxes() << endl;
	cout << simstart.getCorporate_income_taxes() << endl;
	cout << simstart.getSales_and_Excise_taxes() << endl;
	cout << simstart.getProperty_taxes() << endl;
	cout << simstart.getEstate_and_gift_taxes() << endl;
	cout << simstart.getSeverance_taxes() << endl;
	cout << simstart.getCustoms_Duties() << endl;
	cout << simstart.getLicenses() << endl;
	cout << simstart.getOther_taxes() << endl;
	cout << simstart.getSales_of_government_resources() << endl;
	cout << simstart.getFederal_reserve_earnings() << endl;
	cout << simstart.getEarnings_losses() << endl;
	cout << simstart.getOther_non_tax_revenue() << endl;
	cout << simstart.getEstablish_Justice() << endl;
	cout << simstart.getCommon_Defense() << endl;
	cout << simstart.getWelfare() << endl;
	cout << simstart.getLiberty() << endl;
	cout << simstart.getGovernment() << endl;
	cout << simstart.getNon_grant_assistance_other_countries() << endl;
	cout << simstart.getDiscrepancy_between_state_and_local_receipts() << endl;
	*/
	simstart.updateIndividual_income_taxes(change);
	simstart.updatePayroll_taxes(change);
	simstart.updateCorporate_income_taxes(change);
	simstart.updateSales_and_Excise_taxes(change);
	simstart.updateProperty_taxes(change);
	simstart.updateEstate_and_gift_taxes(change);
	simstart.updateSeverance_taxes(change);
	simstart.updateCustoms_Duties(change);
	simstart.updateLicenses(change);
	simstart.updateOther_taxes(change);
	simstart.updateSales_of_government_resources(change);
	simstart.updateFederal_reserve_earnings(change);
	simstart.updateEarnings_losses(change);
	simstart.updateOther_non_tax_revenue(change);
	simstart.updateEstablish_Justice(change);
	simstart.updateCommon_Defense(change);
	simstart.updateWelfare(change);
	simstart.updateLiberty(change);
	simstart.updateGovernment(change);
	simstart.updateNon_grant_assistance_other_countries(change);
	simstart.updateDiscrepancy_between_state_and_local_receipts(change);
	simstart.updaterevenue();
	simstart.updatespending();
	simstart.updatenetgain_loss();
	/*
	cout << simstart.getIndividual_income_taxes() << endl;
	cout << simstart.getPayroll_taxes() << endl;
	cout << simstart.getCorporate_income_taxes() << endl;
	cout << simstart.getSales_and_Excise_taxes() << endl;
	cout << simstart.getProperty_taxes() << endl;
	cout << simstart.getEstate_and_gift_taxes() << endl;
	cout << simstart.getSeverance_taxes() << endl;
	cout << simstart.getCustoms_Duties() << endl;
	cout << simstart.getLicenses() << endl;
	cout << simstart.getOther_taxes() << endl;
	cout << simstart.getSales_of_government_resources() << endl;
	cout << simstart.getFederal_reserve_earnings() << endl;
	cout << simstart.getEarnings_losses() << endl;
	cout << simstart.getOther_non_tax_revenue() << endl;
	cout << simstart.getEstablish_Justice() << endl;
	cout << simstart.getCommon_Defense() << endl;
	cout << simstart.getWelfare() << endl;
	cout << simstart.getLiberty() << endl;
	cout << simstart.getGovernment() << endl;
	cout << simstart.getNon_grant_assistance_other_countries() << endl;
	cout << simstart.getDiscrepancy_between_state_and_local_receipts() << endl;
	*/
}

void worldwarevent(Start& simstart)
{
	double revenuechange = -0.05;
	double spendingchange = 0.05;
	cout << "Another silly war that does no good for the people." << endl;
	cout << "Revenue down 5% and expenses up 5%." << endl;
	system("pause");
	simstart.updateIndividual_income_taxes(revenuechange);
	simstart.updatePayroll_taxes(revenuechange);
	simstart.updateCorporate_income_taxes(revenuechange);
	simstart.updateSales_and_Excise_taxes(revenuechange);
	simstart.updateProperty_taxes(revenuechange);
	simstart.updateEstate_and_gift_taxes(revenuechange);
	simstart.updateSeverance_taxes(revenuechange);
	simstart.updateCustoms_Duties(revenuechange);
	simstart.updateLicenses(revenuechange);
	simstart.updateOther_taxes(revenuechange);
	simstart.updateSales_of_government_resources(revenuechange);
	simstart.updateFederal_reserve_earnings(revenuechange);
	simstart.updateEarnings_losses(revenuechange);
	simstart.updateOther_non_tax_revenue(revenuechange);
	simstart.updateEstablish_Justice(spendingchange);
	simstart.updateCommon_Defense(spendingchange);
	simstart.updateWelfare(spendingchange);
	simstart.updateLiberty(spendingchange);
	simstart.updateGovernment(spendingchange);
	simstart.updateNon_grant_assistance_other_countries(spendingchange);
	simstart.updateDiscrepancy_between_state_and_local_receipts(spendingchange);
	simstart.updaterevenue();
	simstart.updatespending();
	simstart.updatenetgain_loss();
	/*
	cout << simstart.getIndividual_income_taxes() << endl;
	cout << simstart.getPayroll_taxes() << endl;
	cout << simstart.getCorporate_income_taxes() << endl;
	cout << simstart.getSales_and_Excise_taxes() << endl;
	cout << simstart.getProperty_taxes() << endl;
	cout << simstart.getEstate_and_gift_taxes() << endl;
	cout << simstart.getSeverance_taxes() << endl;
	cout << simstart.getCustoms_Duties() << endl;
	cout << simstart.getLicenses() << endl;
	cout << simstart.getOther_taxes() << endl;
	cout << simstart.getSales_of_government_resources() << endl;
	cout << simstart.getFederal_reserve_earnings() << endl;
	cout << simstart.getEarnings_losses() << endl;
	cout << simstart.getOther_non_tax_revenue() << endl;
	cout << simstart.getEstablish_Justice() << endl;
	cout << simstart.getCommon_Defense() << endl;
	cout << simstart.getWelfare() << endl;
	cout << simstart.getLiberty() << endl;
	cout << simstart.getGovernment() << endl;
	cout << simstart.getNon_grant_assistance_other_countries() << endl;
	cout << simstart.getDiscrepancy_between_state_and_local_receipts() << endl;
	*/

}

void corporatepaybackevent(Start& simstart)
{
	choice = "10000"; // a placeholder value so it can go through the loop
	while (choice != "1" && choice != "0")
	{
		double change = 0;
		cout << "Do you wish to stop the corporations from tax evading?" << endl;
		cout << "Type 1 for yes and 0 for no." << endl;
		cin >> choice;

		if (choice == "1")
		{
			cout << "You did it and improved the economy." << endl;
			cout << "Corporate incomes taxes revenue up by 10%." << endl;
			change = 0.10;
			simstart.updateCorporate_income_taxes(change);
			simstart.updaterevenue();
			simstart.updatenetgain_loss();
		}
		else if (choice == "0")
		{
			cout << "Them companies laugh with all the money they have." << endl;
			cout << "Corporate income taxes revenue down by 10%." << endl;
			change = -0.10;
			simstart.updateCorporate_income_taxes(change);
			simstart.updaterevenue();
			simstart.updatenetgain_loss();
		}
		else
		{
			cout << "You typed it in wrong please try again." << endl;
		
		}
	}

}

void greedgovernmentevent(Start& simstart)
{
	double change = 0.10;
	cout << "The government people get more money for who knows what." << endl;
	cout << "Government spending increased by 10%." << endl;
	simstart.updateGovernment(change);
	simstart.updatespending();
	simstart.updatenetgain_loss();
	system("pause");
}

void helpcountryevent(Start& simstart)
{
	choice = "10000"; // a placeholder value so it can go through the loop
	while (choice != "1" && choice != "0")
	{
		double change = 0;
		cout << "A country is struggling with a famine and needs your support." << endl;
		cout << "Do you choose to help them? Type 1 for yes and 0 for no." << endl;
		cin >> choice;

		if (choice == "1")
		{
			cout << "You are a good person and helped them, but it hurt our economy badly." << endl;
			cout << "Non_grant_assistance_other_countries spending up by 1000000000." << endl;
			change = 1000000000;
			simstart.updateNon_grant_assistance_other_countries(change);
			simstart.updatespending();
			simstart.updatenetgain_loss();
		}
		else if (choice == "0")
		{
			cout << "Your economy stays the same, but the other country don't like you." << endl;
			cout << "Nothing economically changed." << endl;
		}
		else
		{
			cout << "You typed it in wrong please try again." << endl;
			
		}
	}
}

void oilproducingmachineevent(Start& simstart)
{
	double change = 0.15;
	cout << "Oil production is at an all time high!" << endl;
	cout << "Severance taxes revenue increased by 15%." << endl;
	simstart.updateSeverance_taxes(change);
	simstart.updaterevenue();
	simstart.updatenetgain_loss();
	system("pause");
}

void welfareoverload(Start& simstart)
{
	double change = 0.10;
	cout << "Lots of new people on welfare due to influx in population, causing more people to be homeless due to lack of jobs for them." << endl;
	cout << "Welfare spending increased by 10%." << endl;
	simstart.updateWelfare(change);
	simstart.updatespending();
	simstart.updatenetgain_loss();
	system("pause");
}

void taxevent(Start& simstart)
{
	choice = "10000"; // a placeholder value so it can go through the loop
	while (choice != "0" && choice != "1")
	{
		string change = "1000"; // placeholder so it can go through the other loop
		cout << "You have a decision to either raise your taxes or decrease." << endl;
		cout << "Will you increase or decrease? Type 1 for increase and 0 for decrease." << endl;
		cin >> choice;

		if (choice == "1")
		{
			while (stod(change) < 0 || stod(change) > 10)
			{
				cout << "The people won't like it but it will make the numbers look better." << endl;
				cout << "How much do you want to increase taxes by? Type 0 for 0% (lame) up to 10 for 10%." << endl;
				cin >> change;
				if (stod(change) >= 0 && stod(change) <= 10)
				{
					double Change; // to take in the change into the class functions
					/*
					cout << simstart.getIndividual_income_taxes() << endl;
					cout << simstart.getPayroll_taxes() << endl;
					cout << simstart.getCorporate_income_taxes() << endl;
					cout << simstart.getSales_and_Excise_taxes() << endl;
					cout << simstart.getProperty_taxes() << endl;
					cout << simstart.getEstate_and_gift_taxes() << endl;
					cout << simstart.getSeverance_taxes() << endl;
					cout << simstart.getCustoms_Duties() << endl;
					cout << simstart.getLicenses() << endl;
					cout << simstart.getOther_taxes() << endl;
					*/
					Change = stod(change) * 0.01;
					cout << "All revenue taxes increased by: " << change << "." << endl;
					simstart.updateIndividual_income_taxes(Change);
					simstart.updatePayroll_taxes(Change);
					simstart.updateCorporate_income_taxes(Change);
					simstart.updateSales_and_Excise_taxes(Change);
					simstart.updateProperty_taxes(Change);
					simstart.updateEstate_and_gift_taxes(Change);
					simstart.updateSeverance_taxes(Change);
					simstart.updateCustoms_Duties(Change);
					simstart.updateLicenses(Change);
					simstart.updateOther_taxes(Change);
					simstart.updaterevenue();
					simstart.updatenetgain_loss();
					change = "0";
					/*
					cout << simstart.getIndividual_income_taxes() << endl;
					cout << simstart.getPayroll_taxes() << endl;
					cout << simstart.getCorporate_income_taxes() << endl;
					cout << simstart.getSales_and_Excise_taxes() << endl;
					cout << simstart.getProperty_taxes() << endl;
					cout << simstart.getEstate_and_gift_taxes() << endl;
					cout << simstart.getSeverance_taxes() << endl;
					cout << simstart.getCustoms_Duties() << endl;
					cout << simstart.getLicenses() << endl;
					cout << simstart.getOther_taxes() << endl;
					*/
				}
				else
				{
					cout << "Not valid change. Please try again." << endl;
					cin.clear();
				}

			}

		}
		else if (choice == "0")
		{
			while (stod(change) < 0 || stod(change) > 10)
			{
				cout << "The people will love you but it will make the numbers look worse." << endl;
				cout << "How much do you want to decrease taxes by? Type 0 for 0% (lame) up to 10 for 10%." << endl;
				cin >> change;
				if (stod(change) >= 0 && stod(change) <= 10)
				{
					double Change = 0;
					Change = stod(change) * -0.01; // to make the change negative to decrease taxes
					cout << "All revenue taxes decreased by: " << change << "." << endl;
					
					/*
					cout << simstart.getIndividual_income_taxes() << endl;
					cout << simstart.getPayroll_taxes() << endl;
					cout << simstart.getCorporate_income_taxes() << endl;
					cout << simstart.getSales_and_Excise_taxes() << endl;
					cout << simstart.getProperty_taxes() << endl;
					cout << simstart.getEstate_and_gift_taxes() << endl;
					cout << simstart.getSeverance_taxes() << endl;
					cout << simstart.getCustoms_Duties() << endl;
					cout << simstart.getLicenses() << endl;
					cout << simstart.getOther_taxes() << endl;
					*/
					simstart.updateIndividual_income_taxes(Change);
					simstart.updatePayroll_taxes(Change);
					simstart.updateCorporate_income_taxes(Change);
					simstart.updateSales_and_Excise_taxes(Change);
					simstart.updateProperty_taxes(Change);
					simstart.updateEstate_and_gift_taxes(Change);
					simstart.updateSeverance_taxes(Change);
					simstart.updateCustoms_Duties(Change);
					simstart.updateLicenses(Change);
					simstart.updateOther_taxes(Change);
					simstart.updaterevenue();
					simstart.updatenetgain_loss();
					/*
					cout << simstart.getIndividual_income_taxes() << endl;
					cout << simstart.getPayroll_taxes() << endl;
					cout << simstart.getCorporate_income_taxes() << endl;
					cout << simstart.getSales_and_Excise_taxes() << endl;
					cout << simstart.getProperty_taxes() << endl;
					cout << simstart.getEstate_and_gift_taxes() << endl;
					cout << simstart.getSeverance_taxes() << endl;
					cout << simstart.getCustoms_Duties() << endl;
					cout << simstart.getLicenses() << endl;
					cout << simstart.getOther_taxes() << endl;
					*/
					change = "0"; // this is so it doesn't get stuck in a endless loop
				}
				else
				{
					cout << "Not valid change. Please try again." << endl;
					
				}

			}
		}
		else
		{
			cout << "You typed it in wrong please try again." << endl;
			
		}
	}
}

void governmentsaleevent(Start& simstart)
{
	double change = 1000000000;
	cout << "The government is selling part of its resources it don't need." << endl;
	cout << "sales of government resources increased by 1000000000" << endl;
	simstart.updateSales_of_government_resources(change);
	simstart.updaterevenue();
	simstart.updatenetgain_loss();
	system("pause");
}

void errorwithnumbersevent(Start& simstart)
{
	double change = 0.10;
	cout << "The numbers the state government had were different than what the local governments had by 10%" << endl;
	cout << "Discrepancy between state and local receipts increased by 10%" << endl;
	simstart.updateDiscrepancy_between_state_and_local_receipts(change);
	simstart.updatespending();
	simstart.updatenetgain_loss();
	system("pause");
}

void estateevent(Start& simstart)
{
	double change = 0.20;
	cout << "More people have been dying than normal and the money is insane." << endl;
	cout << "Estate and gift taxes increased by 20%." << endl;
	simstart.updateEstate_and_gift_taxes(change);
	simstart.updaterevenue();
	simstart.updatenetgain_loss();
	system("pause");
}

void propertyevent(Start& simstart)
{
	choice = "10000";
	double change = 0.15;
	while (choice != "0" && choice != "1")
	{
		cout << "There is more demand for property as the population gets even bigger." << endl;
		cout << "Do you increase the property tax so the demand goes down since people can't afford it or do you increase government spending?" << endl;
		cout << "Type 0 for increase property tax and 1 for increase government spending." << endl;
		cin >> choice;
		if (choice == "0")
		{
			cout << "Property tax increased by 15%." << endl;
			simstart.updateProperty_taxes(change);
			simstart.updaterevenue();
			simstart.updatenetgain_loss();
		}
		else if (choice == "1")
		{
			cout << "Government spending increased by 15%." << endl;
			simstart.updateGovernment(change);
			simstart.updatespending();
			simstart.updatenetgain_loss();
		}
		else
		{
			cout << "Invalid choice please try again." << endl;
		
		}
	}

}

void protectthecountyevent(Start& simstart)
{
	double change = 0.05;
	cout << "Due to a rise in terrorists the spending on defense will increase by 5%." << endl;
	simstart.updateCommon_Defense(change);
	simstart.updatespending();
	simstart.updatenetgain_loss();
	system("pause");
}

void courtevent(Start& simstart)
{
	choice = "10000";
	while (choice != "0" && choice != "1")
	{
		cout << "The lack of lawyers for people is bad, so you're thinking about increasing spending to get more." << endl;
		cout << "Do you spend more on justice? 0 for yes 1 for no." << endl;
		cin >> choice;
		if (choice == "0")
		{
			double change = 0.10;
			cout << "Justice spending increased by 10%." << endl;
			simstart.updateEstablish_Justice(change);
			simstart.updatespending();
			simstart.updatenetgain_loss();
		}
		else if (choice == "1")
		{
			cout << "Your spending hasn't changed." << endl;
		}
		else
		{
			cout << "Invalid choice. Please try again" << endl;
			
		}
	}
}

void magicmoneyevent(Start& simstart)
{
	choice = "1000000";
	double change = 1000000000;
	while (choice != "0" && choice != "1")
	{
		cout << "Santa claus gives your country one billion dollars." << endl;
		cout << "Do you accept the money? 1 for yes 0 for no." << endl;
		cin >> choice;
		if (choice == "0")
		{
			cout << "Nothing happens and poor Santa claus is upset :(" << endl;
		}
		else if (choice == "1")
		{
			cout << "Other non tax revenue increased by one billion" << endl;
			simstart.updateOther_non_tax_revenue(change);
			simstart.updaterevenue();
			simstart.updatenetgain_loss();
		}
		else 
		{
			cout << "Invalid. Try again" << endl;
			cin.clear();
		}
	}
}

void bigbankevent(Start& simstart)
{
	double change = 0.15;
	cout << "Banks be rolling in dough right now. Enjoy!" << endl;
	cout << "Federal reserve earnings increased by 15%." << endl;
	simstart.updateFederal_reserve_earnings(change);
	simstart.updaterevenue();
	simstart.updatenetgain_loss();
}

void fattyfoodevent(Start& simstart)
{
	double change = 0.05;
	cout << "The government decided to tax fatty foods even more to stop people from consuming a lot of it." << endl;
	cout << "Sales and excise taxes increased by 5%." << endl;
	simstart.updateSales_and_Excise_taxes(change);
	simstart.updaterevenue();
	simstart.updatenetgain_loss();
}

void newtaxevent(Start& simstart)
{
	double change = 0.3;
	cout << "There's a new tax on breathing air that's very profitable but received VERY poorly." << endl;
	cout << "Other taxes increased by 30%." << endl;
	simstart.updateOther_taxes(change);
	simstart.updaterevenue();
	simstart.updatenetgain_loss();
}

void lotsoflicensesevent(Start& simstart)
{
	double change = 0.05;
	cout << "Licenses at this time have made more money than ever!" << endl;
	cout << "Licenses increased by 5%." << endl;
	simstart.updateLicenses(change);
	simstart.updaterevenue();
	simstart.updatenetgain_loss();
}

void protectlibertyevent(Start& simstart)
{
	double change = 0.1;
	choice = "100000";
	while (choice != "0" && choice != "1")
	{
		cout << "Freedom is in jeporady." << endl;
		cout << "Will you increase liberty spending by 10% to make sure freedom will never go away?" << endl;
		cout << "1 for yes 0 for no." << endl;
		cin >> choice;
		if (choice == "0")
		{
			cout << "Freedom gone but hey more money." << endl;
		}
		else if (choice == "1")
		{
			simstart.updateLiberty(change);
			simstart.updatespending();
			simstart.updatenetgain_loss();
		}
		else 
		{
			cout << "Invalid answer. Try again" << endl;
			
		}
	}
	
	
}
