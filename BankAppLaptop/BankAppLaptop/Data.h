#pragma once

#include "Customer.h"
#include "Account.h"


class Data
{
public:
	Data();
	~Data();

	Customer* GetCustomer(int customerID);
	Account* GetAccount(int accountNumber);
	void PrintAccountNumbers(int customerID);

private:
	int customerCount = 3;
	Customer customers[3] = {
		Customer(1, "Onedeline"),
		Customer(2, "Twoopsie"),
		Customer(3, "Threena") };
	int accountCount = 4;
	Account accounts[4] = {
		Account(1, 5, 544),
		Account(2, 8, 6599),
		Account(2, 2, 78549),
		Account(3, 1, 2445) };
};

