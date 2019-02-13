#pragma once
#include "Account.h"
class StudentAccount :
	public Account
{
public:
	StudentAccount(int newCustomerID, int newAccountNumber, int initialBalance);
	~StudentAccount();

	void TestFunction();
};

