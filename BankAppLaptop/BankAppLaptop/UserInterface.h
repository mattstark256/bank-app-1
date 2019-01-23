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
	Customer* viewedCustomer;
	Account* viewedAccount;
	Loan* loan;
	Interest* interest;

	void CustomerSelection();
	void AccountSelection();
	void AccountOptions();
};

