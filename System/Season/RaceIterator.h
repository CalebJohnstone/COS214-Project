#ifndef RACEITERATOR_H
#define RACEITERATOR_H

#include "Season/Race.h"

using namespace std;
/**
 * A class that is the concrete iterator for the iterator design pattern
 * @headerfile RaceIterator.h "Season/RaceIterator.h"
 */
class RaceIterator {

private:
    Race **races;/*! @var The array of race pointers*/
    int length;/*! @var Length of races array*/
    int current;/*! @var The current index for the array*/
public:
/**
 *Constructor that takes an array of race pointers and the size of the array as parampters
 * @param races race pointers
 * @param length size of race array
 */
    RaceIterator(Race **races, int length);

    /**
     *Destructor to deallocate the races
     */
    ~RaceIterator();

    /**
     *Function to move the index to the first race
     */
    void first();

    /**
     *Function to move the index one along the array
     */
    void next();

    /**
     *Function to check if the index can be moved further along the array
     * @return true if can move false if index at end
     */
    bool isDone();

    /**
     *Returns the item at the current index
     * @return Race pointer 
     */
    Race *currentItem();
};

#endif
