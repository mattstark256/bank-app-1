#pragma once
#include <string>

using namespace std;


class Customer
{
public:
	Customer(int newCustomerID, string newName);
	~Customer();

	int GetCustomerID();
	string GetName();

private:
	int customerID;
	string name;
};

