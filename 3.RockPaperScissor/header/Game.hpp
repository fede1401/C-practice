#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>  // Import the ctime library

enum ObjectGame {
	ROCK,
	PAPER, 
	SCISSOR
};

class Game{
private:
	time_t dateTime;
	ObjectGame resPlayer;
	ObjectGame resComputer;
	std::string winner;
	

public:
	Game();
	Game(time_t dateTime);

	// Getter and Setter
	time_t getDateTime();
	ObjectGame getResPlayer();
	ObjectGame getResComputer();
	std::string getWinner();

	void setDateTime(time_t dateTime);
	void setResPlayer(ObjectGame resPlayer);
	void setResComputer(ObjectGame resComputer);
	void setWinner(std::string winner);

	void determineWinner();
	void toString();

};

#endif // GAME_H
