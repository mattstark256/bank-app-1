#pragma once
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

private:
	int customerID;
	int accountNumber;
	int balance;
};

