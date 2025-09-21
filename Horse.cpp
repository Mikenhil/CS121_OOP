#include <iostream>
#include <random>

#include "Horse.h"

int horseID;
int position;
int trackSize;

Horse::Horse() {
	position = 0;
	trackSize = 15;
}	

void Horse::tryMove() {
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, 1);

	int coin = dist(rd);
	position += coin;
}

void Horse::printLane() {
	for(int i = 0; i < trackSize; i++) {
		if(position == i) {
			std::cout << horseID << " ";
		}
		else {
			std::cout << ". "; 
		}
	}
	std::cout << "" << std::endl;
}

bool Horse::isWinner() {
	bool winner = false;
	if(position == (trackSize - 1)) {
		winner = true;
		std::cout << "The winner is " << horseID << "!" << std::endl;
	}

	return winner;
}

void Horse::setID(int id) {
	horseID = id;
}
