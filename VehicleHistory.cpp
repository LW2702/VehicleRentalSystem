#include<iostream>
#include "VehicleHistory.h"
using namespace std;

VehicleHistory::VehicleHistory(string dateTo, string dateFrom, int daysToRent, float totalCost, string name, string address, string number)
	:dateTo(dateTo), dateFrom(dateFrom), daysToRent(daysToRent), costForRent(costForRent), name(name), address(address), number(number)
{
}

VehicleHistory::VehicleHistory()
{
}

VehicleHistory::~VehicleHistory()
{
}

//takes object passed to it from StockManager and assigns it values given by the user
void VehicleHistory::fillInForm(Vehicle* V, VehicleHistory* newForm, float dailyCost)
{
	string dateTo;
	string dateFrom;
	int daysToRent;

	string name;
	string address;
	string number;

	std::cout << "Vehicle Rental Form: " << V->getRegNumber() << endl << endl;
	std::cout << "__________________________________________________________" << endl;
	std::cout << "Enter Starting Rent Date: ";
	std::cin >> dateFrom;
	std::cout << "__________________________________________________________" << endl;

	std::cout << "__________________________________________________________" << endl;
	std::cout << "Enter End of Rent Date: ";
	std::cin >> dateTo;
	std::cout << "__________________________________________________________" << endl;

	std::cout << "__________________________________________________________" << endl;
	std::cout << "Enter Amount Days To Rent The Vehicle: ";
	std::cin >> daysToRent;
	std::cout << "__________________________________________________________" << endl;

	std::cout << "__________________________________________________________" << endl;
	std::cout << "Enter Your Name: ";
	std::cin >> name;
	std::cout << "__________________________________________________________" << endl;

	std::cout << "__________________________________________________________" << endl;
	std::cout << "Enter Your Address: ";
	std::cin >> address;
	std::cout << "__________________________________________________________" << endl;

	std::cout << "__________________________________________________________" << endl;
	std::cout << "Enter Your Number: ";
	std::cin >> number;
	std::cout << "__________________________________________________________" << endl;

	//float doesnt go into constructor properly
	newForm->dateTo = dateTo;
	newForm->dateFrom = dateFrom;
	newForm->daysToRent = daysToRent;
	newForm->costForRent = (dailyCost * daysToRent);
	newForm->name = name;
	newForm->address = address;
	newForm->number = number;
}


