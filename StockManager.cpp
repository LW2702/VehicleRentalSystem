#include "StockManager.h"
#include "VehicleHistory.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h >


using namespace std;


//vector for VehicleHistory objects
vector <VehicleHistory*> VHArr;



void StockManager::ReadVehiclesIntoVector(std::vector<Vehicle*>& v)
{
	//read in cars
	std::ifstream reader("CAR_STOCK.txt", std::ios::in);
	if (reader.is_open())
	{
		while (!reader.eof())
		{
			std::string type;
			std::string regNumber;
			std::string model;
			char* make = (char*)malloc(sizeof(char) * 10);
			float cost(0.0);
			int age(0);
			int totalDaysRented = 0;
			float totalRentalCost = 0;
			int noOfDoors;
			int noOfSeats;

			reader >> type;
			reader >> age;
			reader >> totalDaysRented;
			reader >> totalRentalCost;
			reader >> regNumber;
			reader >> model;
			reader >> noOfDoors;
			reader >> noOfSeats;
			reader >> make;

			Car* car = new Car(type, age, totalDaysRented, totalRentalCost, regNumber, model, noOfDoors, noOfSeats, make);
			//cast to Vehicle* store in vector
			(Vehicle*)static_cast<Vehicle*>(car);
			v.push_back(car);
		}
		reader.close();
	}
		
		//read in bikes
		std::ifstream reader2("BIKE_STOCK.txt", std::ios::in);
		if (reader2.is_open())
		{
			while (!(reader2.eof()))
			{
				std::string type;
				std::string regNumber;
				std::string model;
				char* make = (char*)malloc(sizeof(char) * 10);
				float cost(0.0);
				int age(0);
				int totalDaysRented = 0;
				float totalRentalCost = 0;
				int engineSize;
				int noOfWheels;

				reader2 >> type;
				reader2 >> age;
				reader2 >> totalDaysRented;
				reader2 >> totalRentalCost;
				reader2 >> regNumber;
				reader2 >> model;
				reader2 >> engineSize;
				reader2 >> noOfWheels;
				reader2 >> make;

				Bike* bike = new Bike(type, age, totalDaysRented, totalRentalCost, regNumber, model, engineSize, noOfWheels, make);
				(Vehicle*)static_cast<Vehicle*>(bike);
				v.push_back(bike);
			}
			reader2.close();
		}
		
		else
		{
			std::cout << "Could not open the file." << std::endl;
		}

	
}

