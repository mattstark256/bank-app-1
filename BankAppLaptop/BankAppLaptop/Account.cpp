#include "pch.h"
#include "Account.h"
#include <iostream>
using namespace std;


Account::Account(int newCustomerID, int newAccountNumber, int initialBalance) :
	customerID(newCustomerID),
	accountNumber(newAccountNumber),
	balance(initialBalance)
{
}


Account::~Account()
{
}


int Account::GetCustomerID()
{
	return customerID;
}


int Account::GetAccountNumber()
{
	return accountNumber;
}


int Account::GetBalance()
{
	return balance;
}


void Account::Deposit()
{
	cout << "How much would you like to deposit?";
	cout << endl;
	int amount;
	cin >> amount;

	balance += amount;

	cout << amount;
	cout << " has been deposited.";
	cout << endl;
}


void Account::Withdraw()
{
	cout << "How much would you like to withdraw?";
	cout << endl;
	int amount;
	cin >> amount;

	if (balance > amount)
	{
		balance -= amount;

		cout << amount;
		cout << " has been withdrawn.";
		cout << endl;
	}
	else
	{
		cout << "You can't withdraw ";
		cout << amount;
		cout << " because the account only holds ";
		cout << balance;
		cout << endl;
	}
}
