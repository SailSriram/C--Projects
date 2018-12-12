/*
 * ParkingLot.cpp
 * Name: Sailesh Sriram
 * Section: CS 2336-001
 * Description: The ParkingLot class has a constructor and destructor. The constructor creates the parking lot while the destructor destroys it.
 Parking Class has a has-a relationship with the subclasses of vehicle class.
 Its operations are adding and removing a bus, car, or motorcycle.
 The parking lot class also can print out the current state of the parking lot.
 */
#include "Vehicle.h"
#include<string>
#include<iostream>
using namespace std;

class ParkingLot
{
	private:
	 //Variable parkingLotFull determines whether or not parking lot can add any more vehicles
	 int parkingLotFull;
	 //number of rows in parking lot
	 const int NUM_OF_ROWS=5;
	 //number of columns in parking lot
	 const int NUM_OF_COL=30;
	 //2d array that stores the vehicle objects
	 string parkingLot[5][30];
	 //INDEX_OF_FIRST_BUS_SPOT variable specifies the index of the first of the five spots a bus takes up in each row
	 const int INDEX_OF_FIRST_BUS_SPOT=0;
	 //INDEX_OF_LAST_BUS_SPOT variable specifies the index of the last of the five spots a bus takes up in each row
	 const int INDEX_OF_LAST_BUS_SPOT=5;
	// INDEX_OF_FIRST_MOTORCYCLE_SPOT variable specifies the index of the first spot where a motorcycle can park
	 const int INDEX_OF_FIRST_MOTORCYCLE_SPOT=24;
	 // INDEX_OF_LAST_MOTORCYCLE_SPOT variable specifies the index of the last spot where a motorcycle can park
	 const int INDEX_OF_LAST_MOTORCYCLE_SPOT=29;

	public:

