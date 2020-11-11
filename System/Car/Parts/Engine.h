#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "Car/Parts/DepartmentOutput.h"

using namespace std;
/**
 * A class Engine that is a concreteDecorator of the decorator design pattern,concreteProduct of the Factory method
 *@headerfile Engine.h "Car/Parts/Engine.h"
 */
class Engine : public DepartmentOutput {

public:
    /**
     *A constructor
     */
    Engine();

/**
 *Helper function used by clone function
 * @return Engine object
 */
    Engine *cpy();

/**
 *Returns the engines speed
 * @return the cars speed
 */
    int getSpeed();

/**
 *Clones the objects variables and returns a new Engine,method of the prototype design pattern
 * @return Engine object
 */
    Car *clone();
};

#endif