//used for creating new vehicles
void StockManager::AddStockToVector(std::vector<Vehicle*>& v)
{
	std::string regNumber;
	std::string model;
	char* make = (char*)malloc((sizeof(char) * 10));
	float cost(0.0);
	int age(0);
	int totalDaysRented = 0;
	float totalRentalCost = 0;

	int choice(0);
	std::cout << "add a vehicle:" << std::endl;
	std::cout << "______________" << std::endl;

	std::cout << "are you adding a bike or a car? " << std::endl << std::endl;
	std::cout << "1) car" << std::endl;
	std::cout << "2) bike" << std::endl;
	std::cout << "0) return to main menu" << std::endl;
	std::cin >> choice;

	//check if input is valid
	if (choice < 0 || choice > 2)
	{
		std::cout << "Invalid choice. Try again." << std::endl;
	}

	//choice == 1 and choice == 2 get values from the user

	//for a car
	if (choice == 1)
	{
		std::string type = "car";
		int noofdoors = 0;
		int noofseats = 0;

		std::cout << "car" << std::endl;

		std::cout << "registration number: ";
		std::cin >> regNumber;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "Note: Max character count: 10" << std::endl;
		std::cout << "\nMake: ";
		std::cin >> make; 
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nmodel: ";
		std::cin >> model;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nage: ";
		std::cin >> age;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nnumber of doors: ";
		std::cin >> noofdoors;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nnumber of seats: ";
		std::cin >> noofseats;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;

		//used to add the new vehicle made if there isnt a registration number that matches it
		bool alreadyexists = false;

		Car* newCar = new Car(type, age, totalDaysRented, totalRentalCost, regNumber, model, noofseats, noofdoors, make);

		//make sure there is not already a vehicle with that registration number
		for (int i = 0; i < v.size(); i++)
		{
			if (newCar->regNumber == v.at(i)->regNumber)
			{
				alreadyexists = true;
				std::cout << "there is already a vehicle with that registration number.";
				std::cout << "____________________________________________________________________" << std::endl;
				std::cout << "____________________________________________________________________" << std::endl;
				delete newCar;
				newCar = nullptr;

				free(make);
				make = nullptr;

				break;
			}
		}
		if (!alreadyexists)
		{
			v.push_back(newCar);
			std::cout << newCar->regNumber << ", " << newCar->make << " " << newCar->model << " added to stocklist." << std::endl;
			std::cout << "____________________________________________________________________" << std::endl;
			std::cout << "____________________________________________________________________" << std::endl;

			return;
		}

	}
	//for bikes
	else if (choice == 2)
	{
		int noOfWheels(0);
		int engineSize(0);
		std::string type = "bike";

		std::cout << "Bike" << std::endl;

		std::cout << "Registration Number: ";
		std::cin >> regNumber;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nMake: ";
		std::cin >> make;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nModel: ";
		std::cin >> model;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nage: ";
		std::cin >> age;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nNumber of Wheels: ";
		std::cin >> noOfWheels;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\nEngine size: ";
		std::cin >> engineSize;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		//cost = Car::calculateDailyCost(age, noOfDoors);

		bool alreadyExists = false;

		Bike* newBike = new Bike(type, age, totalDaysRented, totalRentalCost, regNumber, model, engineSize, noOfWheels, make);
		for (int i = 0; i < v.size(); i++)
		{
			if (newBike->regNumber == v.at(i)->regNumber)
			{
				alreadyExists = true;
				std::cout << "There is already a vehicle with that registration number.";
				std::cout << "____________________________________________________________________" << std::endl;
				std::cout << "____________________________________________________________________" << std::endl;
				delete newBike;
				newBike = nullptr;

				free(make);
				make = nullptr;

				break;
			}
		}
		//if no matching registration number is found, the vehicle is kept
		if (alreadyExists == false)
		{
			v.push_back(newBike);
			std::cout << newBike->regNumber << ", " << newBike->make << " " << newBike->model << " added to stocklist." << std::endl;
			std::cout << "____________________________________________________________________" << std::endl;
			std::cout << "____________________________________________________________________" << std::endl;
			return;
		}
		
	}
	else if (choice == 0)
	{
		return;
	}

}

//delete a selected vehicle
void StockManager::RemoveStockFromVector(std::vector<Vehicle*>& v)
{
	std::cout << "Remove A Vehicle" << std::endl;
	std::cout << "____________________________________________________________________" << std::endl;

	for (int i = 0; i < v.size(); i++)
	{
		//stop .eof() empty object being shown
		if (v.at(i)->type == "car" || v.at(i)->type == "bike")
		{
			int j = i + 1;
			std::cout << j << ")  ";

			if (v.at(i)->type == "car")
			{
				Car* c = static_cast<Car*>(v.at(i));
				std::cout << c->regNumber << "\t\t\t\x9C" << c->calculateCost() << "\t\t\t" << c->type << std::endl;
				std::cout << "____________________________________________________________________" << std::endl;
				c = nullptr;
			}
			else if (v.at(i)->type == "bike")
			{
				Bike* b = static_cast<Bike*>(v.at(i));
				std::cout << b->regNumber << "\t\t\t\x9C" << b->calculateCost() << "\t\t\t" << b->type << std::endl;
				std::cout << "____________________________________________________________________" << std::endl;
				b = nullptr;
			}

		}
	}
	int choice(0);
	std::cout << "Enter number to choose vehicle or 0 to return to main menu:  ";
	std::cin >> choice;

	if (choice == 0)
	{
		return;
	}
	if (choice != 0)
	{
		std::cout << std::endl << std::endl << v.at(choice - 1)->regNumber << ": " << v.at(choice - 1)->make <<
			", " << v.at(choice - 1)->model << std::endl;

		std::cout << "Are you sure you want to remove this vehicle?\n1) Yes\n2) No " << std::endl;

		int choiceToRemove = 0;
		std::cin >> choiceToRemove;
		if (choiceToRemove == 1)
		{
			std::string model = v.at(choice - 1)->model;
			const char* make = v.at(choice - 1)->make;
			std::string regNumber = v.at(choice - 1)->regNumber;

			delete(v.at(choice - 1));
			v.at(choice - 1) = nullptr;
			v.erase(v.begin() + (choice - 1));
			std::cout << regNumber << ", " << make << " " << model << " has been removed" << std::endl;
			
			return;
		}
		else if (choiceToRemove == 2)
		{
			return;
		}
		else
		{
			std::cout << "That wasn't a valid choice. Try Again.";
			return;
		}
	}
}

