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

private:
	int customerID;
	int accountNumber;
	int balance;
	CreditCard* creditCard;
};

