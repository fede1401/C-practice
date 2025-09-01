#include "../hpp/AgentFile.hpp"

#include <iostream>
#include <string>

int main() {

	AgentFile agent = AgentFile();
	agent.setFileName("../data/log.txt");

	int id = 0;
	agent.run(id);

}
