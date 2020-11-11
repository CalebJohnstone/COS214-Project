#ifndef NEXTSEASON_H
#define NEXTSEASON_H

#include "Car/Car.h"

using namespace std;

/**
 * @class A class NextSeason which inherits publicly from class Car and is a concreteComponent of the Decorator pattern,Concrete handler in chain of responisibility design pattern
 * @headerfile NextSeason.h "Car/NextSeason/NextSeason.h"
 */
class NextSeason : public Car {
public:
    /**
     * A constructor for the nextSeason object
     */
    NextSeason();

/**
 * Clones the object and all its varaibles
 * @return a car object
 */
    Car *clone();

/**
 * Function that returnsthe type used by add and remove in decorator
 * @return the type which is "base"
 */
    string getType();
};

#endif