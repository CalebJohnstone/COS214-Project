#ifndef SOFT_H
#define SOFT_H
#include "Tyre.h"
/**
 * @class Soft class. Inherits publically from tyre and implements the primitive operation getPerformance for the template method
 * @headerfile Soft.h "Car/CurrentSeason/Tyre/Soft.h"
 */
class Soft : public Tyre {


public:
    /**
     * A constructor to create an object of type Medium
     */
    Soft();

    /**
     * Function getPerformance- is the primitive operation of the template method
     * @return int
     */
    int getPerformance();


};

#endif
