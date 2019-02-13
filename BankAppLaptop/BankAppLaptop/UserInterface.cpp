#include "pch.h"
#include "UserInterface.h"

#include <iostream>
#include "Customer.h"
#include "Account.h"
#include "StudentAccount.h"
#include "BusinessAccount.h"

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


// Select a customer by Customer ID
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
			selectedCustomer = data->GetCustomer(customerID);
			if (selectedCustomer != nullptr)
			{
				CustomerOptions();
			}
			else
			{
				cout << "No customer found with that customer ID." << endl;
			}
		}
	}
}


// Select an action to take for the customer
void UserInterface::CustomerOptions()
{
	bool quitting = false;
	while (!quitting)
	{
		cout << "Customer name: ";
		cout << selectedCustomer->GetName();
		cout << endl;

		int menuChoice;
		cout << "Please choose an action:" << endl;
		cout << "1: Manage existing accounts" << endl;
		cout << "2: Create new account" << endl;
		cout << "0: Cancel" << endl;
		cin >> menuChoice;

		if (menuChoice == 1)
		{
			AccountSelection();
		}
		else if (menuChoice == 2)
		{
			AddNewAccount();
		}
		else if (menuChoice == 0)
		{
			quitting = true;
		}
	}
}


// Select one of the customer's accounts by account number
void UserInterface::AccountSelection()
{
	bool quitting = false;
	while (!quitting)
	{
		cout << "Account numbers held: ";
		cout << endl;
		data->PrintAccountNumbers(selectedCustomer->GetCustomerID());

		cout << "Please select an account. (0 to cancel)" << endl;
		int accountNumber = 0;
		cin >> accountNumber;

		if (accountNumber == 0)
		{
			quitting = true;
		}
		else
		{
			selectedAccount = data->GetAccount(accountNumber);
			if (selectedAccount != nullptr &&
				selectedAccount->GetCustomerID() == selectedCustomer->GetCustomerID())
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


// Select an action to take with the account
void UserInterface::AccountOptions()
{
	bool quitting = false;
	while (!quitting)
	{


		// I should use an accounttype variable to check
		/*if (myStudentAccount != nullptr)
		{
			StudentAccount *myStudentAccount = static_cast <StudentAccount*>(selectedAccount);
			cout << "It's a student account." << endl;
			myStudentAccount->TestFunction();
		}*/
		

		cout << "Balance: ";
		cout << selectedAccount->GetBalance();
		cout << endl;

		int menuChoice;
		cout << "Please choose an action:" << endl;
		cout << "1: Withdraw money" << endl;
		cout << "2: Deposit money" << endl;
		cout << "3: Withdraw 10" << endl;
		cout << "4: Calculate interest" << endl;
		cout << "5: Calculate loan" << endl;
		cout << "6: Assign a credit card" << endl;

		
		// If accounttype is student account show 7th option


		cout << "0: Cancel" << endl;
		cin >> menuChoice;

		if (menuChoice == 1)
		{
			selectedAccount->Withdraw();
		}
		else if (menuChoice == 2)
		{
			selectedAccount->Deposit();
		}
		else if (menuChoice == 3)
		{
			selectedAccount->Withdraw(10);
		}
		else if (menuChoice == 4)
		{
			interest->CalculateInterest(selectedAccount);
		}
		else if (menuChoice == 5)
		{
			loan->CalculateLoan(selectedAccount);
		}
		else if (menuChoice == 6)
		{
			selectedAccount->AddCreditCard();
		}
		else if (menuChoice == 0)
		{
			quitting = true;
		}
	}
}


// Create a new account for the customer
void UserInterface::AddNewAccount()
{
	int newAccountNumber = data->GetNewAccountNumber();
	data->AddAccount(new Account(selectedCustomer->GetCustomerID(), newAccountNumber, 0));

	cout << "Created new account with account number ";
	cout << newAccountNumber;
	cout << " and a balance of 0.";
	cout << endl;
}