//save the updated vector of vehicles to files
void StockManager::WriteVehiclesOnExit(std::vector<Vehicle*>& v)
{
	//this clears the file so that any updates made to the stock can be saved
	std::ofstream writerCar;
	writerCar.open("CAR_STOCK.txt", std::ios::trunc);
	writerCar.clear();
	writerCar.close();

	std::ofstream writerBike;
	writerBike.open("BIKE_STOCK.txt", std::ios::trunc);
	writerBike.clear();
	writerBike.close();

	//writing to the files
	for (int i = 0; i < v.size(); i++)
	{

		if (v.at(i)->type == "car")
		{
			Car* c = static_cast<Car*>(v.at(i));
			writerCar.open("CAR_STOCK.txt", std::ios::app);
			writerCar << c;
			writerCar.close();
			
			c = nullptr;
		}
		else if (v.at(i)->type == "bike")
		{
			Bike* b = static_cast<Bike*>(v.at(i));
			writerBike.open("BIKE_STOCK.txt", std::ios::app);
			writerBike << b;
			writerBike.close();
			
			b = nullptr;
		}
	}
}


//displays vector of vehicles for the main menu
void StockManager::DisplayStock(std::vector<Vehicle*>& v)
{	
	if (v.size() > 0)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v.at(i)->type == "car" || v.at(i)->type == "bike")
			{
				std::cout << v.at(i)->regNumber << "\t\t\t\x9C" << v.at(i)->calculateCost() << "\t\t\t" << v.at(i)->type << std::endl;
				std::cout << "____________________________________________________________________" << std::endl;

			}
		}
	}
	else
	{
		std::cout << "There is currently no stock available." << std::endl;
	}
}


void StockManager::SortRegistration(std::vector<Vehicle*>& v)
{
	sort(v.begin(), v.end(), StockManager::orderByRegPlate);


	for (int i = 0; i < v.size(); i++)
	{
		//stop .eof() empty object being shown
		if (v.at(i)->type == "car" || v.at(i)->type == "bike")
		{
			int j = i + 1;
			std::cout << j << ")  ";	

			std::cout << v.at(i)->regNumber << "\t\t\t\x9C" << v.at(i)->calculateCost() << "\t\t\t" << v.at(i)->type << std::endl;
			std::cout << "____________________________________________________________________" << std::endl;

		}
	}
	int choice(0);
	std::cout << "Enter number to choose vehicle or 0 to return to main menu:  ";
	std::cin >> choice;

	if (choice == 0)
	{
		return;
	}
	if (choice != 0)
	{
		std::cout << std::endl << std::endl << v.at(choice - 1)->regNumber << ": ";
		std::cout << v.at(choice - 1)->make << ", ";
		std::cout << v.at(choice - 1)->model << std::endl;

		ShowVehicleDetails(v.at(choice - 1));

	}

}

