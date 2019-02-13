#pragma once
#include "Account.h"


class StudentAccount :
	public Account
{
public:
	StudentAccount(int newCustomerID, int newAccountNumber, int initialBalance, int initialOverdraft);
	~StudentAccount();

	void Withdraw(int amount);
	void ManageOverdraft();

private:
	int overdraft;
};

