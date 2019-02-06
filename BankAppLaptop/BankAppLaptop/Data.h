#pragma once

#include "Customer.h"
#include "Account.h"
#include <vector>


class Data
{
public:
	Data();
	~Data();

	Customer* GetCustomer(int customerID);
	Account* GetAccount(int accountNumber);
	void PrintAccountNumbers(int customerID);

private:

	Account account1 = Account(1, 5, 544);
	Account account2 = Account(2, 8, 6599);
	Account account3 = Account(2, 2, 78549);
	Account account4 = Account(3, 1, 2445);

	//ArrayList customers = new ArrayList();

	//int customerCount = 3;
	/*Customer *customers[3] = {
		&customer1,
		&customer2,
		&customer3 };*/

	vector<Customer*> customersVector;
	vector<int> numbersVector;

	int accountCount = 4;
	Account *accounts[4] = {
		&account1,
		&account2,
		&account3,
		&account4 };
};