void StockManager::SortCost(std::vector<Vehicle*>& v)
{
	//a lamba expression is used for this sort function
	std::sort(v.begin(), v.end(),
		[](Vehicle* lhs, Vehicle* rhs) 
		{
		return lhs->calculateCost() < rhs->calculateCost();
		});


	for (int i = 0; i < v.size(); i++)
	{
		//stop .eof() empty object being shown
		if (v.at(i)->type == "car" || v.at(i)->type == "bike")
		{
			int j = i + 1;
			std::cout << j << ")  ";

			std::cout << v.at(i)->regNumber << "\t\t\t\x9C" << v.at(i)->calculateCost() << "\t\t\t" << v.at(i)->type << std::endl;
			std::cout << "____________________________________________________________________" << std::endl;

		}
	}
	int choice(0);
	std::cout << "Enter number to choose vehicle or 0 to return to main menu:  ";
	std::cin >> choice;

	if (choice == 0)
	{
		return;
	}
	if (choice != 0)
	{
		std::cout << std::endl << std::endl << v.at(choice - 1)->regNumber << ": ";
		std::cout << v.at(choice - 1)->make << ", ";
		std::cout << v.at(choice - 1)->model << std::endl;

		ShowVehicleDetails(v.at(choice - 1));
	}
}

//display the VehicleHistory objects stored in VehicleHistory array
void StockManager::ShowVehicleDetails(Vehicle* V)
{
	int choice;

	std::cout << "_________________________________________________________________________________________________" << std::endl;
	std::cout << "Cost Per Day: \x9C" << V->calculateCost() << std::endl;
	std::cout << "Total Rental Income: \x9C" << V->totalRentalCost << std::endl;
	std::cout << "Total Days Rented: " << V->totalDaysRented << std::endl;
	std::cout << "1) Rent Vehicle" << std::endl;
	std::cout << "2) View Historic Details" << std::endl;
	std::cout << "0) Return to Main Menu" << std::endl << std::endl;
	std::cout << "Please Choose an Option: " << std::endl;

	std::cin >> choice;
	switch (choice)
	{
		case 1:
		{
			AddVehicleHistory(V);
			break;
		}
		case 2:
		{
			int size = 10;
			int index = 0;
			VehicleHistory* ArrayVH = new VehicleHistory[size];

			ReadVehicleHistory(V, ArrayVH, index);
			break;
		}
		case 0:
		{
			break;
		}

	}
}



//the following functions are used for the Vehicle history
void StockManager::AddVehicleHistory(Vehicle* V)
{
	//get the daily cost
	float cost = V->calculateCost();

	//create and fill in form
	VehicleHistory* newForm = new VehicleHistory();      // memory leak
	VehicleHistory::fillInForm(V, newForm, cost);

	//add to array
	int size = 10;
	int index = 0;
	VehicleHistory* ArrayVH = new VehicleHistory[size];
	ArrayVH[0] = *newForm;

	//update the details on the vehicle
	V->totalDaysRented += newForm->daysToRent;
	V->totalRentalCost += newForm->costForRent;

	ReadVehicleHistory(V, ArrayVH, 1);
	WriteVehicleHistory(newForm, V);

}

void StockManager::ReadVehicleHistory(Vehicle* V, VehicleHistory ArrayVH[], int index)
{
	string dateTo;
	string dateFrom;
	int daysToRent = 0;
	float costForRent = 0.0f;
	string name;
	string address;
	string number;

	int size = 10;

	std::ifstream reader("HISTORY\\" + V->regNumber + V->make + V->model + ".txt", std::ios::app);
	if (reader.is_open())
	{
		while (!reader.eof())
		{
			//if there are more than 15 VehicleHistory objects, resize the array;
			if (index == size - 1)
			{
				cout << "if block index == size - 1" << endl;
				size += 5;
				ArrayVH = (VehicleHistory*)realloc(ArrayVH, size * sizeof(VehicleHistory));
			}
			if (ArrayVH == NULL)
			{
				std::cout << "There was a problem getting the records" << std::endl;
			}
			
			reader >> ArrayVH[index].dateTo;
			reader >> ArrayVH[index].dateFrom;
			reader >> ArrayVH[index].daysToRent;
			reader >> ArrayVH[index].costForRent;
			reader >> ArrayVH[index].name;
			reader >> ArrayVH[index].address;
			reader >> ArrayVH[index].number;

			index++;
		}
		reader.close();
	}
	else
	{
		std::cout << "There was a problem getting the records." << endl;
	}
	ShowVehicleHistory(ArrayVH, index);
}

