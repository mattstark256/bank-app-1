#pragma once

#include "Account.h"


class Interest
{
public:
	Interest();
	~Interest();

	void CalculateInterest(Account* account);

private:
	float interestRate = 0.05;
};

