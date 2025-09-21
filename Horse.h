#ifndef HORSE_H
#define HORSE_H

#include <iostream>
#include <random>

class Horse {
	int horseID;
	int position;
	int trackSize;

	public:
		Horse();	
		void tryMove();
		void printLane();
		bool isWinner();
		void setID(int id);
};

#endif
