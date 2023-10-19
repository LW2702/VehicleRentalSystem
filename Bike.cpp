#include "Bike.h"
#include<iostream>

Bike::Bike()
{
}
Bike::Bike(std::string type, int age, int totalDaysRented, float totalRentalCost, std::string regNumber, std::string model, int engineSize, int noOfWheels, const char* make)
	:Vehicle{type, age, totalDaysRented, totalRentalCost, regNumber, model, make }, engineSize(engineSize), noOfWheels(noOfWheels)
{

}

Bike::~Bike()
{
	
}

float Bike::calculateCost()
{
	float cost = 1500 + engineSize;
	if (cost < 0)
	{
		cost = 0.0f;
	}
	return floor(cost + 1) / 100;
}





std::ostream& operator<<(std::ostream& out, Bike* B)
{
	out << B->type << " ";
	out << B->age << " ";
	out << B->totalDaysRented << " ";
	out << B->totalRentalCost << " ";
	out << B->regNumber << " ";
	out << B->model << " ";
	out << B->engineSize << " ";
	out << B->noOfWheels << " ";
	for (int i = 0; i < strlen(B->make); i++)
	{
		out << B->make[i];
	}
	out << "\n";
	return out;

}

