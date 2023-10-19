#pragma once
#include <string>
class Vehicle
{
public:
	//constructors
	Vehicle();
	Vehicle(std::string type, int age, int totalDaysRented, float totalRentalCost, std::string regNumber, std::string model, const char* make);
	//destructor
	~Vehicle();

	//cost Calculation function
	virtual float calculateCost();
	std::string getRegNumber();

	
	friend class StockManager;

protected:
	int age = 0;
	const char* make = (char*)malloc(sizeof(char) * 10);
	std::string model;
	std::string regNumber;
	std::string type;

	//for Vehicle History
	float totalRentalCost = 0.0f;
	int totalDaysRented = 0;

};

