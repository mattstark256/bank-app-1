#pragma once
#include "Account.h"
class BusinessAccount :
	public Account
{
public:
	BusinessAccount(int newCustomerID, int newAccountNumber, int initialBalance);
	~BusinessAccount();

	void ManageLoan();

private:
	void IncreaseLoan();
	int loanAmount = 0;
};

