/*
 * Car.h
 * Name: Sailesh Sriram
 * Class Section: CS 2336-001
 * Definition: This header file defines the car class, which extends from the Vehicle superclass.
   The car class has a constructor and destructor and it overrides the Vehicle's class toString() method.
 */


#ifndef CAR_H_
#define CAR_H_
#include<string>
#include "Vehicle.h"
#include<iostream>
using namespace std;
class Car : public Vehicle
{
	public:
	Car();
	 ~Car();
	string toString() override;
};




#endif /* CAR_H_ */
