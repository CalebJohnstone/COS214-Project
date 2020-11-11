#ifndef DEPARTMENTFACTORY_H
#define DEPARTMENTFACTORY_H

#include "Car/Car.h"
#include "Car/Parts/DepartmentOutput.h"
#include "Team/Department/DepartmentMediator.h"

#include <iostream>
#include <string>
using namespace std;

class DepartmentMediator;
/**
 * Pattern: Factory Method. This class is the Creator participant. The ConcreteCreator participants are: 
 * AerodynamicsFactory, ElectronicsFactory, EngineFactory and ChassisFactory.
 * @headerfile DepartmentFactory.h "Team/Department/DepartmentFactory.h"
 */
class DepartmentFactory {
protected:
    DepartmentMediator *mediator;/*! @var The mediator to which this factory must be attached. */

public:
    /**
     *
     * @param mediator The mediator to which this factory must be attached. The attaching is done here.
     */
    DepartmentFactory(DepartmentMediator *mediator);

/**
 * Team is responsible for de-allocating the mediator. This destructor does no de-allocation.
 */
    ~DepartmentFactory();

/**
 *
 * @param oldPart The entry point to the decorated Car object to which to add a new part
 * @param season A string that is either "current" or "next" to indicate which season the car is for
 */
    virtual void createPart(DepartmentOutput* oldPart,string season) = 0;

/**
 * Run a simulation relevant to the part produced by this department factory
 */
    virtual void simulation() = 0;

/**
 *
 * @param part The part that has just been added to the car. This function lets all other departments know that
 * this part has been added.
 */
    virtual void otherPartChanged(DepartmentOutput* part) = 0;

/**
 *
 * @return The type of department.
 */
    virtual string getType() = 0;

/**
 *
 * @param oldPart The current part that is in the car
 * @param partType The type of part which is produced by this department factory, which is either "Aerodynamics", 
 * "Electronics", "Engine" or "Chassis".
 * 
 * @return The speed of the current part that is in the car. This is used to be compared with the new part's speed in
 * determining whether or not to add the new part.
 */
    int getPartSpeed(Car* oldPart, string partType);
};

#endif