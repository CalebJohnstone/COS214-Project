#ifndef DEPARTMENTOUTPUT_H
#define DEPARTMENTOUTPUT_H

#include "Car/Car.h"
#include <string>
#include <iostream>

using namespace std;
/**
 * Pattern: Factory Method. A class DepartmentOutput Decorator partcipant of the decorator design pattern,concreteHandler of the chain of responsibilities design pattern,Product of the factory method design pattern
 * This is the Product participant and the ConcreteProduct participants are Aerodynamics, Electronics, Engine and Chassis.
 * @headerfile DepartmentOutput.h "Car/Parts/DepartmentOutput.h"
 */
class DepartmentOutput : public Car {
protected:
    int speed;/*! @var protected attribute speed of part */
    string type;/*! @var protected attribute the name of the type of part*/
    Car *next;/*! @var protected attribute points to the component of the decorator design pattern*/
public:
    /**
     *Constructor creates a departmentoutput object
     */
    DepartmentOutput();

/**
 *Destructor to deallocate the next pointers
 */
    virtual ~DepartmentOutput();

/**
 *Return the calculated speed calculated by running throught he list of decorators and adding all their speeds
 * @return int speed
 */
    int calculateSpeed();

/**
 *Add a new part to the list of decorators
 * @param part
 */
    void addPart(Car *part);

/**
 *Remove a part from list of decorators may not remove a current or next season car, Removed by specifying part for removal
 * @param part
 * @return The car object at front of decorator list
 */
    Car *removePart(string part);

/**
 *Returns type of part
 * @return string
 */
    string getType();

/**
 *Returns next decorator in list
 * @return Car pointer
 */
    Car* getNext();

/**
 *Return parts speed
 * @return int speed
 */
    virtual int getSpeed();

/**
 *Clone the part and return new cloned part
 * @return Car pointer
 */
    virtual Car *clone() = 0;

/**
 *set the raceTime of the car, handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @param rt
 */
    void setRaceTime(int rt);

/**
 *Increase the racetime by rt,handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @param rt
 */
    void incrementRaceTime(int rt);

/**
 *Return the raceTime of the car,handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @return
 */
    int getRaceTime();

/**
 *Set the driver of the car,handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @param d
 */
    void setDriver(Driver *d);

/**
 *Get the points from the driver of the car,handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @return int points
 */
    int getPoints();

/**
 *Add points to the driver of the car, handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @param p
 */
    void addPoints(int p);

/**
 *Help the driver increase performance,handle request method of chain of responisibility to get to the currentseason car to handle the request
 */
    void simulate();

/**
 *Get the drivers name,handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @return string name
 */
    string getDriverName();

/**
 *Add an array of tyres to the car,handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @param t Tyres to be added
 * @param num Number of tyres added
 */
    void addTyres(Tyre **t, int num);

/**
 *Remove the current tyre from queue
 */
    void popOldTyre();

/**
 *Return the current tyre without removing it from queue
 * @return Tyre pointer
 */
    Tyre *currentTyre();

};

#endif
