#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H

#include "Car/Car.h"
#include "Team/Department/DepartmentFactory.h"
#include "Car/Parts/Engine.h"

#include <string>
using namespace std;
/**
 * The class that represents the Engine Department. This department produces the Engine part.
 * @headerfile EngineFactory.h "Team/Department/EngineFactory.h"
 */
class EngineFactory : public DepartmentFactory {
private:

public:
    /**
     *
     * @param mediator The mediator to which this factory must be attached.
     */
    EngineFactory(DepartmentMediator *mediator);

/**
 *
 */
    ~EngineFactory();

/**
 *
 * @param oldPart The entry point to the decorated Car object to which to add a new part
 * @param season A string that is either "current" or "next" to indicate which season the car is for
 */
    void createPart(DepartmentOutput* oldPart, string season);

/**
 * Run a simulation to allow the driver to adjust to the weight distribution of the Engine.
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
 * @return The type of department which is "Engine" in this case.
 */
    string getType();
};

#endif