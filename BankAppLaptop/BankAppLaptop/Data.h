#pragma once

#include "Customer.h"
#include "Account.h"
#include <vector>


class Data
{
public:
	Data();
	~Data();

	Customer* GetCustomer(int customerID);
	Account* GetAccount(int accountNumber);
	void AddAccount(Account* newAccount);
	void PrintAccountNumbers(int customerID);
	int GetNewAccountNumber();

private:


	vector<Customer*> customersVector;
	vector<Account*> accountsVector;
};

