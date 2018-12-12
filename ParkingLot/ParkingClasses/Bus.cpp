/*
 * Bus.cpp
 * Name: Sailesh Sriram
 * Section: CS 2336-001
 * Definition: This implementation file implements the methods in the bus header file.
 */
#include "Bus.h"
#include<string>
#include<iostream>
using namespace std;

Bus::Bus()
{
	//Creates a bus object
}
Bus::~Bus()
{
	//Destroys a bus object once it goes out of scope
}
//Return Type: string
//Parameters: none
//Description: Overrides the vehicle's superclass toString() method
string Bus::toString()
{
	//Returns in string format the first letter of the type of vehicle when an instance of this class is made
	return "B";
}



