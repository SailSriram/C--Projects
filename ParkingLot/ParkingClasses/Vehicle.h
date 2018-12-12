/*
 * Vehicle.h
 * Name: Sailesh Sriram
 * Section: CS 2336-001
 * Definition: The vehicle class is a superclass, which has three subclasses: Bus, Car, and Motorcycle.
   Any type of vehicle can park in a parking lot based on the availability of spaces.
   The vehicle has a constructor, destructor, and a toString() method that returns what type of vehicle is parking in a parking space.
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include<iostream>
#include<string>

using namespace std;

class Vehicle
{
	public:
		Vehicle();
		virtual ~Vehicle();
		virtual string toString();

};




#endif /* VEHICLE_H_ */
