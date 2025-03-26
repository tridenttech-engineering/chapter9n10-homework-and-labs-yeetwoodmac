//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Tyler Sharer> on <03/18/2025>
//This program calculates the monthly payments for a car loan with dealer financing and bank financing. The user enters the price of the car, rebate amount, dealer interest rate, bank interest rate, and number of years for the loan. The program calculates the monthly payments for both loans and displays the results.
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getPayment(double principal, double annualRate, int term)// Calculate the monthly payment using the formula for an amortizing loan
{
	int months = term * 12; // convert years to months
	double monthlyRate = annualRate / 12.0; // convert annual rate to monthly
	double powerFactor = pow((1 + monthlyRate), -months);
	double denominator = 1 - powerFactor;  // calculate the denominator for the payment formula
		if (denominator < 1e-9) { // check for division by zero
			return -1; // return -1 to indicate division by zero error
		}
	double payment = (principal * monthlyRate) / denominator;
	return payment; // return the calculated payment
} // end of payment function

int main()
{
	int carPrice = 0; // price of the car
	int rebate = 0; // rebate amount
	double rateBank = 0.0; // dealer imakenterest rate
	double rateDealer = 0.0; // credit union interest rate
	int term = 0; // number of years for the loan
	double paymentDealer = 0.0; // monthly payment for dealer loan
	double paymentBank = 0.0; // monthly payment for bank loan
	double totalPaymentDealer = 0.0; // total payment for dealer loan
	double totalPaymentBank = 0.0; // total payment for bank loan

	// Input the car price, rebate, dealer interest rate, bank interest rate, and number of months
	cout << "Enter the price of the car: ";
	cin >> carPrice;
	cout << "Enter the rebate amount: ";
	cin >> rebate;
	cout << "Enter the dealer interest rate (as a decimal): ";
	cin >> rateDealer;
	cout << "Enter the bank interest rate (as a decimal): ";
	cin >> rateBank;
	cout << "Enter the term in number of years for the loan: ";
	cin >> term;

	// Calculate the price of the car with bank financing (after rebate) and dealer financing
	int bankPrice = carPrice; // price of the car with bank financing
	int	dealerPrice = carPrice - rebate; // price of the car with dealer financing

	// Calculate the monthly payments for both loans by calling the payment function
	paymentDealer = getPayment(dealerPrice, rateDealer, term);
	paymentBank = getPayment(bankPrice, rateBank, term);
	// Calculate total payments for both loans
	totalPaymentDealer = paymentDealer * (term * 12); // total payment for dealer loan
	totalPaymentBank = paymentBank * (term * 12); // total payment for bank loan
	
	// Apply rounding before output
	paymentDealer = round(paymentDealer * 100) / 100; 
	paymentBank = round(paymentBank * 100) / 100; 
	totalPaymentDealer = round(paymentDealer * (term * 12) * 100) / 100; 
	totalPaymentBank = round(paymentBank * (term * 12) * 100) / 100;

		// Display the results
	cout << fixed << setprecision(2); // set output to 2 decimal places
	cout << "Monthly payment without rebate & dealer financing: $" << paymentDealer << endl;
	cout << "Total paid with dealer financing: $" << totalPaymentDealer << endl;
	cout << "Monthly payment with rebate & credit union financing: $" << paymentBank << endl;
	cout << "Total paid with bank financing: $" << totalPaymentBank << endl;


	return 0;
	//end of main function
}