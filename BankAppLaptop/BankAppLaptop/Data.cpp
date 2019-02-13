#include "pch.h"
#include "Data.h"
#include <iostream>

#include "StudentAccount.h"
#include "BusinessAccount.h"

using namespace std;


Data::Data()
{
	customersVector.push_back(new Customer(1, "Jane"));
	customersVector.push_back(new Customer(2, "Twolip"));
	customersVector.push_back(new Customer(3, "Threena"));

	accountsVector.push_back(new Account(1, 1, 544));
	accountsVector.push_back(new Account(2, 3, 6599));
	accountsVector.push_back(new StudentAccount(2, 5, 78549));
	accountsVector.push_back(new BusinessAccount(3, 2, 2445));
}


Data::~Data()
{
}


Customer* Data::GetCustomer(int customerID)
{
	for (int i = 0; i < customersVector.size(); i++)
	{
		Customer* customer = customersVector[i];
		if (customersVector[i]->GetCustomerID() == customerID)
		{
			return customersVector[i];
		}
	}
	return nullptr;
}


Account* Data::GetAccount(int accountNumber)
{
	for (int i = 0; i < accountsVector.size(); i++)
	{
		if (accountsVector[i]->GetAccountNumber() == accountNumber)
		{
			return accountsVector[i];
		}
	}
	return nullptr;
}


void Data::AddAccount(Account * newAccount)
{
	accountsVector.push_back(newAccount);
}


void Data::PrintAccountNumbers(int customerID)
{
	for (int i = 0; i < accountsVector.size(); i++)
	{
		if (accountsVector[i]->GetCustomerID() == customerID)
		{
			cout << accountsVector[i]->GetAccountNumber();
			cout << endl;
		}
	}
	return;
}


// Returns the lowest available account number
int Data::GetNewAccountNumber()
{
	int newAccountNumber = 1; // All account numbers should be integers above 0

	// Repeatedly iterate through all existing accounts until newAccountNumber doesn't match any of them
	bool accountNumberChanged = false;
	do
	{
		accountNumberChanged = false;
		for (int i = 0; i < accountsVector.size(); i++)
		{
			if (accountsVector[i]->GetAccountNumber() == newAccountNumber)
			{
				newAccountNumber++;
				accountNumberChanged = true;
			}
		}
	}
	while (accountNumberChanged);

	return newAccountNumber;
}
