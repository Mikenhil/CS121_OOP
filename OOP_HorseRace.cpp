
#include <iostream>
#include <random>

class Horse {
	int horseID;
	int position;
	int trackSize;

	public:
		Horse() {
			position = 0;
			trackSize = 15;
		}

	public:
		void tryMove() {
			std::random_device rd;
			std::uniform_int_distribution<int> dist(0, 1);
			int coin = dist(rd);
			position += coin;
		}

	public:
		void printLane() {
			for(int i = 0; i < trackSize - 1; i++) {
				if(position == i) {
					std::cout << horseID << " ";
				}
				else {
					std::cout << ". ";
				}
			}
			std::cout << "" << std::endl;
		}

	public:
		bool isWinner() {
			bool winner = false;
			if(position == (trackSize - 1)) {
				winner = true;
				std::cout << "The winner is " << horseID << "!" << std::endl;
			}

			return winner;
		}
	
	public:
		void setID(int id) {
			horseID = id;
		}
};

class Race {
	Horse horses[5];
	int numHorses;

	public:
		Race() {
			numHorses = 5;

			for(int i = 0; i < numHorses; i++) {
				Horse newHorse;
				newHorse.setID(i);
				horses[i] = newHorse;
			}
		}

	public:
		void raceLoop() {	
			bool keepGoing = true;
			while(keepGoing) {
				for(int i = 0; i < numHorses; i++) {
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
};

Race race;

int main() {
	race.raceLoop();

	return 0;
}
