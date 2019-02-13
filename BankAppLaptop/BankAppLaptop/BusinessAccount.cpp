#include "pch.h"
#include "BusinessAccount.h"

#include <iostream>

using namespace std;


BusinessAccount::BusinessAccount(int newCustomerID, int newAccountNumber, int initialBalance)
: Account(newCustomerID, newAccountNumber, initialBalance)
{
	accountType = Business;
}


BusinessAccount::~BusinessAccount()
{
}


void BusinessAccount::ManageLoan()
{
	bool quitting = false;
	while (!quitting)
	{
		if (loanAmount == 0)
		{
			cout << "There is currently no loan on this account.";
			cout << endl;
		}
		else
		{
			cout << "There is currently a loan of ";
			cout << loanAmount;
			cout << " on this account.";
			cout << endl;
		}

		// The maximum loan that can be taken is 3 times the non-loan balance of the account.
		int maxLoanAmount = 3 * (balance - loanAmount);
		cout << "The maximum loan that can be taken on this account is ";
		cout << maxLoanAmount;
		cout << ".";
		cout << endl;

		int menuChoice;
		cout << "Please choose an action:" << endl;
		cout << "1: Increase loan" << endl;
		cout << "0: Cancel" << endl;
		cin >> menuChoice;

		if (menuChoice == 1)
		{
			IncreaseLoan();
		}
		else if (menuChoice == 0)
		{
			quitting = true;
		}
	}
}


void BusinessAccount::IncreaseLoan()
{
	int increaseAmount;
	cout << "How much would you like to increase the loan by?" << endl;
	cin >> increaseAmount;

	int maxLoanAmount = 3 * (balance - loanAmount);
	if (loanAmount + increaseAmount > maxLoanAmount)
	{
		cout << "That would exceed the maximum loan on the account." << endl;
	}
	else
	{
		balance += increaseAmount;
		loanAmount += increaseAmount;
		cout << "Your loan value has been increased." << endl;
	}
}