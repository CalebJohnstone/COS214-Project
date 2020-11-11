#ifndef ELECTRONICSFACTORY_H
#define ELECTRONICSFACTORY_H

#include "Car/Car.h"
#include "Team/Department/DepartmentFactory.h"
#include "Car/Parts/Electronics.h"

#include <string>
using namespace std;
/**
 * The class that represents the Electronics Department. This department produces the Electronics part.
 * @headerfile ElectronicsFactory.h "Team/Department/ElectronicsFactory.h"
 */
class ElectronicsFactory : public DepartmentFactory {
private:

public:
    /**
     *
     * @param mediator The mediator to which this factory must be attached.
     */
    ElectronicsFactory(DepartmentMediator *mediator);

/**
 *
 */
    ~ElectronicsFactory();

/**
 *
 * @param oldPart The entry point to the decorated Car object to which to add a new part
 * @param season A string that is either "current" or "next" to indicate which season the car is for
 */
    void createPart(DepartmentOutput* oldPart, string season);

/**
 * Run a simulation to test the electronics, so the driver becomes familiar with the controls.
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
 * @return The type of department which is "Electronics" in this case.
 */
    string getType();
};

#endif