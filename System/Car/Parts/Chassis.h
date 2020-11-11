#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>
#include "Car/Parts/DepartmentOutput.h"
#include "Car/Car.h"

using namespace std;

/**
 * A class Aerodynamics that is a concreteDecorator of the decorator design pattern,concreteProduct of the Factory method
 * @headerfile Chassis.h "Car/Parts/Chassis.h"
 */
class Chassis : public DepartmentOutput {
public:
    /**
     *Constructor to create a Chassis object
     */
    Chassis();

/**
 *Helper function used by clone
 * @return Chassis pointer
 */
    Chassis *cpy();

/**
 *Returns the objects speed
 * @return int the speed
 */
    int getSpeed();

/**
 *Clone function to copy and create a new Car object to match the current chassis attributes,method of the prototype design pattern
 * @return A Chassis object
 */
    Car *clone();

};

#endif