void StockManager::ShowVehicleHistory(VehicleHistory array[], int index)
{
	int i = 0;
	int choice(0);

	for (i; i < index; i++)
	{
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\t\t\t  Vehicle History" << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\t\t\tDate" << std::endl;
		std::cout << "From: " << array[i].dateFrom << std::endl;
		std::cout << "To: " << array[i].dateTo << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\t\t\tRental Details" << std::endl;
		std::cout << "Days Rented: " << array[i].daysToRent << std::endl;
		std::cout << "Cost: \x9C" << array[i].costForRent << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\t\t\tContact Details" << std::endl;
		std::cout << "Name: " << array[i].name << std::endl;
		std::cout << "Address: " << array[i].address << std::endl;
		std::cout << "Number: " << array[i].number << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "________________________________(" << (i + 1) << ")_________________________________" << std::endl;
		std::cout << "____________________________________________________________________" << std::endl;
		std::cout << "\t1) Next\t\t  2)Previous\t\t0)Exit" << std::endl;

		std::cin >> choice;
		
		//look through the records
		if (choice == 1)
		{
			if (i == index - 2)
			{
				std::cout << "********************************************************************" << std::endl;
				std::cout << "\t\t  there are no more records." << std::endl;
				std::cout << "********************************************************************" << std::endl;
				i -= 1;
			}
			if(i < index)
			{
				continue;
			}
			else
			{
				std::cout << "********************************************************************" << std::endl;
				std::cout << "\t\t  there are no more records available" << std::endl;;
				std::cout << "********************************************************************" << std::endl;
			}
		}
		if (choice == 2)
		{
			if (i > 0)
			{
				i -= 2;
			}
			else
			{
				std::cout << "********************************************************************" << std::endl;
				std::cout << "\t\t  this is the first file." << std::endl;
				std::cout << "********************************************************************" << std::endl;
				i -= 1;
			}
		}
		//this is where the array of VehicleHistory objects is deleted
		if (choice == 0)
		{
			delete[] array;
			return;
		}
		if(choice < 0 || choice > 2)
		{
			std::cout << "invalid choice. try again." << std::endl;
			i -= 1;
		}

	}
}

void StockManager::WriteVehicleHistory(VehicleHistory* VH, Vehicle* V)
{
	ofstream writer("HISTORY\\" + V->regNumber + V->make + V->model + ".txt", std::ios::app);
	writer << VH->dateTo << " ";
	writer << VH->dateFrom << " ";
	writer << VH->daysToRent << " ";
	writer << VH->costForRent << " ";
	writer << VH->name << " ";
	writer << VH->address << " ";
	writer << VH->number << "\n";

	writer.close();
	return;
}


//used for ordering the registration plates of the vehicles
bool StockManager::orderByRegPlate(const Vehicle* lhs, const Vehicle* rhs)
{
		return lhs->regNumber < rhs->regNumber;
}


//used when user chooses to exit. It will free the memory being used by the vehicles in the garage vector
void StockManager::cleanUp(std::vector<Vehicle*>& v)
{

	for (int i = 0; i < v.size(); i++)
	{
		delete(v.at(i));
		v.at(i) = nullptr;
	}
}


