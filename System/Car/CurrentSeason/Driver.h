#ifndef DRIVER_H
#define DRIVER_H

#include <string>

using namespace std;

/**
 * @class A class Driver that holds all the information for a formula one driver
 * @headerfile Driver.h "Car/CurrentSeason/Driver.h"
 */
class Driver {

private:
    string name; /*! @var a private variable that holds the name of the driver */
    int points; /*! @var a private varibale that holds the drivers championship points for the season */
    int performance; /*! @var a private variable that holds the drivers performance */

public:
    /**
     * A constructor that takes in the drivers name as a parameter
     * @param n The drivers name
     */
    Driver(string n);

    /**
     * A function to get the drivers name
     * @return returns drivers name
     */
    string getDriver();

    /**
     * Function to get the performance variable
     * @return perfromance variable
     */
    int getPerformance();

    /**
     * Function to set the performance varaible
     * @param p new performance variable
     */
    void setPerformance(int p);

    /**
     * Function to get the drivers championship points
     * @return points
     */
    int getPoints();

    /**
     * Function to set points to p
     * @param p new points
     */
    void setPoints(int p);

    /**
     * Function to get drivers name
     * @return drivers name
     */
    string getName();

};

#endif
