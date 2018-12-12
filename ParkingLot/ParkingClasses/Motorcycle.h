/*
 * Motorcycle.h
 * Name: Sailesh Sriram
 * Class Section: CS 2336-001
 * Definition: This header file defines the motorcycle class, which extends from the Vehicle superclass.
   The car class has a constructor and destructor and it overrides the Vehicle's class toString() method.
 *
 *
 */

#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_
#include<string>
#include "Vehicle.h"
#include<iostream>
using namespace std;
class Motorcycle : public Vehicle
{
	public:
	Motorcycle();
	~Motorcycle();
	string toString() override;

};





#endif /* MOTORCYCLE_H_ */
