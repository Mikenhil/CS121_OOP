#include <iostream>

#include "Horse.h"
#include "Race.h"

const static int NUM_HORSES = 5;
Horse horses[NUM_HORSES];

Race::Race() {
	for(int i = 0; i < NUM_HORSES; i++) {
		Horse newHorse;
		newHorse.setID(i);
		horses[i] = newHorse;
	}
}		
	// Changed from RaceLoop() to StartRace() for clarity
void Race::StartRace() {
	bool keepGoing = true;
	while(keepGoing) {
		for(int i = 0; i < NUM_HORSES; i++) {
			horses[i].tryMove();
			horses[i].printLane();

			if(horses[i].isWinner()) {
				keepGoing = false;
			}
		}
		std::cout << "press ENTER for a new turn";
		std::cin.ignore();
	}
}

