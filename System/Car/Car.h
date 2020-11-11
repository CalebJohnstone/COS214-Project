#ifndef CAR_H
#define CAR_H

#include "Car/CurrentSeason/Driver.h"
#include "Car/CurrentSeason/Tyre/Tyre.h"

using namespace std;
/**
 * Class Car creates abstract Car object is the component in the Decorator pattern, prototype in Prototype design pattern,Product in Factory method design pattern,Handler in chain of responsibility design pattern
 * @headerfile Car.h "Car/Car.h"
 */
class Car {
protected:
   // int averageSpeed; /*! @var a protected varaible that holds the cars average speed */

public:
    /**
     * The constructor for the car class
     */
    Car();

/**
 * The destructor for the car class
 */
    virtual ~Car();

/**
 * Base class returns the points from its driver object, if not base class chain of responsibility goes down chain till it finds base
 * @return the points
 */
    virtual int getPoints();

/**
 * Goes down chain till it finds a current season car to handle request of adding points to driver object
 * @param p points to be added
 */
    virtual void addPoints(int p);

/**
 * adds a new part to the decorator and chain
 * @param part
 */
    virtual void addPart(Car *part);

/**
 *Add all the speeds added together of all the components of decorator design pattern
 * @return the total speed of all decorated parts
 */
    virtual int calculateSpeed();

/**
 * Clone the part and return new cloned part
 * @return Car pointer
 */
    virtual Car *clone() = 0;

/**
 * Run a simulation to possibly increase the performance of the car by 1 with a 10% chance.
 */
    virtual void simulate();

/**
 *set the raceTime of the car, handle request method of chain of responisibility to get to the currentseason car to handle the request
 */
    virtual void setRaceTime(int);        // raceTime = param
    /**
     Increase the racetime by rt,handle request method of chain of responisibility to get to the currentseason car to handle the request
    * @param rt
     */
    virtual void incrementRaceTime(int);    //raceTime += param
    /**
     *
     * @return
     */
    virtual int getRaceTime();

/**
 *
 * @return
 */
    virtual string getDriverName();

/**
 *Set the driver of the car,handle request method of chain of responisibility to get to the currentseason car to handle the request
 * @param d the driver
 */
    virtual void setDriver(Driver *d);

/**
 *
 * @return The type which is "base".
 */
    virtual string getType() = 0;

/**
 *
 * @param part The type of part to remove from the car
 * @return The entry point to the decorated car
 */
    virtual Car* removePart(string part);

/**
 * Function to add an array of tyre pointers to the tyre queue
 * @param t the tyre array to add to the tyre queue
 * @param num the number of tyres to add
 */
    virtual void addTyres(Tyre **t, int num);

/**
 * Function to change the tyre by popping the tyre at the front of the queue
 */
    virtual void popOldTyre();

/**
 *Return current tyre without removing it from the queue
 * @return tyre pointer
 */
    virtual Tyre *currentTyre();

/**
 *Return speed of the car
 * @return int speed
 */
    virtual int getSpeed();


};

#endif