//the following functions are used to filter the cars
void StockManager::carSortRegistration(std::vector<Vehicle*>& v)
{
	//for holding the car objects
	vector<Car*> carsV;

	//used to check if any stock matching filter was found
	bool stockFound = false;

	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i)->type == "car")
		{
			Car* c;
			c = static_cast<Car*>(v.at(i));
			carsV.push_back(c);
		}
	}

	//make entered regNumber uppercase
	string searchRegistration;
	std::cout << "Enter a registration number: ";
	std::cin >> searchRegistration;
	transform(searchRegistration.begin(), searchRegistration.end(), searchRegistration.begin(), ::toupper);

	std::cout << "____________________________________________________________________" << endl;
	std::cout << "Registration Number:\tCost Per Day:\tMake:\t\tModel:" << endl << endl;
	std::cout << "____________________________________________________________________" << endl;

	for (int i = 0; i < carsV.size(); i++)
	{
		if (carsV.at(i)->regNumber == searchRegistration)
		{
			int j = i + 1;
			cout << j << ") " << carsV.at(i)->regNumber << "\t\t\x9C" << carsV.at(i)->calculateCost()  << "\t\t"
				<< carsV.at(i)->make << "\t\t" << carsV.at(i)->model << endl;
			std::cout << "____________________________________________________________________" << endl;
			stockFound = true;
		}
	}
	if (stockFound)
	{
		cout << endl;

		int choice;
		std::cout << "Enter number to choose the vehicle or 0 to return to main menu:  ";
		std::cin >> choice;

		cout << endl;

		if (choice == 0)
		{
			return;
		}
		if (choice != 0)
		{

			std::cout << endl << endl << carsV.at(choice - 1)->regNumber << ": " << carsV.at(choice - 1)->make <<
				", " << carsV.at(choice - 1)->model << endl;

			ShowVehicleDetails(carsV.at(choice - 1));

		}

		
	}
	else
	{
		std::cout << "The Registration number entered did not match any cars available." << endl;
	}
	for (int i = 0; i < carsV.size(); i++)
	{
		carsV.at(i) = nullptr;
	}
}

void StockManager::carFilterDoors(std::vector<Vehicle*>& v)
{
	vector<Car*> carsV;

	//used to check if any stock matching filter was found
	bool stockFound = false;

	int amount;
	std::cout << "Enter number of doors:  ";
	std::cout << "\nNote: The boot counts as a door.\n";

	std::cout << endl;
	std::cin >> amount;

	std::cout << "____________________________________________________________________" << endl;
	std::cout << "Registration Number:\tCost Per Day:\tMake:\t\tModel:" << endl << endl;
	std::cout << "____________________________________________________________________" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i)->type == "car")
		{
			Car* c;
			c = static_cast<Car*>(v.at(i));
			carsV.push_back(c);
		}
	}
	for (int i = 0; i < carsV.size(); i++)
	{
		if (carsV.at(i)->noOfDoors == amount)
		{
			int j = i + 1;
			cout << j << ") " << carsV.at(i)->regNumber << "\t\t\x9C" << carsV.at(i)->calculateCost() << "\t\t"
				<< carsV.at(i)->make << "\t\t" << carsV.at(i)->model << endl;
			std::cout << "____________________________________________________________________" << endl;
			stockFound = true;
		}
	}
	if (stockFound)
	{
		cout << endl;

		int choice;
		std::cout << "Enter number to choose vehicle or 0 to return to main menu:  ";
		std::cin >> choice;

		cout << endl;

		if (choice == 0)
		{
			return;
		}
		if (choice != 0)
		{
			std::cout << endl << endl << carsV.at(choice - 1)->regNumber << ": " << carsV.at(choice - 1)->make <<
				", " << carsV.at(choice - 1)->model << endl;

			ShowVehicleDetails(carsV.at(choice - 1));
		}

	}
	else if (!stockFound)
	{
		std::cout << "There are no matches currently for what you requested." << endl;
	}

}

