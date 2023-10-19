#include "Car.h"
#include <iostream>

Car::Car()
{
}

Car::Car(std::string type, int age, int totalDaysRented, float totalRentalCost, std::string regNumber, std::string model, int noOfSeats, int noOfDoors, const char* make)
	:Vehicle{type, age, totalDaysRented, totalRentalCost, regNumber, model, make }, noOfSeats(noOfSeats), noOfDoors(noOfDoors)
{

}

Car::~Car()
{
	
}

float Car::calculateCost()
{
	float cost = 2500 - (age * 150) - (noOfDoors * 200);
	if (cost < 0)
	{
		cost = 0.0f;
	}
	return cost  /  100;
}


std::ostream& operator<<(std::ostream& out, Car* C)
{
	out << C->type << " ";
	out << C->age << " ";
	out << C->totalDaysRented << " ";
	out << C->totalRentalCost << " ";
	out << C->regNumber << " ";
	out << C->model << " ";
	out << C->noOfSeats << " ";
	out << C->noOfDoors << " ";
	for(int i = 0; i < strlen(C->make); i++)
	{
		out << C->make[i];
	}
	out << "\n";
	return out;
}

