#include "../header/Game.hpp"

Game::Game() {}
Game::Game(time_t dateTime) {
	this->dateTime = dateTime;
}



// Getter and Setter
time_t Game::getDateTime(){	return dateTime; }
ObjectGame Game::getResPlayer() { return this->resPlayer; }
ObjectGame Game::getResComputer() { return this->resComputer; }
std::string Game::getWinner() { return winner; }

void Game::setDateTime(time_t dateTime)
{
	if (this->dateTime == dateTime){}
	else { this->dateTime = dateTime; }
	return;
}

void Game::setResPlayer(ObjectGame resPlayer)
{
	if (this->resPlayer == resPlayer) {}
	else { this->resPlayer = resPlayer; }
	return;
}

void Game::setResComputer(ObjectGame resComputer)
{
	if (this->resComputer == resComputer) {}
	else { this->resComputer = resComputer; }
	return;
}

void Game::setWinner(std::string winner)
{
	if (this->winner == winner) {}
	else { this->winner = winner; }
	return;
}



void Game::determineWinner() {
	//std::cout << "Player gesture: " << this->resPlayer << ", computer gesture: " << this->resComputer << std::endl;
	if (this->resPlayer == this->resComputer) {
		std::cout << "U and Computer same" << std::endl;
		std::cout << "Parity!!!!";
		setWinner("None");
	}
	else if (this->resPlayer == ObjectGame::ROCK &&
		this->resComputer == ObjectGame::PAPER) {
		std::cout << "U rock and Computer paper " << std::endl;
		std::cout << "Computer are the winner" << std::endl;
		setWinner("Computer");

	}
	else if (this->resPlayer == ObjectGame::PAPER &&
		this->resComputer == ObjectGame::ROCK) {
		std::cout << "U paper and Computer rock " << std::endl;
		std::cout << "U are the winner" << std::endl;
		setWinner("you");
	}
	else if (this->resPlayer == ObjectGame::ROCK &&
		this->resComputer == ObjectGame::SCISSOR) {
		std::cout << "U rock and Computer scissor " << std::endl;
		std::cout << "U are the winner" << std::endl;
		setWinner("you");
	}
	else if (this->resPlayer == ObjectGame::SCISSOR &&
		this->resComputer == ObjectGame::ROCK) {
		std::cout << "U scissor and Computer rock " << std::endl;
		std::cout << "Computer are the winner" << std::endl;
		setWinner("Computer");
	}
	else if (this->resPlayer == ObjectGame::SCISSOR &&
		this->resComputer == ObjectGame::PAPER) {
		std::cout << "U scissor and Computer paper " << std::endl;
		std::cout << "U are the winner" << std::endl;
		setWinner("you");
	}
	else if (this->resPlayer == ObjectGame::PAPER &&
		this->resComputer == ObjectGame::SCISSOR) {
		std::cout << "U paper and Computer scissor " << std::endl;
		std::cout << "Computer are the winner" << std::endl;
		setWinner("Computer");
	}
	
	return;
}


void Game::toString() {
	
	std::cout << "Game in date time: " << ctime(&dateTime) 
		<< "- With player's gesture: " << resPlayer <<
		" and computer's gesture: " << resComputer <<
		" have winner : " << winner
		<< "\n\n" << std::endl;
}