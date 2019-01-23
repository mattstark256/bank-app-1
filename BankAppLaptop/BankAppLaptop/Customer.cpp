#include "pch.h"
#include "Customer.h"


Customer::Customer(int newCustomerID, string newName) : customerID(newCustomerID), name(newName)
{
}


Customer::~Customer()
{
}


int Customer::GetCustomerID()
{
	return customerID;
}


string Customer::GetName()
{
	return name;
}
