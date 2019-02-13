#pragma once
#include "CreditCard.h"

class Account
{
public:
	Account(int newCustomerID, int newAccountNumber, int initialBalance);
	~Account();

	int GetCustomerID();
	int GetAccountNumber();
	int GetBalance();
	void Deposit();
	void Withdraw();
	void Withdraw(int amount);
	void AddCreditCard();

protected:
	int balance;
	int accountType = 0; // TODO change this to enum?

private:
	int customerID;
	int accountNumber;
	CreditCard* creditCard;
};