void StockManager::carFilterSeats(std::vector<Vehicle*>& v)
{
	vector<Car*> carsV;

	//used to check if any stock matching filter was found
	bool stockFound = false;

	int amount;
	std::cout << "Enter number of seats:  ";

	std::cout << endl;
	std::cin >> amount;

	std::cout << "____________________________________________________________________" << endl;
	std::cout << "Registration Number:\tCost Per Day:\tMake:\t\tModel:" << endl << endl;
	std::cout << "____________________________________________________________________" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i)->type == "car")
		{
			Car* c;
			c = static_cast<Car*>(v.at(i));
			carsV.push_back(c);
		}
	}
	for (int i = 0; i < carsV.size(); i++)
	{
		if (carsV.at(i)->noOfSeats == amount)
		{
			int j = i + 1;
			cout << j << ") " << carsV.at(i)->regNumber << "\t\t\x9C" << carsV.at(i)->calculateCost() << "\t\t"
				<< carsV.at(i)->make << "\t\t" << carsV.at(i)->model << endl;
			std::cout << "____________________________________________________________________" << endl;
			stockFound = true;
		}
	}
	if (stockFound)
	{
		cout << endl;

		int choice;
		std::cout << "Enter number to choose vehicle or 0 to return to main menu:  ";
		std::cin >> choice;

		cout << endl;

		if (choice == 0)
		{
			return;
		}
		if (choice != 0)
		{
			std::cout << endl << endl << carsV.at(choice - 1)->regNumber << ": " << carsV.at(choice - 1)->make <<
				", " << carsV.at(choice - 1)->model << endl;

			ShowVehicleDetails(carsV.at(choice - 1));
		}

		
	}
	else if (!stockFound)
	{
		std::cout << "There are no matches currently for what you requested." << endl;
	}
}


//the following functions are used to filter the bikes
void StockManager::bikeSortRegistration(std::vector<Vehicle*>& v)
{
	//for holding the car objects
	vector<Bike*> bikesV;

	//used to check if any stock matching filter was found
	bool stockFound = false;

	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i)->type == "bike")
		{
			Bike* b;
			b = static_cast<Bike*>(v.at(i));
			bikesV.push_back(b);
		}
	}

	//make entered regNumber uppercase
	string searchRegistration;
	std::cout << "Enter a registration number: ";
	std::cin >> searchRegistration;
	transform(searchRegistration.begin(), searchRegistration.end(), searchRegistration.begin(), ::toupper);

	std::cout << "____________________________________________________________________" << endl;
	std::cout << "Registration Number:\tCost Per Day:\tMake:\t\tModel:" << endl << endl;
	std::cout << "____________________________________________________________________" << endl;

	for (int i = 0; i < bikesV.size(); i++)
	{
		if (bikesV.at(i)->regNumber == searchRegistration)
		{
			int j = i + 1;
			cout << j << ") " << bikesV.at(i)->regNumber << "\t\t\x9C" << bikesV.at(i)->calculateCost() << "\t\t"
				<< bikesV.at(i)->make << "\t\t" << bikesV.at(i)->model << endl;
			std::cout << "____________________________________________________________________" << endl;
			stockFound = true;
		}
	}
	if (stockFound)
	{
		cout << endl;

		int choice;
		std::cout << "Enter number to choose the vehicle or 0 to return to main menu:  ";
		std::cin >> choice;

		cout << endl;

		if (choice == 0)
		{
			return;
		}
		if (choice != 0)
		{
			std::cout << endl << endl << bikesV.at(choice - 1)->regNumber << ": " << bikesV.at(choice - 1)->make <<
				", " << bikesV.at(choice - 1)->model << endl;

			ShowVehicleDetails(bikesV.at(choice - 1));
		}
	}
	else
	{
		std::cout << "The Registration number entered did not match any bikes available." << endl;
	}
	for (int i = 0; i < bikesV.size(); i++)
	{
		bikesV.at(i) = nullptr;
	}
}

