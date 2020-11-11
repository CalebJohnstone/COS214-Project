#ifndef DEPARTMENTMEDIATOR_H
#define DEPARTMENTMEDIATOR_H

#include "Car/Car.h"
#include "Team/Team.h"
#include "Car/Parts/DepartmentOutput.h"
#include "Team/Department/DepartmentFactory.h"

#include <string>
using namespace std;

class DepartmentFactory;
class Team;
/**
 * Pattern: Mediator. This class is the mediator that tells the team as well as other departments when a new part has been added to 
 * the car. This class servers as both the Mediator and ConcreteMediator participants.
 * The Colleague participant is the DepartmentOutput class and the ConcreteColleague participants are
 * Aerodynamics, Electronics, Engine and Chassis.
 * @headerfile DepartmentMediator.h "Team/Department/DepartmentMediator.h"
 */
class DepartmentMediator {
private:
    int currentDepartment;/*! @var The current number of department factories that this mediator is mediating for. 
    The maximum number is 4.*/
    DepartmentFactory **departments;/*! @var The department factories to mediate for. */
    Team *team;/*! @var The team that the departments are for.*/

public:
    /**
     *
     * @param team The team that the departments are for.
     */
    DepartmentMediator(Team *team);

/**
 *
 */
    ~DepartmentMediator();

/**
 * First the team is notified about the new part being added then the other departments are notified.
 * For example: if the Aerodynamics department produces a new part then the Electronics, Engine and 
 * Chassis departments must be notified of this change.
 * @param part The new part added to the car.
 * @param season A string that is either "current" or "next" to indicate which season the car is for
 */
    void communicate(DepartmentOutput* part,string season);

/**
 * Used to attach a department to this mediator.
 * @param department The department factory to attach.
 */
    void attachDepartment(DepartmentFactory* department);


};

#endif