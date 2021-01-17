#ifndef END_H
#define END_H



#include <iostream>
using namespace std;

class End {

private:
	int year = 0;
	double Revenue = 0;
	double Spending = 0;
	double Netgain_loss = 0;
public:
	End();
	End(int endyear);
	void setRevenue_Spending_Netgain_loss();
	double getrevenue();
	double getspending();
	double getnetgain_loss();
};






#endif
