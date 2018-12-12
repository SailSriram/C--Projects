/*
 * Runner.cpp
 *
 *  Created on: Nov 8, 2018
 *      Author: sass2
 */
#include "ParkingLot.cpp"
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorcycle.h"
#include <string>

/*
 Documentation: The runner class allows the user to interact with a virtual UTD parking lot.
  The user has the ability to park and remove a vehicle while also can see the current state
  of the parking lot. The user can park a vehicle by typing b for bus, c for car, or m for motorcycle.
  The user can also remove by pressing r and specifying whether they want to remove a bus, car,
  or motorcycle. If the user wants to get out of the parking lot, he or she can press d for done. Any other input
  is disregarded by the system and the user is asked again whether or not he wants to park or remove. The user can add
  how many ever vehicles they want to add until the parking lot gets full.
 */
int main()
{
	ParkingLot p;
	//Input is the unformatted user input
	string input;
	string secondInput;
	//Vehicle and removeVehicle are formatted user inputs in selecting the type of vehicle to be added or removed
	char vehicle;
	char removeVehicle;
	cout << "Hello user. Welcome to the UTD parking lot.";
	cout << endl;
	p.toString();
	cout << endl;

	//Verifies to see if parking lot is not full to perform add and remove operations
	while (p.isParkingLotFull()!=1)
	{

		cout << "To park,type b for bus, c for car, m for motorcycle, or d for done. To remove a vehicle, press r";
		cout << endl;
		cin >> input;
		//Checks to see if input is valid
		if (input.length()== 1)
		{
			vehicle=input.at(0);
			//Creates a Bus pointer that is added to the parking lot and then deleted to ensure unecessary use of memory
			if (toupper(vehicle)==toupper('b'))
			{
				Bus *b=new Bus();
				p.add(b);
				p.toString();
				cout << endl;
				delete b;
			}
			//Creates a car pointer that is added to the parking lot (Like bus)
			else if (toupper(vehicle)==toupper('c'))
			{
				Car *c=new Car();
				p.add(c);
				p.toString();
				cout << endl;
				delete c;

			}
			//Creates a motorcycle pointer that is added to the parking lot
			else if (toupper(vehicle)==toupper('m'))
			{
				Motorcycle *m=new Motorcycle();
				p.add(m);
				p.toString();
				cout << endl;
				delete m;
			}
			//Case where user wants to remove a vehicle
			else if (toupper(vehicle)==toupper('r'))
			{

				cout << "Type b for bus, c for car, m for motorcycle, or d for done.";
				cout << endl;
				cin >> secondInput;
				//Checks to see if string is only one character before performing the remove operation
				if (secondInput.length()==1)
				{
					removeVehicle=secondInput.at(0);
					//Creates bus pointer and removes first vehicle that is a bus in parking lot
					if (toupper(removeVehicle)==toupper('b'))
					{
						Bus *b=new Bus();
						p.remove(b);
						p.toString();
						cout << endl;
						delete b;
					}
					else if (toupper(removeVehicle)==toupper('c'))
					{
						//Creates car pointer and removes first vehicle that is a car in parking lot
						Car *c=new Car();
						p.remove(c);
						p.toString();
						cout << endl;
						delete c;

					}
					else if (toupper(removeVehicle)==toupper('m'))
					{
						//Creates motorcyle pointer and removes first vehicle that is a motorcycle in parking lot
						Motorcycle *m=new Motorcycle();
						p.remove(m);
						p.toString();
						cout << endl;
						delete m;
					}
					else if (toupper(removeVehicle)==toupper('d'))
					{
						//Stops adding and removing vehicles when user presses d for done
						break;
					}

				}
				else
				{
					cout << "Input is not correct. Please specify if you want to park or remove a vehicle." << endl;

				}


			}
			//Breaks loop when user presses d for done
			else if (toupper(vehicle)==toupper('d'))
			{
				break;
			}
			//Asks user to enter input if user enters a char that is not r, d, m, b, or c
			else
			{
				cout << "This input is not correct. ";
				cout << "Please enter input again" << endl;
			}
		}
		//Asks user to enter input is length of string is not equal to one, indicating it is a wrong input
		else
		{
			cout << "This input is not correct. ";
			cout << "Please enter input again" << endl;
		}


	}
	//Terminates program once user is done
	if (toupper(vehicle)==toupper('d') || toupper(removeVehicle)==toupper('d'))
	{
		cout << "Thank you for parking in the UTD parking lot";
		cout << endl;
		return 1;
	}
	cout << endl;






	return 0;
}



