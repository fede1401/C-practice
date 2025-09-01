#ifndef AGENT_FILE_HPP
#define AGENT_FILE_HPP

#include <string>
#include <fstream> 
#include <iostream>
#include <vector>
#include <windows.h>
#include <filesystem>

class AgentFile {

private:

	std::string fileName;
	int numFile;  // utilizzato per memorizzare il numero di copie necessarie

public:
	// Getter and Setter
	void setFileName(std::string fileName) { this->fileName = fileName; }
	std::string getFileName() { return fileName; }

	void setNumFile(int numFile) { this->numFile = numFile; }
	int getNumFile() const { return numFile; }


	void timer(int sec) {
		Sleep(sec * 1000);
	}

	// L'agente si occupa di creare un file e scriverci dentro dei log ogni 5 secondi in maniera che il tailer può gestire il resto
	void run(int id) {

		std::vector<std::string> backupLines{};

		std::ofstream fileToWrite;
		fileToWrite.open(fileName, std::ios::trunc);

		if (!fileToWrite.is_open()) return;

		while (true) {
			timer(2);
			std::cout << "Write on file !" << std::endl;
			fileToWrite << id << " Example to print\n";
			backupLines.push_back(std::to_string(id) + " Example to print\n");
			fileToWrite.flush();
			id += 1;

			// rotate: se la dimensione del file supera i 680 mb (cioè 100 righe)
			std::filesystem::path filePath = fileName;
			std::cout << "Size of file: " << fileName << " is: " << std::filesystem::file_size(filePath) << "\n";
			if (std::filesystem::file_size(filePath) > 300) {

				std::cout << "Enter to rotate!" << std::endl;

				fileToWrite.close();

				numFile += 1;
				setNumFile(numFile);
				// viene creato il nuovo file
				std::string fileNew =  fileName.substr(0, 11) + std::to_string(numFile) +  fileName.substr(11);
				std::ofstream fileToWriteN;
				std::cout << "File NEW: " << fileNew;
				fileToWriteN.open(fileNew, std::ios_base::app);

				// copia le linee nel nuovo file:
				for (std::string line : backupLines) { fileToWriteN << line; }

				fileToWriteN.close();

				fileToWrite.open(fileName, std::ios::trunc);

				backupLines.clear();
			}
		}

		fileToWrite.close();
	}

};

#endif // !AGENT_FILE_HPP
