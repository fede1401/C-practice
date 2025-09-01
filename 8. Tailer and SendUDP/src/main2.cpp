#include "../hpp/Tailer.hpp"

#include <iostream>
#include <string>

int main() {

	Tailer tailer = Tailer();
	tailer.setFileName("../data/log.txt");

	std::vector<std::string> lines = tailer.run();

}
