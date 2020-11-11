#ifndef MEDIUM_H
#define MEDIUM_H
#include "Tyre.h"
/**
 *@class Medium class. Inherits publically from tyre and implements the primitive operation getPerformance for the template method
 * @headerfile Medium.h "Car/CurrentSeason/Tyre/Medium.h"
 */
class Medium : public Tyre {


public:
    /**
   * A constructor to create an object of type Medium
   */
    Medium();

    /**
   * Function getPerformance- is the primitive operation of the template method
   * @return int
   */
    int getPerformance();


};

#endif
