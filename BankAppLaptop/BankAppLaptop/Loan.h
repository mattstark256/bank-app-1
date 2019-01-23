#pragma once

#include "Account.h"


class Loan
{
public:
	Loan();
	~Loan();

	void CalculateLoan(Account* account);
};