void StockManager::bikeFilterEngine(std::vector<Vehicle*>& v)
{
	vector<Bike*> bikesV;

	//used to check if any stock matching filter was found
	bool stockFound = false;

	int amount;
	std::cout << "Enter Max. Engine Size:  ";
	std::cin >> amount;
	std::cout << endl;

	std::cout << "____________________________________________________________________" << std::endl; 
	std::cout << "Registration Number:\tCost Per Day:\tMake:\t\tModel:" << std::endl << std::endl;
	std::cout << "____________________________________________________________________" << std::endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i)->type == "bike")
		{
			Bike* b;
			b = static_cast<Bike*>(v.at(i));
			bikesV.push_back(b);
		}
	}
	for (int i = 0; i < bikesV.size(); i++)
	{
		if (bikesV.at(i)->engineSize <= amount)
		{
			int j = i + 1;
			cout << j << ") " << bikesV.at(i)->regNumber << "\t\t\x9C" << bikesV.at(i)->calculateCost() << "\t\t"
				<< bikesV.at(i)->make << "\t\t" << bikesV.at(i)->model << endl;
			std::cout << "____________________________________________________________________" << endl;
			stockFound = true;
		}
	}
	if (stockFound)
	{
		cout << endl;

		int choice;
		std::cout << "Enter number to choose vehicle or 0 to return to main menu:  ";
		std::cin >> choice;

		cout << endl;

		if (choice == 0)
		{
			return;
		}
		if (choice != 0)
		{
			std::cout << endl << endl << bikesV.at(choice - 1)->regNumber << ": " << bikesV.at(choice - 1)->make <<
				", " << bikesV.at(choice - 1)->model << endl;

			ShowVehicleDetails(bikesV.at(choice - 1));
		}
	}
	else if (!stockFound)
	{
		std::cout << "There are no matches currently for what you requested." << endl;
	}
	for (int i = 0; i < bikesV.size(); i++)
	{

		bikesV.at(i) = nullptr;
	}
}

void StockManager::bikeFilterWheels(std::vector<Vehicle*>& v)
{
	vector<Bike*> bikesV;

	//used to check if any stock matching filter was found
	bool stockFound = false;

	int amount;
	std::cout << "Enter How Many Wheels:  ";

	std::cout << endl;
	std::cin >> amount;

	std::cout << "____________________________________________________________________" << endl;
	std::cout << "Registration Number:\tCost Per Day:\tMake:\t\tModel:" << endl << endl;
	std::cout << "____________________________________________________________________" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i)->type == "bike")
		{
			Bike* b;
			
			b = static_cast<Bike*>(v.at(i));
			bikesV.push_back(b);
		}
	}
	for (int i = 0; i < bikesV.size(); i++)
	{
		if (bikesV.at(i)->noOfWheels == amount)
		{
			int j = i + 1;
			cout << j << ") " << bikesV.at(i)->regNumber << "\t\t\x9C" << bikesV.at(i)->calculateCost() << "\t\t"
				<< bikesV.at(i)->make << "\t\t" << bikesV.at(i)->model << endl;
			std::cout << "____________________________________________________________________" << endl;
			stockFound = true;
		}
	}
	if (stockFound)
	{
		cout << endl;

		int choice;
		std::cout << "Enter number to choose vehicle or 0 to return to main menu:  ";
		std::cin >> choice;

		cout << endl;

		if (choice == 0)
		{
			return;
		}
		if (choice != 0)
		{
			std::cout << endl << endl << bikesV.at(choice - 1)->regNumber << ": " << bikesV.at(choice - 1)->make <<
				", " << bikesV.at(choice - 1)->model << endl;

			ShowVehicleDetails(bikesV.at(choice - 1));
		}

	
	}
	else if (!stockFound)
	{
		std::cout << "There are no matches currently for what you requested." << endl;
	}
	for (int i = 0; i < bikesV.size(); i++)
	{
		bikesV.at(i) = nullptr;
	}
}



