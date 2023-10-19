#pragma once
#include "Vehicle.h"
#include <iostream>
class Bike :
    public Vehicle
{
    Bike();
    Bike(std::string type, int age, int totalDaysRented, float totalRentalCost, std::string regNumber, std::string model, int engineSize, int noOfWheels, const char* make);
    ~Bike();
    //overloaded virtual function from base class
    float calculateCost();

    friend class StockManager;
    
    friend std::ostream& operator<<(std::ostream& out, Bike* B);

private:
    int engineSize = 0;
    int noOfWheels = 0;
};

