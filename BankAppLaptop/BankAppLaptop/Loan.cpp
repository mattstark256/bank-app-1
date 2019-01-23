#include "pch.h"
#include "Loan.h"
#include <iostream>
using namespace std;


Loan::Loan()
{
}


Loan::~Loan()
{
}


void Loan::CalculateLoan(Account * account)
{
	cout << "The maximum loan you can take is ";
	cout << account->GetBalance() * 2;
	cout << ".";
	cout << endl;
}
