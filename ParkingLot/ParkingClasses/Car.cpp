/*
 * Car.cpp
 * Name: Sailesh Sriram
 * Section: CS 2336-001
 * Definition: This implementation file implements the methods in the car header file.
 */
#include "Car.h"
#include<string>
#include<iostream>
using namespace std;


Car::Car()
{
	//Creates a car object
}
Car::~Car()
{
	//Destroys a car object that goes out of scope
}
//Return Type: string
//Parameters: none
//Description: Overrides the vehicle's superclass toString() method
string Car::toString()
{
	//Returns in string format the first letter of the type of vehicle when an instance of this class is made
	return "C";
}





