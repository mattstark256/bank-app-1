#include "pch.h"
#include "UserInterface.h"

#include <iostream>
#include "Customer.h"
#include "Account.h"
#include "StudentAccount.h"
#include "BusinessAccount.h"

using namespace std;


UserInterface::UserInterface(Data* newData, Interest* newInterest) : data(newData), interest(newInterest)
{
}


UserInterface::~UserInterface()
{
}


void UserInterface::StartSession()
{
	cout << "Welcome to the Bank of Abertay!" << endl;
	cout << endl;
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
		cout << endl;

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
		cout << "Customer ID: ";
		cout << selectedCustomer->GetCustomerID();
		cout << endl;

		cout << "Customer name: ";
		cout << selectedCustomer->GetName();
		cout << endl;

		int menuChoice;
		cout << "Please choose an action:" << endl;
		cout << "1: Manage existing accounts" << endl;
		cout << "2: Create new account" << endl;
		cout << "0: Cancel" << endl;
		cin >> menuChoice;
		cout << endl;

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
		cout << endl;

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
		cout << "Account number: ";
		cout << selectedAccount->GetAccountNumber();
		cout << endl;

		cout << "Account type: ";
		switch (selectedAccount->getAccountType())
		{
		case Regular :
			std::cout << "Regular account";
			break;
		case Student :
			std::cout << "Student account";
			break;
		case Business :
			std::cout << "Business account";
			break;
		}
		cout << endl;

		cout << "Balance: ";
		cout << selectedAccount->GetBalance();
		cout << endl;

		int menuChoice;
		cout << "Please choose an action:" << endl;
		cout << "1: Withdraw money" << endl;
		cout << "2: Deposit money" << endl;
		cout << "3: Withdraw 10" << endl;
		cout << "4: Calculate interest" << endl;
		cout << "5: Assign a credit card" << endl;

		if (selectedAccount->getAccountType() == Student)
		{
			cout << "6: Manage overdraft" << endl;
		}
		if (selectedAccount->getAccountType() == Business)
		{
			cout << "6: Manage loan" << endl;
		}

		cout << "0: Cancel" << endl;
		cin >> menuChoice;
		cout << endl;

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
			selectedAccount->AddCreditCard();
		}
		else if (selectedAccount->getAccountType() == Student && menuChoice == 6)
		{
			static_cast<StudentAccount*>(selectedAccount)->ManageOverdraft();
		}
		else if (selectedAccount->getAccountType() == Business && menuChoice == 6)
		{
			static_cast<BusinessAccount*>(selectedAccount)->ManageLoan();
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

	bool quitting = false;
	while (!quitting)
	{
		int menuChoice;
		cout << "What type of account would you like to create?" << endl;
		cout << "1: Regular account" << endl;
		cout << "2: Student account" << endl;
		cout << "3: Business account" << endl;
		cout << "0: Cancel" << endl;
		cin >> menuChoice;
		cout << endl;

		if (menuChoice == 1)
		{
			data->AddAccount(new Account(selectedCustomer->GetCustomerID(), newAccountNumber, 0));
			cout << "Created new Regular account with account number ";
			cout << newAccountNumber;
			cout << " and a balance of 0.";
			cout << endl;
			quitting = true;
		}
		else if (menuChoice == 2)
		{
			data->AddAccount(new StudentAccount(selectedCustomer->GetCustomerID(), newAccountNumber, 0, 50));
			cout << "Created new Student account with account number ";
			cout << newAccountNumber;
			cout << " and a balance of 0.";
			cout << endl;
			quitting = true;
		}
		else if (menuChoice == 3)
		{
			data->AddAccount(new BusinessAccount(selectedCustomer->GetCustomerID(), newAccountNumber, 0));
			cout << "Created new Business account with account number ";
			cout << newAccountNumber;
			cout << " and a balance of 0.";
			cout << endl;
			quitting = true;
		}
		else if (menuChoice == 0)
		{
			quitting = true;
		}
		cout << endl;
	}
}
