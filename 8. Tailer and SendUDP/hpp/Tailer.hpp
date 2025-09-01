#ifndef TAILER_HPP
#define TAILER_HPP

#include <filesystem>
#include <fstream> 
#include <iostream>
#include <string>
#include <vector>
//#include <windows.h>

#include "ClientUDP.hpp"



class Tailer {

private:
	std::string fileName;
	int dimFile = -1;
	int rowsReaded;

public:
	// Getter and Setter
	void setFileName(std::string fileName) { this->fileName = fileName; }
	std::string getFileName() { return fileName; }

	void setRowsReaded(int rowsReaded) { this->rowsReaded = rowsReaded; }
	int getRowsReaded() { return this->rowsReaded; }

	void setDimFile(int dimFile) { this->dimFile = dimFile; }
	int getDimFile() { return dimFile; }


	void timer(int sec) {
		Sleep(sec * 1000);
	}

	// Il tailer si occupa di leggere le righe dei file 
	std::vector<std::string> run() {
		
		std::vector<std::string> lines{};
		int countRows = 0;

		Clientt clientt = Clientt();
		
		while (true) {
			//std::cout << "Enter to while " << std::endl;
			timer(1);

			//std::cout << "Timer passed " << std::endl;

			int iRow = 0;

			std::ifstream fileRead(fileName);
			std::string text{};

			std::filesystem::path filePath = fileName;

			if (getDimFile() != -1) {
				if (std::filesystem::file_size(filePath) < getDimFile()) {
					std::cout << "Rotate file!" << std::endl;
					countRows = 0;
					setRowsReaded(0); // we will restart to read!
				}
			}

			//std::cout << "Size of file: " << fileName << " is: " << std::filesystem::file_size(filePath) << "\n";
			setDimFile(std::filesystem::file_size(filePath));
			
			while (std::getline(fileRead, text)) {
				//std::cout << "iRow: " << iRow << " count Rows: " << countRows << std::endl;

				if (iRow < countRows) { 
					std::cout << "Line alreay readed!" << std::endl;
					iRow += 1;
					continue; 
				} // lines already readed 
				
				std::cout << text << std::endl;
				lines.push_back(text);
				iRow += 1;
				countRows += 1;
				setRowsReaded(countRows);

				clientt.sendSocket(line);
				std::cout << "Send message!" << std::endl;

				for (std::string line : lines) {
					std::cout << "- " << line << std::endl;
				}

			}

		}

	
		return lines;
	}

};


#endif // !TAILER_HPP
