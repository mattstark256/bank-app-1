#pragma once

#include "Data.h"
#include "Loan.h"
#include "Interest.h"

class UserInterface
{
public:
	UserInterface(Data* newData, Loan* newLoan, Interest* newInterest);
	~UserInterface();

	void StartSession();

private:
	Data* data;
	Customer* selectedCustomer;
	Account* selectedAccount;
	Loan* loan;
	Interest* interest;

	void CustomerSelection();
	void CustomerOptions();
	void AccountSelection();
	void AccountOptions();
	void AddNewAccount();
};

