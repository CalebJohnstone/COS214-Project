#ifndef TEAM_H
#define TEAM_H

#include "Car/CurrentSeason/CurrentSeason.h"
#include "Team/Transport/Container/Container.h"
#include "Team/Transport/Strategy/TransportStrategy.h"
#include "Team/Department/DepartmentFactory.h"
#include "Team/Department/DepartmentMediator.h"
#include "Car/NextSeason/NextSeason.h"
#include "Car/Parts/DepartmentOutput.h"

class DepartmentFactory;
class DepartmentMediator;
/**
 * Represents a single team in an F1 season.
 * @headerfile Team.h "Team/Team.h"
 */
class Team {

private:
    Car **currentCars;/*! @var An array of cars currently participating in the F1 season.*/
    Container *container;/*! @var A container used to transport items to races.*/
    TransportStrategy *transportStrategy;/*! @var The strategy used to transport items. Can be Truck or Ship.*/
    DepartmentFactory **departments;/*! @var The departments that produce parts to be put on the cars.*/
    string name;/*! @var The name of the team.*/
    DepartmentMediator *mediator;/*! @var A mediator between the team and its departments.*/
    int constructorPoints;/*! @var The team's constructor points.*/
    Car *nextSeasonCar;/*! @var The car that the team is working on for the next season.*/

public:
/**
 *
 * @param string_name The name of the team.
 * @param driver1Name The name of the team's first driver.
 * @param driver2Name The name of the team's second driver.
 */
    Team(string string_name, string driver1Name, string driver2Name);

/**
 * Destroys the team and its cars and departments.
 */
    ~Team();

/**
 * Transports items to a race using the current transport strategy.
 */
    void transport();

/**
 * Orders tyres for both cars ahead of a race.
 */
    void orderTyres();

/**
 *
 * @return an array of the team's current cars.
 */
    Car **getCurrentSeasonCars();

/**
 * Sets the team's transport strategy to use Truck.
 */
    void setEuropeanStrategy();

/**
 * Sets the team's transport strategy to use Ship.
 */
    void setNonEuropeanStrategy();

/**
 *
 * @return the name of the team.
 */
    string getName();

/**
 *
 * @param part a newly created upgraded part.
 * @param season The car that the upgrade applies to ("current" or "next")
 */
    void partChanged(DepartmentOutput* part, string season);

/**
 * Updates the team's constructor points by adding its drivers' points together.
 */
    void updatePoints();

/**
 * Tells a factory to work on an upgrade for the current cars, and trains the drivers.
 */
    void upgradeAndSimulate();

/**
 * Tells a factory to work on an upgrade for next season's cars.
 */
    void upgradeNextSeason();
/**
 *
 * @return the team's current constructor point tally.
 */
    int getConstructorPoints();


};

#endif
