#pragma once

#include "Data.h"

class UserInterface
{
public:
	UserInterface(Data newData);
	~UserInterface();

	void StartSession();

private:
	Data data;
	Customer* viewedCustomer;
	Account* viewedAccount;

	void CustomerSelection();
	void AccountSelection();
	void AccountOptions();
};

