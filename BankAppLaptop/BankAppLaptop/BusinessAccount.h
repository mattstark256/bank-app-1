#pragma once
#include "Account.h"
class BusinessAccount :
	public Account
{
public:
	BusinessAccount(int newCustomerID, int newAccountNumber, int initialBalance);
	~BusinessAccount();

	void AddToLoan(int amount);

private:
	int loanAmount = 0;
};

