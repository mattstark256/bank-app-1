#include "pch.h"
#include "UserInterface.h"

#include <iostream>
#include "Customer.h"
#include "Account.h"

using namespace std;


UserInterface::UserInterface(Data* newData, Loan* newLoan, Interest* newInterest) : data(newData), loan(newLoan), interest(newInterest)
{
}


UserInterface::~UserInterface()
{
}


void UserInterface::StartSession()
{
	cout << "Welcome to the Bank of Abertay!" << endl;
	CustomerSelection();
}


void UserInterface::CustomerSelection()
{
	bool quitting = false;
	while (!quitting)
	{
		cout << "Please enter your customer ID. (0 to quit)" << endl;
		int customerID = 0;
		cin >> customerID;

		if (customerID == 0)
		{
			quitting = true;
		}
		else
		{
			viewedCustomer = data->GetCustomer(customerID);
			if (viewedCustomer != nullptr)
			{
				AccountSelection();
			}
			else
			{
				cout << "No customer found with that customer ID." << endl;
			}
		}
	}
}


void UserInterface::AccountSelection()
{
	bool quitting = false;
	while (!quitting)
	{
		cout << "Customer name: ";
		cout << viewedCustomer->GetName();
		cout << endl;

		cout << "Account numbers held: ";
		cout << endl;
		data->PrintAccountNumbers(viewedCustomer->GetCustomerID());

		cout << "Please select an account. (0 to cancel)" << endl;
		int accountNumber = 0;
		cin >> accountNumber;

		if (accountNumber == 0)
		{
			quitting = true;
		}
		else
		{
			viewedAccount = data->GetAccount(accountNumber);
			if (viewedAccount != nullptr &&
				viewedAccount->GetCustomerID() == viewedCustomer->GetCustomerID())
			{
				AccountOptions();
			}
			else
			{
				cout << "This customer doesn't hold an account with that account number." << endl;
			}
		}
	}
}


void UserInterface::AccountOptions()
{
	bool quitting = false;
	while (!quitting)
	{
		cout << "Balance: ";
		cout << viewedAccount->GetBalance();
		cout << endl;

		int menuChoice;
		cout << "Please choose an action:" << endl;
		cout << "1: withdraw money" << endl;
		cout << "2: deposit money" << endl;
		cout << "3: withdraw 10" << endl;
		cout << "4: calculate interest" << endl;
		cout << "5: calculate loan" << endl;
		cout << "6: assign a credit card" << endl;
		cout << "0: cancel" << endl;
		cin >> menuChoice;

		if (menuChoice == 1)
		{
			viewedAccount->Withdraw();
		}
		else if (menuChoice == 2)
		{
			viewedAccount->Deposit();
		}
		else if (menuChoice == 3)
		{
			viewedAccount->Withdraw(10);
		}
		else if (menuChoice == 4)
		{
			interest->CalculateInterest(viewedAccount);
		}
		else if (menuChoice == 5)
		{
			loan->CalculateLoan(viewedAccount);
		}
		else if (menuChoice == 6)
		{
			viewedAccount->AddCreditCard();
		}
		else if (menuChoice == 0)
		{
			quitting = true;
		}
	}
}
