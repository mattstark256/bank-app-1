#include "pch.h"

#include <iostream>
#include "Data.h"
#include "UserInterface.h"

using namespace std;


int main()
{
	Data data = Data();
	UserInterface userInterface = UserInterface(data);

	userInterface.StartSession();
}