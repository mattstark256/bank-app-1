#include "pch.h"
#include "Data.h"
#include <iostream>

using namespace std;


Data::Data()
{
	customersVector.push_back(new Customer(1, "Jane"));

	Customer customer2 = Customer(2, "Twolip");
	customersVector.push_back(&customer2);



	//customersVector.p
	cout << "called Data constructor\n";
	cout << customersVector[0]->GetCustomerID();
	cout << endl;
}


Data::~Data()
{
}


Customer* Data::GetCustomer(int customerID)
{
	cout << "called GetCustomer\n";
	cout << customersVector[1]->GetName();
	cout << endl;

	return nullptr;


	//if (customersVector.size() > 0)
	//{
	//	//Customer* customer = customersVector.at(0);
	//	Customer* customer = customersVector[0];
	//	if (customer != nullptr)
	//	{
	//		//cout << customer->GetName();
	//		cout << customer->GetCustomerID();
	//	}
	//	else
	//	{
	//		cout << "value is null\n";
	//	}
	//}
	//else
	//{
	//	cout << "outside range\n";
	//}


	//return customersVector[0];

	//for (int i = 0; i < 3; i++)
	//	//for (int i = 0; i < customersVector.size(); i++)
	//{
	//	Customer* customer = customersVector[i];
	//	int test = customer->GetCustomerID();
	//	cout << test;
	//	if (customersVector[i]->GetCustomerID() == customerID)
	//	{
	//		return customersVector[i];
	//	}
	//}
	//return nullptr;
}


Account* Data::GetAccount(int accountNumber)
{
	for (int i = 0; i < accountCount; i++)
	{
		if (accounts[i]->GetAccountNumber() == accountNumber)
		{
			return accounts[i];
		}
	}
	return nullptr;
}


void Data::PrintAccountNumbers(int customerID)
{
	for (int i = 0; i < accountCount; i++)
	{
		if (accounts[i]->GetCustomerID() == customerID)
		{
			cout << accounts[i]->GetAccountNumber();
			cout << endl;
		}
	}
	return;
}
