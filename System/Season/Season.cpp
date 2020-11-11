#include "Season/Season.h"
#include <iostream>

using namespace std;

Season* Season::singleton;

Season::Season() {}

Season::~Season() {
	for (int i = 0; i < 10; i++) {
		delete teams[i];
	}
	delete[] teams;
	for (int i = 0; i < 21; i++) {
		delete races[i];
	}
	delete[] races;
	singleton = NULL;
}

Season Season::instance() {
	if (singleton == NULL) {
		singleton = new Season();
	}
	return *(singleton);
}

void Season::addTeam(string teamName, string driver1, string driver2) {
	Team** newList = new Team*[numTeams+1];
	for (int i = 0; i < numTeams; i++) {
		newList[i] = teams[i];
	}
	newList[numTeams] = new Team(teamName, driver1, driver2);
	delete[] teams;
	teams = newList;
	numTeams++;
}

void Season::addRace(int length, bool european, int date, string name, int averageLapTime) {
	Race** newList = new Race*[numRaces+1];
	for (int i = 0; i < numRaces; i++) {
		newList[i] = races[i];
	}
	newList[numRaces] = new Race(length, european, date, name, averageLapTime);
	delete[] races;
	races = newList;
	numRaces++;
}

void Season::runSeason() {
	bool upgradesBlocked = false;
	bool workOnCurrentCar = true;
	cout << endl << "The season has started" << endl;
	for (int date = 1; date <= 365; date++) {
		cout << GREEN << "Day " << date << RESET << endl;
		RaceIterator* it = createIterator();
		for (it->first(); !it->isDone(); it->next()) {
			Race* race = it->currentItem();

			if ((!race->isEuropean() && race->getDate()-90 == date) || (date == 1 && !race->isEuropean() && race->getDate()-90 == date)) {
				cout << "Transporting items to the " << race->getName() << ":" << endl;
				transport(false);
			} else if ((race->isEuropean() && race->getDate()-7 == date) || (date == 1 && race->isEuropean() && race->getDate()-7 < date)) {
				cout << "Transporting items to the " << race->getName() << ":" << endl;
				transport(true);
			}
			
			if (race->getDate()-30 == date || (date == 1 && race->getDate()-30 < date)) {
				cout << "Ordering tyres for the " << race->getName() << ":" << endl;
				orderTyres();
			}

			if (race->getDate()-1 == date) {
				cout << "All teams have flown their cars from the factory to the race" << endl;
				upgradesBlocked = true;
			} else if (race->getDate() == date) {
				race->runRaceWeekend(getCars(), numTeams*2);
				date += 2;
				updateTeamPoints();
				displayDriversStandings();
				cout << endl;
				displayConstructorsStandings();
				if (race == races[numRaces-1]) {
					workOnCurrentCar = false;
				}
			} else if (race->getDate()+4 == date) {
				cout << "All teams have flown their cars back to the factory for upgrades" << endl;
				upgradesBlocked = false;
			}
		}
		delete it;
		if (workOnCurrentCar && !upgradesBlocked) {
			upgradeAndSimulate(false);
		}

		if (date > 180) {
			upgradeAndSimulate(true);
		}
	}
	cout << RED << "Final Standings:" << RESET << endl;
	displayDriversStandings();
	cout << endl;
	displayConstructorsStandings();
}

void Season::displayConstructorsStandings() {
	cout << RED << "Constructors' Standings:" << RESET << endl;
	for (int i = 0; i < numTeams; i++) {
		for (int j = i+1; j < numTeams; j++) {
			if (teams[i]->getConstructorPoints() < teams[j]->getConstructorPoints()) {
				Team* temp = teams[i];
				teams[i] = teams[j];
				teams[j] = temp;
			}
		}
	}
	for (int i = 0; i < numTeams; i++) {
		cout << (i+1) << ". " << teams[i]->getName() << ": " << teams[i]->getConstructorPoints() << endl;
	}
}

void Season::orderTyres() {
	for (int i = 0; i < numTeams; i++) {
		teams[i]->orderTyres();
	}
}

Car** Season::getCars() {
	Car** cars = new Car*[20];
	for (int i = 0; i < 10; i++) {
		cars[i*2] = teams[i]->getCurrentSeasonCars()[0];
		cars[i*2+1] = teams[i]->getCurrentSeasonCars()[1];
	}
	return cars;
}

void Season::transport(bool european) {
	for (int i = 0; i < numTeams; i++) {
		if (european) {
			teams[i]->setEuropeanStrategy();
		} else {
			teams[i]->setNonEuropeanStrategy();
		}
		teams[i]->transport();
	}
}

void Season::displayDriversStandings() {
	Car** cars = getCars();
	cout << RED << "Drivers' Standings:" << RESET << endl;
	for (int i = 0; i < numTeams*2; i++) {
		for (int j = i+1; j < numTeams*2; j++) {
			if (cars[i]->getPoints() < cars[j]->getPoints()) {
				Car* temp = cars[i];
				cars[i] = cars[j];
				cars[j] = temp;
			}
		}
	}
	for (int i = 0; i < numTeams*2; i++) {
		cout << (i+1) << ". " << cars[i]->getDriverName() << ": " << cars[i]->getPoints() << endl;
	}
}

RaceIterator* Season::createIterator() {
	return new RaceIterator(races, numRaces);
}

void Season::upgradeAndSimulate(bool nextSeason) {
	for (int i = 0; i < numTeams; i++) {
        //cout << teams[i]->getName() << endl;
		if (nextSeason) {
			teams[i]->upgradeNextSeason();
		} else {
       		teams[i]->upgradeAndSimulate();
		}
    }
}

void Season::updateTeamPoints() {
	for (int i = 0; i < numTeams; i++) {
        //cout << teams[i]->getName() << endl;
        teams[i]->updatePoints();
    }
}