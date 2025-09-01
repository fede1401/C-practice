#include "../header/Game.hpp"

#include <random>


void manageGesturePlayer(Game *g, bool *isContinue) {
	std::cout << "Choice your gesture:\n1. Rock\n2. Paper\n3. Scissor\nEnter:";
	std::string gestureInput;
	int gesture{};
	std::getline(std::cin >> std::ws, gestureInput); // read a full line of text into color

	if (gestureInput.length() > 1 || (gestureInput[0] != '1' && gestureInput[0] != '2' && gestureInput[0] != '3')) {
		std::cout << "You must choice between 1 and 3!\n\n";
		//continue;
		*isContinue = true;
		return;
	}
	//std::cout << gestureInput;
	//std::cin >> gesture;
	gesture = stoi(gestureInput);
	//std::cout << gesture;

	if (gesture > 3 || gesture < 1) {
		std::cout << "You must choice between 1 and 3!\n\n";
		//continue;
		*isContinue = true;
		return;
	}

	switch (gesture) {
	case 1: g->setResPlayer(ObjectGame::ROCK); break;
	case 2: g->setResPlayer(ObjectGame::PAPER); break;
	case 3: g->setResPlayer(ObjectGame::SCISSOR); break;
	}

	std::cout << "---------- valid game ----------" << std::endl;

	//std::cout << "Player gesture: " << g.getResPlayer() << std::endl;
}


void manageGestureComputer(Game *g) {
	srand(time(0));
	int computerGesture = rand() % 3;
	//std::cout << "Computer gesture: " << computerGesture << std::endl;
	switch (computerGesture) {
	case 0: {
		g->setResComputer(ObjectGame::ROCK);
		std::cout << "Computer chioced rock" << std::endl;
	}break;
	case 1: {
		g->setResComputer(ObjectGame::PAPER);
		std::cout << "Computer chioced paper" << std::endl;
	}break;
	case 2: {
		g->setResComputer(ObjectGame::SCISSOR);
		std::cout << "Computer chioced paper" << std::endl;
	}break;
	}
}



int main() {

	bool isRunning = true;
	bool isContinue = false;
	std::vector<Game> games{};

	while (isRunning) {
		isContinue = false;
		time_t timestamp = time(&timestamp);
		Game g = Game(timestamp);

		manageGesturePlayer(&g, &isContinue);
		if (isContinue == true) { continue; }
		manageGestureComputer(&g);
		g.determineWinner();
		games.push_back(g);

		std::cout << "\n----------valid game----------\n\n\n Do u want play another game? Enter y (yes), n (no)!";
		char anotherGame;
		std::cin >> anotherGame;
		if (anotherGame == 'n') {
			std::cout << "Goodbye :)))))" << std::endl;
			isRunning = false;
		}
	}

	for (Game game : games) {
		game.toString();
	}
	
	
	return 1;
}