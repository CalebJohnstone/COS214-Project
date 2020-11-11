#ifndef AERODYNAMICSFACTORY_H
#define AERODYNAMICSFACTORY_H

#include "Car/Car.h"
#include "Team/Department/DepartmentFactory.h"
#include "Car/Parts/Aerodynamics.h"

using namespace std;
/**
 * The class that represents the Aerodynamics Department. This department produces the Aerodynamics part and
 * tests the part using the windTunnel
 * @headerfile AerodynamicsFactory.h "Team/Department/AerodynamicsFactory.h"
 */
class AerodynamicsFactory : public DepartmentFactory {
private:
    int windTokens;/*! @var the number of tokens left to use the wind tunnel. This value is initiailised to 400 at the
    start of the season*/

    /**
    * Uses the wind tunnel to test the aerodynamics performance of the new Aerodynamics part. The wind tunnel can
    * only be used if the Team has at least one wind tunnel token left.
    */
    int windTunnel();

public:
    /**
     *
     * @param mediator The mediator to which this factory must be attached.
     */
    AerodynamicsFactory(DepartmentMediator *mediator);

/**
 *
 */
    ~AerodynamicsFactory();

/**
 *
 * @param oldPart The entry point to the decorated Car object to which to add a new part
 * @param season A string that is either "current" or "next" to indicate which season the car is for
 */
    void createPart(DepartmentOutput* oldPart,string season);

/**
 * Run a simulation of the wind patterns and weather conditions for the day so that the driver can become familiar with
 *  these.
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
 * @return The current number of wind tunnel tokens left for the Team.
 */
    int getTunnelTokens();

/**
 * Decreases the number of wind tunnel tokens left for the Team when this department uses the wind tunnel.
 */
    void decreaseTunnelTokens();

/**
 *
 * @return The type of department which is "Aerodynamics" in this case.
 */
    string getType();
};

#endif