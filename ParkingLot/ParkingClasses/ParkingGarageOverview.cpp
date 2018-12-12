/*
 * ParkingGarageOverview.cpp
 * Name: Sailesh Sriram
 * Class Section: CS 2336-001
 * Analysis: To create a parking garage for vehicles of the type motorcycle, bus, and car.
 * The parking lot or parking garage can add and remove vehicles based on the availability of spots and the number of vehicles.
 * Design:
 *     1. Create a superclass Vehicle
 *     2. Create three derived classes, Car, Motorcycle,and Bus, which extend Vehicle and have a public myAccessSpecifier with Vehicle
 *     3. Vehicle class has toString method that indicates what type of vehilcle it is. The method is overriden by the toString method in Car, Motorcycle, and Bus.
 *     4. The ParkingLot class has an aggregation (composition) relationsip with Vehicle and its subclasses. This is shown as follows.
 *     5. The add and remove method of the ParkingLot class accepts a Vehicle pointer
 *     6. The ParkingLot class has a 2D string array
 *     7. The ParkingLot class has default values as to how many spots are reserved for motorcycles, buses, and cars
 *     7. The array keeps track of the rows and columns of the parking lot, which are by default five by thirty
 *     8. The add accesses the toString() method of the Vehicles through the arrow operator -> since they only accept a pointer to the vehicles and adds them to the array
 *     9. The remove method does the same but removes the first Vehicle based on the parameter's toString() method
 *     10. The ParkingLot also checks to see whether the parkingLot is entirely full of vehicle
 *  Assumptions:
 *     1. The program will continue to run even if a vehicle of a certain type cannot be added anymore.
 *     The program will render a message saying that the vehicle of that type cannot be added anymore but the program does not terminate like when no vehicles can be added.
 *     2. The user can also only add vehicles of the type motorcycle, bus, and car.
 *
 *
 */




