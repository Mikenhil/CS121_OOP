class Horse {
	int horseID;
	int position;
	int trackSize;

	public:
		Horse(int id) {
			horseID = id;
			position = 0;
			trackSize = 15;
		}	

	public:
		void tryMove() {
			int coin = 0;
			position += coin;
		}

	public:
		void printLane() {
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

	public:
		bool isWinner() {
			bool winner = false;
			if(position == (trackSize - 1)) {
				winner = true;
				std::cout << "The winner is " << horseID << "!" << std::endl;
			}

			return winner;
		}
}

class Race {
	Horse[] horses;
	int numHorses;

	public:
		Race() {
			numHorses = 5;
			horses = Horse[numHorses];

			for(int i = 0; i < numHorses; i++) {
				Horse newHorse = new Horse(i);
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
}

Race race;

int main() {
	race = new Race();
	race.raceLoop()

	return 0;
}
