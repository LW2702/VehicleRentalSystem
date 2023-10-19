#include "MenuSystem.h"
#include "StockManager.h"
#include "VehicleHistory.h"
#include <vector>
#include <iostream>


void MenuSystem::StartApplication()
{
	//function pointers for car:
	void(*carRegSearch_ptr)(std::vector<Vehicle*>&v) = &StockManager::carSortRegistration;
	void(*carDoorsSearch_ptr)(std::vector<Vehicle*>&v) = &StockManager::carFilterDoors;
	void(*carSeatsSearch_ptr)(std::vector<Vehicle*>&v) = &StockManager::carFilterSeats;

	//function pointers for bike:
	void(*bikeSortReg_ptr)(std::vector<Vehicle*>&v) = &StockManager::bikeSortRegistration;
	void(*bikeFilterEngine_ptr)(std::vector<Vehicle*>&v) = &StockManager::bikeFilterEngine;
	void(*bikeFilterWheels_ptr)(std::vector<Vehicle*>&v) = &StockManager::bikeFilterWheels;

	//garage will hold the vehicles
	std::vector<Vehicle*> garage;
	StockManager::ReadVehiclesIntoVector(garage);
	
	int choice = 0;
	do
	{
		std::cout << std::endl << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\t\t\tVehicle Rental System" << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "Registration:\t\t\tCost:\t\t\tType: " << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		StockManager::DisplayStock(garage);
		if (garage.size() == 0)
		{
			std::cout << "There are currently no vehicles available to rent." << std::endl;
		}

		std::cout << std::endl << std::endl;

		std::cout << "1) Add vehicle" << std::endl;
		std::cout << "2) Remove vehicle" << std::endl;
		std::cout << "3) Search for car" << std::endl;
		std::cout << "4) Search for bike" << std::endl;
		std::cout << "5) Sort vehicles by registration number" << std::endl;
		std::cout << "6) Sort by cost per day" << std::endl;
		std::cout << "9) Exit" << std::endl << std::endl;

		std::cout << "enter a choice: ";
		std::cin >> choice;
		std::cout << std::endl << std::endl;

		switch (choice)
		{
		case 1:
			{
				StockManager::AddStockToVector(garage);
				break;
			}
			case 2:
			{
				StockManager::RemoveStockFromVector(garage);
				break;

			}
			case 3:
			{
				std::cout << "Search for a Car By: " << std::endl;
				std::cout << "_____________________________" << std::endl;
				std::cout << "1) Registration number" << std::endl;
				std::cout << "2) Number of Seats" << std::endl;
				std::cout << "3) Number of Doors" << std::endl;
				std::cout << "0) Return to main menu" << std::endl;
				std::cout << "_____________________________" << std::endl;

				std::cin >> choice;

				void (*carSearchFuncArr[3])(std::vector<Vehicle*>&v) = { carRegSearch_ptr, carSeatsSearch_ptr, carDoorsSearch_ptr };

				if (choice == 0)
				{
					break;
				}
				else if (choice <= 3 && choice > 0)
				{
					(carSearchFuncArr[choice - 1])(garage);
				}
				

				break;
			}
			case 4:
			{
				std::cout << "Search for a Bike By: " << std::endl;
				std::cout << "_____________________________" << std::endl;
				std::cout << "1) Registration number" << std::endl;
				std::cout << "2) Engine Size" << std::endl;
				std::cout << "3) Number of Wheels" << std::endl;
				std::cout << "0) Return to main menu" << std::endl;
				std::cout << "_____________________________" << std::endl;

				std::cin >> choice;

				void (*bikeSearchFuncArr[3])(std::vector<Vehicle*>&v) = { bikeSortReg_ptr, bikeFilterEngine_ptr, bikeFilterWheels_ptr };
				if (choice == 0)
				{
					break;
				}
				else if(choice <= 3 && choice > 0)
				{
					(bikeSearchFuncArr[choice - 1])(garage);
				}


				break;
			}
			case 5:
			{

				std::cout << "\t\tSorted By Registration Number\n";
				std::cout << "____________________________________________________________________" << std::endl;
				std::cout << std::endl << std::endl;
				std::cout << "____________________________________________________________________" << std::endl;
				std::cout << "Registration:\t\t\tCost:\t\t\tType: " << std::endl;
				std::cout << "____________________________________________________________________" << std::endl;
				StockManager::SortRegistration(garage);
				break;
			}
			case 6:
			{
				std::cout << "\t\tSorted By Cost Per Day\n";
				std::cout << "____________________________________________________________________" << std::endl;
				StockManager::SortCost(garage);
				break;
			}
			case 9:
			{
				StockManager::WriteVehiclesOnExit(garage);
				break;
			}
			default:
			{
				std::cout << "That wasn't a valid choice. Try again." << std::endl;
				continue;
			}
		}


	} while (choice != 9);
	
	StockManager::cleanUp(garage);
}