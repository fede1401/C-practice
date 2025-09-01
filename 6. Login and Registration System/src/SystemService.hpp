#ifndef SYSTEM_SERVICE
#define SYSTEM_SERVICE

#include <fstream> 
#include <iostream>
#include <vector>
#include "Account.hpp"


class SystemService {
public:

	static std::string splitAndTakeStringAt(std::string text, char delimiter, int position) {
		//std::cout << "\n\nInto the method: \n\n";
		int i = 0;
		int j = 0;
		int pos1 = 0;
		int pos2 = 0;
		int firstTime = 0;
		std::string res{};
		while (i < text.length()) {
			//std::cout << "Char at " << i << ": " << text[i] << std::endl;
			if (text[i] == delimiter) {
				//std::cout << "Char == Delimiter at " << i << std::endl;

				if (firstTime == 0) {
					if (position == 1) {
						pos1 = 0;
						pos2 = i;
						res = text.substr(pos1, (pos2 - pos1));
						break;
					}
					pos1 = i;
					firstTime++;
				}
				j++;
				if (j == position) {
					pos2 = i;
					res = text.substr(pos1 + 2, ((pos2 - 1) - pos1) - 1);
					break;
				}
			}
			i++;
		}
		return res;
	}

	static std::vector<std::string> updateRegisteredUsers() {
		std::vector<std::string> usernames{};
		std::string text;
		std::ifstream Myfile("../data/regFile.txt");
		if (Myfile.is_open()) {
			// read file
			while (std::getline(Myfile, text)) {
				//std::cout << text; 

				// take all username
				std::string username = splitAndTakeStringAt(text, ',', 1);
				usernames.push_back(username);
			}
		}
		Myfile.close();
		return usernames;
	}


	static int checkIfUserExist(std::string username, std::vector<std::string> usernames) {
		for (int i = 0; i < usernames.size(); i++) {
			//std::cout << "Usernames's vector at " << i << ": " << usernames[i] << "\n";
			if (usernames[i] == username) {
				return i;
			}
		}
		return -1;
	}

	static int checkIfUserLogged(std::string username, std::vector<Account> accountLogged) {
		for (int i = 0; i < accountLogged.size(); i++) {
			//std::cout << "Usernames's vector at " << i << ": " << usernames[i] << "\n";
			if (accountLogged[i].getName() == username) {
				return i;
			}
		}
		return -1;
	}








};

#endif // !SYSTEM_SERVICE
