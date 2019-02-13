#include "pch.h"

#include <iostream>
#include "Data.h"
#include "UserInterface.h"
#include "Interest.h"

using namespace std;


int main()
{
	Data data = Data();
	Interest interest = Interest();
	UserInterface userInterface = UserInterface(&data, &interest);

	userInterface.StartSession();
}