#include "pch.h"
#include "StudentAccount.h"

#include <iostream>


StudentAccount::StudentAccount(int newCustomerID, int newAccountNumber, int initialBalance)
	: Account(newCustomerID, newAccountNumber, initialBalance)
{
	accountType = 1;
}


StudentAccount::~StudentAccount()
{
}

void StudentAccount::TestFunction()
{
	std::cout << "void StudentAccount::TestFunction()";
}
