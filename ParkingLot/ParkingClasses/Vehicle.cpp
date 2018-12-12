/*
 * Vehicle.cpp
 * Name: Sailesh Sriram
 * Section: CS 2336-001
 * Definition: This implementation file implements the methods in the vehicle header file.
 */
#include "Vehicle.h"
#include<string>
#include<iostream>
using namespace std;

Vehicle::Vehicle()
{
	//Creates Vehicle object
}
Vehicle::~Vehicle()
{
	//Destroys Vehicle object once object goes out of scope
}
//Return Type: string
//Parameters: none
//Description: Standardizes method for subclasses to override
 string Vehicle:: toString()
{
	 //Returns in string format the first letter of the type of vehicle when an instance of this class is made
	return "V";
}





