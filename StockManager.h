#pragma once
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "VehicleHistory.h"


class StockManager
{
public:

	//for adding, removing, and file interaction
	static void ReadVehiclesIntoVector(std::vector<Vehicle*> &v);
	static void AddStockToVector(std::vector<Vehicle*>& v);
	static void RemoveStockFromVector(std::vector<Vehicle*>& v);
	static void WriteVehiclesOnExit(std::vector<Vehicle*>& v);

	//for displaying and sorting the array

	static void DisplayStock(std::vector<Vehicle*>& v);
	static void SortRegistration(std::vector<Vehicle*>& v);
	static void SortCost(std::vector<Vehicle*>& v);
	static bool orderByRegPlate(const Vehicle* lhs, const Vehicle* rhs);

	//for interacting with vehicles
	static void ShowVehicleDetails(Vehicle* V);

	//for car search
	static void carSortRegistration(std::vector<Vehicle*>& v);
	static void carFilterDoors(std::vector<Vehicle*>& v);
	static void carFilterSeats(std::vector<Vehicle*>& v);

	//for bike search
	static void bikeSortRegistration(std::vector<Vehicle*>& v);
	static void bikeFilterEngine(std::vector<Vehicle*>& v);
	static void bikeFilterWheels(std::vector<Vehicle*>& v);

	//for interacting with the vehicle history
	static void AddVehicleHistory(Vehicle* V);
	static void ReadVehicleHistory(Vehicle* V, VehicleHistory ArrayVH[], int index);
	static void ShowVehicleHistory(VehicleHistory array[], int index);
	static void WriteVehicleHistory(VehicleHistory* VH, Vehicle* V);

	

	//memory cleaning for vehicles
	static void cleanUp(std::vector<Vehicle*>& v);



private:

};

