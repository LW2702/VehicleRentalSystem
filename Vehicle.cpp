#include "Vehicle.h"

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(std::string type, int age, int totalDaysRented, float totalRentalCost, std::string regNumber, std::string model, const char* make)
	:type(type), age(age), totalDaysRented(totalDaysRented), totalRentalCost(totalRentalCost), regNumber(regNumber), model(model), make(make)
{
}

Vehicle::~Vehicle()
{
	free((void*)make);
}

float Vehicle::calculateCost()
{
	return 0.0f;
}

std::string Vehicle::getRegNumber()
{
	return regNumber;
}



