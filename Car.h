#pragma once
#include "Vehicle.h"
#include <iostream>
class Car :
    public Vehicle
{
public:
    Car();
    Car(std::string type, int age, int totalDaysRented, float totalRentalCost, std::string regNumber, std::string model, int noOfSeats, int noOfDoors, const char* make);
    ~Car();
    //overloaded virtual function from base class
    float calculateCost();


    friend class StockManager;

    friend std::ostream& operator<<(std::ostream& out, Car* C);  

private:
    int noOfSeats = 0;
    int noOfDoors = 0;
};

