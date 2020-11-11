#ifndef HARD_H
#define HARD_H
#include "Tyre.h"
/**
 * @class Hard class. Inherits publicly from tyre and implements the primitive operation getPerformance for the template method
 * @headerfile Hard.h "Car/CurrentSeason/Tyre/Hard.h"
 */
class Hard : public Tyre {


public:
    /**
     * A constructor to create an object of type Hard
     */
    Hard();

    /**
     * Function getPerformance- is the primitive operation of the template method
     * @return int
     */
    int getPerformance();


};

#endif
