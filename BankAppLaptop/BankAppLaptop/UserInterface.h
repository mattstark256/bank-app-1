#pragma once

#include "Data.h"
#include "Interest.h"

class UserInterface
{
public:
	UserInterface(Data* newData, Interest* newInterest);
	~UserInterface();

	void StartSession();

private:
	Data* data;
	Customer* selectedCustomer;
	Account* selectedAccount;
	Interest* interest;

	void CustomerSelection();
	void CustomerOptions();
	void AccountSelection();
	void AccountOptions();
	void AddNewAccount();
};

