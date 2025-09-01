/*
/Questo progetto è un divertente e interattivo gioco di indovinelli in cui 
il giocatore scommette denaro e cerca di indovinare un numero generato casualmente 
all'interno di un intervallo specificato. 
Il gioco premia le risposte corrette e detrae denaro da quelle errate, 
simulando un'esperienza simile a quella di un casinò.
*/

#include <map>
#include <iostream>
#include <string>
#include <random>

class CasinoGame {
private:
	int id;
	float moneyInGame;
	int randomuserNumberesult;
	bool victory;

public:
	CasinoGame() {}
	CasinoGame(int id) { this->id = id; }

	// Getter and setter
	int getId() { return this->id; }
	float getMoneyInGame() { return moneyInGame; }
	int getRandomuserNumberesult() { return randomuserNumberesult; }
	bool getVictory() { return victory; }

	void setId(int id) { this->id = id; }
	void setMoneyInGame(float moneyInGame) { this->moneyInGame = moneyInGame; }
	void setRandomuserNumberesult(int randomuserNumberesult) { this->randomuserNumberesult = randomuserNumberesult; }
	void setVictory(bool victory) { this->victory = victory; }

	void determineVictory(int randomUser) {
		if (randomUser == randomuserNumberesult) {
			victory = true;
		}
	}

	void toString() {
		victory == true ? std::cout << "Game with id: " << id << ", with money in this game: " << moneyInGame << " won with the number drawn: " << randomuserNumberesult << std::endl
			: std::cout << "Game with id: " << id << ", with money in this game: " << moneyInGame << " lose with the number drawn: " << randomuserNumberesult << std::endl;
	}

};


int main() {

	CasinoGame g;
	std::vector<CasinoGame> games;


	bool isRunning = true;
	int id = 0;
	while (isRunning) {
		isRunning = true;
		std::cout << "\n\nDo you wanna play? 'y': yes, 'n': no\nEnter:";
		std::string playChoice;
		std::getline(std::cin , playChoice); // read a full line of text into moneyToBet
		//std::cin >> playChoice;

		if (playChoice == "n") {
			isRunning = false;
			continue;
		}

		else if (playChoice != "y") {
			std::cout << "\nYou must choice 'y' or 'n'\n";
			continue;
		}

		id++;
		g = CasinoGame(id);

		std::string moneyToBet;
		int intMoneyToBet{};
		std::cout << "How much money do you want to bet? Enter: ";
		std::getline(std::cin >> std::ws, moneyToBet); // read a full line of text into moneyToBet
		try {
			intMoneyToBet = stoi(moneyToBet);
		}
		catch (...) {
			std::cout << "Invalid number input!\n";
			continue;
		}
		g.setMoneyInGame((float)intMoneyToBet);


		std::string numberInput;
		std::cout << "Enter your number between 0 and 5:";
		int userNumber{};
		std::getline(std::cin >> std::ws, numberInput); // read a full line of text into color

		try {
			userNumber = stoi(numberInput);
		}
		catch (...) {
			std::cout << "Invalid number input!\n";
			continue;
		}

		if (userNumber < 0 || userNumber > 5) {
			std::cout << "\nYou must choice between 0 and 5\n";
			continue;
		}

		srand(time(0)); // random number different every time
		g.setRandomuserNumberesult(rand() % 6);
		g.determineVictory(userNumber);
		std::cout << "--------valid game --------" << std::endl;
		g.toString();
		std::cout << "--------valid game --------" << std::endl;
		games.push_back(g);
	
	}

	std::cout << "\n\nGames:" << std::endl;
	float winnings = 0.0;
	float losses = 0.0;
	for (int i = 0; i < games.size(); i++) {
		games[i].toString();

		games[i].getVictory() == true ? winnings += games[i].getMoneyInGame() : losses += games[i].getMoneyInGame();
	}
	std::cout << "\nWinning: " << winnings << "\nLosses: " << losses << " Goodbyeeeee :))))))))" << std::endl;

	return 1;
}

