#ifndef AERODYNAMICS_H
#define AERODYNAMICS_H

#include <string>
#include "Car/Parts/DepartmentOutput.h"
#include "Car/Car.h"

using namespace std;
/**
 * A class Aerodynamics that is a concreteDecorator of the decorator design pattern,concreteProduct of the Factory method
 * @headerfile Aerodynamics.h "Car/Parts/Aerodynamics.h"
 */
class Aerodynamics : public DepartmentOutput {

public:
    /**
     *Constructor to create an Aerodynamics object
     */
    Aerodynamics();

/**
 *Helper function used in cloning
 * @return Aerodynamics pointer
 */
    Aerodynamics *cpy();

/**
 *Returns the speed of an Aerodynamics object
 * @return int the speed
 */
    int getSpeed();

/**
 *Clones the objects variables
 * @return a Aerodynamics object
 * method of the prototype design pattern
 */
    Car *clone();

};

#endif