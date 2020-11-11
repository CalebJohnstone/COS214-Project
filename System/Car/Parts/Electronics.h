#ifndef Electronics_H
#define Electronics_H

#include <string>
#include "Car/Parts/DepartmentOutput.h"
#include "Car/Car.h"

using namespace std;
/**
 * A class Electronics that is a concreteDecorator of the decorator design pattern,concreteProduct of the Factory method
 * @headerfile Electronics.h "Car/Parts/Electronics.h"
 */
class Electronics : public DepartmentOutput {

public:
    /**
     *Constructor to create an Electronics object
     */
    Electronics();

/**
 *Helper function used by clone function
 * @return Electronics pointer
 */
    Electronics *cpy();

/**
 *returns the speed
 * @return
 */
    int getSpeed();

/**
 *Clones the objects variables,method of the prototype design pattern
 * @return Electronics Object
 */
    Car *clone();
};

#endif
