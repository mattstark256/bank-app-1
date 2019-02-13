#pragma once
#include "CreditCard.h"

enum AccountType { Regular, Business, Student };

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
	virtual void Withdraw(int amount);
	void AddCreditCard();
	AccountType getAccountType();

protected:
	int balance;
	AccountType accountType = Regular;

private:
	int customerID;
	int accountNumber;
	CreditCard* creditCard;
};

