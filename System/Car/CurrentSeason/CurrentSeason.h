
#ifndef CURRENTSEASON_H
#define CURRENTSEASON_H

#include "Car/Car.h"
#include "Car/CurrentSeason/Tyre/Tyre.h"
#include "Car/CurrentSeason/Driver.h"
#include <queue>

using namespace std;

/**
 * @class  A class CurrentSeason the inherits publically from car and is the concrete component of the decorator design pattern,Concrete handler in chain of responisibility design pattern
 * @headerfile CurrentSeason.h "Car/CurrentSeason/CurrentSeason.h"
 */
class CurrentSeason : public Car {
private:
    int raceTime; /*! @var private variable the holds the cars current raceTime   */
    queue<Tyre *> tyres; /*! @var private variable that is a queue that holds the cars tyre pointers */
    Driver *driver; /*! @var private variable that holds the driver pointer of the car */
public:
    /**
     * Constructor for a CurrentSeason car
     * @param name The name of the driver for the team
     */
    CurrentSeason(string name);

/**
 * Function to add the points to the driver of the car
 * @param p The points to be added
 */
    void addPoints(int p);

/**
 * Function that lets the drivers gain experience
 */
    void simulate();

/**
 * Function to get the drivers points
 * @return returns the points of the driver of the car
 */
    int getPoints();

/**
 * Function that recursively runs through all the Concrete Componets of the decorator design pattern and adds their speeds
 * @return returns the speed of the car
 */
    int calculateSpeed();

/**
 * Function to set the raceTime of the car
 * @param rt the raceTime of the car
 */
    virtual void setRaceTime(int rt);

/**
 * Function to increase the raceTime of the car by rt
 * @param rt increase race time variable by rt
 */
    virtual void incrementRaceTime(int rt);

/**
 * Get the cars raceTime
 * @return return the raceTime an int of the car
 */
    virtual int getRaceTime();

/**
 * Set the driver of the car
 * @param d the driver pointer to be set
 */
    void setDriver(Driver *d);

/**
 * Clone the car and return a car pointer
 * @return the cloned car
 */
    Car *clone();

/**
 * Function to get the Drivers name from the driver variable
 * @return the drivers name as string
 */
    string getDriverName();

/**
 * Destructor to deallocate all the memory and points used by the car
 */
    ~CurrentSeason();

/**
 * Return the type which is base, used by decorator
 * @return string "base
 */
    string getType();

/**
 * Function to add an array of tyre pointers to the tyre queue
 * @param t the tyre array to add to the tyre queue
 * @param num the number of tyres to add
 */
    void addTyres(Tyre** t, int num);

/**
 * Function to change the tyre by popping the tyre at the front of the queue
 */
    void popOldTyre();

/**
 * Function to see and get the tyre at the front of the queue
 * @return the tyre at front of Queue
 */
    Tyre* currentTyre();
};

#endif