	ParkingLot()
	{
		//Constructor creates the parking lot
		parkingLotFull=0;
		for (int i=0; i < NUM_OF_ROWS; i++)
		{

			for (int j=0; j < NUM_OF_COL; j++)
			{
				//First six spots in each row are large spots
				if (j >= INDEX_OF_FIRST_BUS_SPOT && j <= INDEX_OF_LAST_BUS_SPOT)
				{
					parkingLot[i][j]="l";
				}
				//Last six spots in each row are reserved for only motorcycles
				else if (j >= INDEX_OF_FIRST_MOTORCYCLE_SPOT && j <= INDEX_OF_LAST_MOTORCYCLE_SPOT)
				{
					parkingLot[i][j]="m";
				}
				//Rest of the spots are for cars and possibly, motorcycles
				else
				{
					parkingLot[i][j]="c";
				}
			}
		}
		cout << endl;
	}
	~ParkingLot()
	{

		//Destroys ParkingLot object once object goes out of scope
	}
	//Return type: void
	//Parameters: Pointer to vehicle object
	//Description: Adds vehicle to parkingLot by finding open spots for new vehicles going to be added
	void add(Vehicle *v)
	{
			//variable breakPoint is an indicator of when to break the loop once vehicle has been added to parkinglot
			int breakPoint=0;
			for (int i=0; i < NUM_OF_ROWS; i++)
			{

				for (int j=0; j < NUM_OF_COL; j++)
				{
					//A car can park in a compact spot
					if (parkingLot[i][j]=="c" && v->toString()=="C")
					{
						cout << "Parking a Car";
						cout << endl;
						parkingLot[i][j]="C";
						breakPoint=1;
						break;
					}
					//A car can also park in a large spot
					else if (parkingLot[i][j]=="l" && v->toString()=="C")
					{
						cout << "Parking a Car";
						cout << endl;
						parkingLot[i][j]="C";
						breakPoint=1;
						break;
					}
					//A motorcycle can park in a compact spot
					else if (parkingLot[i][j]=="c" && v->toString()=="M")
					{
						cout << "Parking a Motorcycle";
						cout << endl;
						parkingLot[i][j]="M";
						breakPoint=1;
						break;
					}
					//A motorcycle can park in a small spot
					else if (parkingLot[i][j]=="m" && v->toString()=="M")
					{
						cout << "Parking a Motorcycle";
						cout << endl;
						parkingLot[i][j]="M";
						breakPoint=1;
						break;
					}
					//A motorcycle can park in a large spot
					else if (parkingLot[i][j]=="l" && v->toString()=="M")
					{
							cout << "Parking a Motorcycle";
							cout << endl;
							parkingLot[i][j]="M";
							breakPoint=1;
							break;
					}
					//A bus can only park in a large spot
					else if (parkingLot[i][j]=="l" && v->toString()=="B")
					{
							//Puts bus in first five spots in a row if spots are available
							if (j== INDEX_OF_FIRST_BUS_SPOT)
							{
								cout << "Parking a Bus";
								cout << endl;
								for (int k=0; k < INDEX_OF_LAST_BUS_SPOT; k++)
								{
									parkingLot[i][k]="B";
								}
								breakPoint=1;
							}

					}


				}
				//Breaks loop once vehicle is added
				if (breakPoint==1)
				{
					break;
				}
			}
			//Renders error message if vehicle cannot be added
			if (breakPoint==0)
			{

				cout << ("Parking failed.");
				cout << endl;
				if (isParkingLotFullOfVehicles()==true)
				{
					parkingLotFull=1;
					cout << "Final state" << endl;
				}
				else
				{
					parkingLotFull=0;
					cout << "Cannot park this vehicle. Park any other vehicle" << endl;
				}

			}

	}
	//Return type: boolean
	//Parameters: None
	//Description: Checks if parking lot is full and vehicle cannot be added anymore
	bool isParkingLotFullOfVehicles()
	{
		//An indicator for an empty spot
		bool isEmptySpot=false;
		for (int i=0; i < NUM_OF_ROWS; i++)
		{
			for (int j=0; j < NUM_OF_COL; j++)
			{
				if (parkingLot[i][j]!="C" && parkingLot[i][j]!="M" && parkingLot[i][j]!="B")
				{
					//Breaks loop once empty spot is found
					isEmptySpot=true;
					break;
				}
			}
		}
		//Return false if empty spot is found and true if not
		if (isEmptySpot==true)
		{
			return false;
		}
		return true;
	}
	//Return type: void
	//Parameters: Pointer to vehicle object
	//Description: Removes vehicle from parking lot
	void remove(Vehicle *v)
	{
		//variable breakPoint is an indicator of when to break the loop once a vehicle has been found to be removed from parkinglot
		int breakPoint=0;
		for (int i=0; i < NUM_OF_ROWS; i++)
		{

			for (int j=0; j < NUM_OF_COL; j++)
			{
				//Removes car parked in first five spots in a row which are large spots
				if (parkingLot[i][j]=="C" && v->toString()=="C" && j >= INDEX_OF_FIRST_BUS_SPOT && j <= INDEX_OF_LAST_BUS_SPOT)
				{
					cout << "Removing a Car";
					cout << endl;
					parkingLot[i][j]="l";
					breakPoint=1;
					break;
				}
				//Removes car parked in compact spots
				else if (parkingLot[i][j]=="C" && v->toString()=="C" && j>= (INDEX_OF_LAST_BUS_SPOT + 1) && j <= (INDEX_OF_FIRST_MOTORCYCLE_SPOT - 1))
				{
					cout << "Removing a Car";
					cout << endl;
					parkingLot[i][j]="c";
					breakPoint=1;
					break;
				}
				//Removes motorcycle parked in large spots
				else if (parkingLot[i][j]=="M" && v->toString()=="M" && j>= INDEX_OF_FIRST_BUS_SPOT && j <= INDEX_OF_LAST_BUS_SPOT)
				{
					cout << "Removing a Motorcycle";
					cout << endl;
					parkingLot[i][j]="l";
					breakPoint=1;
					break;
				}
				//Removes motorcycles parked in compact spots
				else if (parkingLot[i][j]=="M" && v->toString()=="M" && j>= (INDEX_OF_LAST_BUS_SPOT + 1) && j <= (INDEX_OF_FIRST_MOTORCYCLE_SPOT - 1))
				{
					cout << "Removing a Motorcycle";
					cout << endl;
					parkingLot[i][j]="c";
					breakPoint=1;
					break;
				}
				//Removes motorcycle parked in small spots designated for motorcycles
				else if (parkingLot[i][j]=="M" && v->toString()=="M" && j>= (INDEX_OF_FIRST_MOTORCYCLE_SPOT) && j <= (INDEX_OF_LAST_MOTORCYCLE_SPOT))
				{
					cout << "Removing a Motorcycle";
					cout << endl;
					parkingLot[i][j]="m";
					breakPoint=1;
					//Breaks inner loop once vehicle has been added
					break;
				}
				//Removes buses parked in first five spots in a row
				else if (parkingLot[i][j]=="B" && v->toString()=="B" && j== INDEX_OF_FIRST_BUS_SPOT)
				{
					cout << "Removing a Bus";
					cout << endl;
					//Changes values at spots in array back to l to indicate spots are empty
					for (int k=0; k < INDEX_OF_LAST_BUS_SPOT; k++)
					{
						parkingLot[i][k]="l";
					}
					breakPoint=1;
					break;
				}

			}
			//Breaks outerloop so other spots are not checked for availability
			if (breakPoint==1)
			{
				break;
			}
		}
		//Renders error message when no vehicle of parameter type can be removed
		if (breakPoint==0)
		{
			cout << "No vehicles of that type can be removed";
			cout << endl;
		}
	}
	//Return type: void
	//Parameters: None
	//Description: Displays parking lot
	void toString()
	{
		for (int i=0; i < NUM_OF_ROWS; i++)
		{
			cout << "Level" + to_string(i+1) + ": ";
			//cout << endl;
			for (int j=0; j < NUM_OF_COL; j++)
			{
				//Adds spacing at index 9 and 19 for display
				if (j==9 || j==19)
				{
					cout << parkingLot[i][j] + " ";
				}
				else
				{
					cout << parkingLot[i][j];
				}

			}
			cout << endl;
		}
	}
	//Return Type: int
	//Parameters: none
	//Description: Indicates when parking lot is full and no vehicles of only a certain type can be added
	int isParkingLotFull()
	{
		return parkingLotFull;
	}





};



