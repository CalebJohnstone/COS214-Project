#ifndef RACE_H
#define RACE_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m" 
#define GREEN   "\033[32m"

#include <string>
#include "Car/Car.h"

using namespace std;
/**
 * Represents a single race. It is the Aggregate participant of the Iterator design pattern.
 * @headerfile Race.h "Season/Race.h"
 */
class Race {

private:
    int laps;/*! @var The number of laps in the race*/
    bool european;/*! @var True if the race is European, false if not*/
    int date;  /*! @var The date when the race weekend starts (a number from 1 to 365)*/
    string name;/*! @var The name of the race, which includes the country it is held in*/
    Car **cars;/*! @var An array of cars participating in the race*/
    int numCars;/*! @var The number of cars participating in the race*/
    int averageLapTime;/*! @var The average lap time around the circuit*/
/**
 * Run free practice on Saturday morning.
 */
    void runFreePractice2();

/**
 * Run qualifying on Saturday afternoon.
 */
    void runQualifying();

/**
 * Run free practice on Friday morning.
 */
    void runFreePractice1();

/**
 * Sends all drivers into the pits for a tyre change.
 */
    void pitStop();

/**
 * Run the race on Sunday afternoon.
 */
    void runRace();

/**
 * Sort the cars by their raceTime in ascending order (lowest time is fastest).
 */
    void sortDrivers();

/**
 * Add points to drivers' totals after a race depending on their finishing position.
 */
    void allocatePoints();

public:
    /**
     *
     * @param l The number of laps in the race
     * @param euro True if the race is European, false if not
     * @param d The date when the race weekend starts (1 to 365)
     * @param n The name of the race, which includes the country it is held in)
     * @param avgL The average lap time around the circuit
     */
    Race(int l, bool euro, int d, string n, int avgL);

/**
 * Prints a leaderboard of the current positions of the drivers.
 */
    void printLeaderBoard();

/**
 * 
 * @return The date when the race weekend starts.
 */
    int getDate();

/**
 * 
 * @return True if the race is European, false if not.
 */
    bool isEuropean();

/**
 * Runs a race weekend with the given Car objects.
 * @param c An array of Car objects that have entered the race.
 * @param num The number of Car objects
 */
    void runRaceWeekend(Car **c, int num);

/**
*@return The name of the race, which includes the country it is held in.
*/
    string getName();
};

#endif
