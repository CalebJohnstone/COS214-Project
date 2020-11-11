#include "Season/Season.h"

int main() {

	Season season = Season::instance();//(teams, 10, races, 21);

	season.addTeam("Mercedes", "Lewis Hamilton", "Valtteri Bottas");
	season.addTeam("Red Bull", "Max Verstappen", "Alex Albon");
	season.addTeam("Renault", "Daniel Ricciardo", "Esteban Ocon");
	season.addTeam("McLaren", "Carlos Sainz", "Lando Norris");
	season.addTeam("Racing Point", "Sergio Perez", "Lance Stroll");
	season.addTeam("Ferrari", "Charles Leclerc", "Sebastian Vettel");
	season.addTeam("AlphaTauri", "Pierre Gasly", "Daniil Kvyat");
	season.addTeam("Alfa Romeo", "Kimi Raikkonen", "Antonio Giovinazzi");
	season.addTeam("Haas", "Romain Grosjean", "Kevin Magnussen");
	season.addTeam("Williams", "George Russell", "Nicholas Latifi");

	// length, european, date, name, avg lap time
	season.addRace(58, false, 74, "Australian Grand Prix", 86);
	season.addRace(57, true, 88, "Bahrain Grand Prix", 93);
	season.addRace(56, false, 102, "Chinese Grand Prix", 95);
	season.addRace(51, true, 116, "Azerbaijan Grand Prix", 103);
	season.addRace(66, true, 130, "Spanish Grand Prix", 78);
	season.addRace(78, true, 143, "Monaco Grand Prix", 74);
	season.addRace(70, false, 158, "Canadian Grand Prix", 73);
	season.addRace(53, true, 172, "French Grand Prix", 93);
	season.addRace(71, true, 179, "Austrian Grand Prix", 67);
	season.addRace(52, true, 193, "British Grand Prix", 87);
	season.addRace(67, true, 207, "German Grand Prix", 77);
	season.addRace(70, true, 214, "Hungarian Grand Prix", 77);
	season.addRace(44, true, 242, "Belgian Grand Prix", 107);
	season.addRace(53, true, 249, "Italian Grand Prix", 83);
	season.addRace(61, false, 263, "Singapore Grand Prix", 102);
	season.addRace(53, true, 270, "Russian Grand Prix", 97);
	season.addRace(53, false, 284, "Japanese Grand Prix", 91);
	season.addRace(71, false, 298, "Mexican Grand Prix", 79);
	season.addRace(56, false, 305, "United States Grand Prix", 96);
	season.addRace(71, false, 319, "Brazilian Grand Prix", 71);
	season.addRace(55, true, 333, "Abu Dhabi Grand Prix", 99);

	season.runSeason();

	return 0;
}