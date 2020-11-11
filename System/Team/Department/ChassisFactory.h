#ifndef CHASISFACTORY_H
#define CHASISFACTORY_H

#include "Car/Car.h"
#include "Team/Department/DepartmentFactory.h"
#include "Car/Parts/Chassis.h"

#include <string>
using namespace std;
/**
 * The class that represents the Chassis Department. This department produces the Chassis part.
 * @headerfile ChassisFactory.h "Team/Department/ChassisFactory.h"
 */
class ChassisFactory : public DepartmentFactory {
private:


public:
    /**
     *
     * @param mediator The mediator to which this factory must be attached.
     */
    ChassisFactory(DepartmentMediator *mediator);

/**
 *
 */
    ~ChassisFactory();

/**
 *
 * @param oldPart The entry point to the decorated Car object to which to add a new part
 * @param season A string that is either "current" or "next" to indicate which season the car is for
 */
    void createPart(DepartmentOutput* oldPart,string season);

/**
 * Run a simulation for the driver so that they can adjust to the weight distribution of the chassis.
 */
    void simulation();

/**
 *
 * @param part The part that has just been added to the car. This function lets all other departments know that
 * this part has been added.
 */
    void otherPartChanged(DepartmentOutput* part);

/**
 *
 * @return The type of department which is "Chassis" in this case.
 */
    string getType();
};

#endif