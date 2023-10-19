#pragma once
#include <string>
#include "Vehicle.h"

using namespace std;

class VehicleHistory
{
public:

	VehicleHistory(string dateTo, string dateFrom, int daysToRent, float costForRent, string name, string address, string number);
	VehicleHistory();
	~VehicleHistory();
	static void fillInForm(Vehicle* V, VehicleHistory* newForm, float dailyCost);

	friend class StockManager;


private:

	float costPerDay;
	float totalRentalIncome;

	string dateTo;
	string dateFrom;
	int daysToRent = 0;
	float costForRent = 0.0f;
	string name;
	string address;
	string number;
};

