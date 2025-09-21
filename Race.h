#ifndef RACE_H
#define RACE_H

#include <iostream>
#include "Horse.h"

class Race {
	const static int NUM_HORSES = 5;
	Horse horse[NUM_HORSES];

	public:
		Race();
		void StartRace();
};

#endif
