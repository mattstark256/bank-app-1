#include "pch.h"

#include <iostream>
#include "Data.h"
#include "UserInterface.h"
#include "Loan.h"
#include "Interest.h"

using namespace std;


int main()
{
	Data data = Data();
	Loan loan = Loan();
	Interest interest = Interest();
	UserInterface userInterface = UserInterface(&data, &loan, &interest);

	userInterface.StartSession();
}