//Lab10-2.cpp - displays total owed
//Created/revised by <Tyler Sharer> on <10/23/2023>
// This program calculates the total amount owed by a Patterson Window customer for their window order, using number of windows and price per window, and whether the sale is a BOGO (Buy One Get One) sale or regular sale. Cal
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
	int numWindows = 0; // number of windows ordered
	double windowPrice = 0.0; // price per window
	double totalAmountOwed = 0.0; // total amount owed
	int pricingOption = 0; // flag for BOGO sale (2) or regular sale (1)
	
	// Input the number of windows, price per window, and whether the sale is a BOGO sale
	cout << "Is this a BOGO sale (1 for no, 2 for yes)? ";
	cin >> pricingOption;
	cout << "Enter the number of windows ordered: ";
	cin >> numWindows;
	cout << "Enter the price per window: ";
	cin >> windowPrice;
	
	
	// Calculate the total amount owed
	if (pricingOption == 1) // regular sale
	{
		totalAmountOwed = numWindows * windowPrice;
	} // end if
	else if (pricingOption == 2) // BOGO sale
	{
		double bogoWindows = ceil(numWindows / 2.0); // number of windows in a BOGO sale
		totalAmountOwed = bogoWindows * windowPrice;
	} // end else
	
	// Output the total amount owed
	cout << fixed << setprecision(2);
	cout << "The total amount owed is $" << totalAmountOwed << endl;

    return 0;
} //end of main function