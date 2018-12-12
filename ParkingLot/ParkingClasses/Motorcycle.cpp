/*
 * Motorcycle.cpp
 * Name: Sailesh Sriram
 * Section: CS 2336-001
 * Definition: Implementation of the motorcycle header file methods
 */

#include "Motorcycle.h"
#include<string>
#include<iostream>
using namespace std;

Motorcycle::Motorcycle()
{
	//Creates a motorcycle object
}
Motorcycle::~Motorcycle()
{
	//Destroys a motorcycle object when it goes out of scope
}
//Return Type: string
//Parameters: none
//Description: Overrides the vehicle's superclass toString() method
string Motorcycle::toString()
{
	//Returns in string format the first letter of the type of vehicle when an instance of this class is made
	return "M";
}


