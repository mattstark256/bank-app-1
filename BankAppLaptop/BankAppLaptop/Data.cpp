#include "pch.h"
#include "Data.h"
#include <iostream>

using namespace std;


Data::Data()
{
}


Data::~Data()
{
}


Customer* Data::GetCustomer(int customerID)
{
	for (int i = 0; i < customerCount; i++)
	{
		if (customers[i].GetCustomerID() == customerID)
		{
			return &(customers[i]);
		}
	}
	return nullptr;
}


Account* Data::GetAccount(int accountNumber)
{
	for (int i = 0; i < accountCount; i++)
	{
		if (accounts[i].GetAccountNumber() == accountNumber)
		{
			return &(accounts[i]);
		}
	}
	return nullptr;
}


void Data::PrintAccountNumbers(int customerID)
{
	for (int i = 0; i < accountCount; i++)
	{
		if (accounts[i].GetCustomerID() == customerID)
		{
			cout << accounts[i].GetAccountNumber();
			cout << endl;
		}
	}
	return;
}
