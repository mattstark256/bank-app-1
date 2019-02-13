#include "pch.h"
#include "StudentAccount.h"
#include <iostream>

using namespace std;


StudentAccount::StudentAccount(int newCustomerID, int newAccountNumber, int initialBalance, int initialOverdraft) :
	Account(newCustomerID, newAccountNumber, initialBalance),
	overdraft(initialOverdraft)
{
	accountType = Student;
}


StudentAccount::~StudentAccount()
{
}


// Withdraw needs to be overridden because for student accounts it must take into account the overdraft.
void StudentAccount::Withdraw(int amount)
{
	if (balance + overdraft >= amount)
	{
		balance -= amount;

		cout << amount;
		cout << " has been withdrawn.";
		cout << endl;
	}
	else
	{
		cout << "You can't withdraw ";
		cout << amount;
		cout << " because the account only holds ";
		cout << balance;
		cout << " with an overdraft of ";
		cout << overdraft;
		cout << ".";
		cout << endl;
	}
	cout << endl;
}


// Currently this just displays the overdraft. If additional features were required, such as modifying the overdraft, they could be included here in a menu.
void StudentAccount::ManageOverdraft()
{
	cout << "The overdraft on this account is ";
	cout << overdraft;
	cout << ".";
	cout << endl;
	cout << endl;
}
