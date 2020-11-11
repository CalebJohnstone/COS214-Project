#ifndef SEASON_H
#define SEASON_H

//colours for output
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

#include "Team/Team.h"
#include "Season/Race.h"
#include "Season/RaceIterator.h"
#include <string>

using namespace std;
/**
 * A singleton that represents the F1 season run in this simulation.
 * @headerfile Season.h "Season/Season.h"
 */
class Season {

private:
    static Season *singleton;/*! @var A pointer to the unique instance of Season.*/
    Team **teams;/*! @var An array of Team objects*/
    int numTeams;/*! @var The number of Team objects*/
    Race **races;/*! @var An array of Race objects*/
    int numRaces;/*! @var The number of Race objects*/
    /**
     * Private constructor
     */
    Season();

    /**
     * Orders tyres for all teams
     */
    void orderTyres();

    /**
     * 
     * @return An array of all Car objects from all Team objects.
     */
    Car **getCars();

    /**
     * Prints the current constructors' standings.
     */
    void displayConstructorsStandings();

    /**
     * Displays the current drivers' standings.
     */
    void displayDriversStandings();

    /**
     * Tells all teams to transport equipment to a race.
     * @param european True if the race is European, false if not.
     */
    void transport(bool european);

    /**
     *
     * @return a RaceIterator for going through all races
     */
    RaceIterator *createIterator();

    /**
     * Upgrades all cars, and trains drivers in the simulator if applicable
     * @param nextSeason True if NextSeason cars should be upgraded, and false if CurrentSeason cars should be upgraded and drivers should train in the simulator.
     */
    void upgradeAndSimulate(bool nextSeason);

    /**
     * Tells all teams to update their constructors' points according to their drivers' points.
     */
    void updateTeamPoints();

public:
    /**
     * 
     * @return The unique instance of Season
     */
    static Season instance();

    /**
     * Destructor that deletes all races and teams, as well as the unique Season object
     */
    ~Season();

    /**
     * Enters a team into the season.
     * @param teamName The name of the team.
     * @param driver1 The name of the team's first driver.
     * @param driver2 The name of the team's second driver.
     */
    void addTeam(string teamName, string driver1, string driver2);

    /**
     * Adds a race to the season.
     * @param length The number of laps in the race
     * @param european True if the race is European, false if not
     * @param date The date of the race (1-365)
     * @param name The name of the race, including the country that it is held in
     * @param averageLapTime The average lap time around the circuit
     */
    void addRace(int length, bool european, int date, string name, int averageLapTime);

    /**
     * Runs an entire season with the races and teams that have been provided.
     */
    void runSeason();
};

#endif
