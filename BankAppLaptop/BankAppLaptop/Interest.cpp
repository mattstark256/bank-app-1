#include "pch.h"
#include "Interest.h"
#include <iostream>
#include <cmath>
using namespace std;


Interest::Interest()
{
}


Interest::~Interest()
{
}


void Interest::CalculateInterest(Account * account)
{
	int balance = account->GetBalance();
	int years = 0;

	cout << "How many years interest would you like to calculate?" << endl;
	cin >> years;
	int interestAmount = floor(balance * pow(1 + interestRate, years) - balance);
	cout << "The interest rate is ";
	cout << interestRate;
	cout << " so in ";
	cout << years;
	cout << " years it will earn ";
	cout << interestAmount;
	cout << "." << endl;
}
