#include "pch.h"
#include "BusinessAccount.h"

#include <iostream>

BusinessAccount::BusinessAccount(int newCustomerID, int newAccountNumber, int initialBalance)
: Account(newCustomerID, newAccountNumber, initialBalance)
{

}


BusinessAccount::~BusinessAccount()
{
}

void BusinessAccount::AddToLoan(int amount)
{
	int balanceMinusLoan = balance - loanAmount;
	int maxLoanAmount = 3 * balanceMinusLoan;

	std::cout << "Current loan amount: ";
	std::cout << loanAmount << std::endl;
	std::cout << "Maximum loan amount: ";
	std::cout << maxLoanAmount << std::endl;

}
