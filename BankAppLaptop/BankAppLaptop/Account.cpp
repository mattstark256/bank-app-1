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
	cout << endl;

	balance += amount;

	cout << amount;
	cout << " has been deposited.";
	cout << endl;
	cout << endl;
}


void Account::Withdraw()
{
	cout << "How much would you like to withdraw?";
	cout << endl;
	int amount;
	cin >> amount;
	cout << endl;

	Withdraw(amount);
}


void Account::Withdraw(int amount)
{
	if (balance >= amount)
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
		cout << ".";
		cout << endl;
	}
	cout << endl;
}

void Account::AddCreditCard()
{
	if (creditCard != nullptr)
	{
		cout << "This account already has a credit card assigned to it.";
		cout << endl;
	}
	else
	{
		cout << "What should the overdraft of the card be?";
		cout << endl;
		int overdraft;
		cin >> overdraft;
		cout << endl;

		if (overdraft > balance)
		{
			cout << "This account only holds ";
			cout << balance;
			cout << ". You can't have an overdraft greater than the account balance.";
			cout << endl;
		}
		else
		{
			// I'm using the variable newCard because you can't get the address of something in the same statement as the constructor. I'm using a pointer so I can check if creditCard is null.
			CreditCard newCard = CreditCard(overdraft);
			creditCard = &newCard;
			cout << "This account now has a credit card with an overdraft of ";
			cout << overdraft;
			cout << ".";
			cout << endl;
		}
	}
	cout << endl;
}

AccountType Account::getAccountType()
{
	return accountType;
}
