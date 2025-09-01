#ifndef CRIPTING_PASSWORD_SERVICE_H
#define CRIPTING_PASSWORD_SERVICE_H

#include <string>
#include <map>

class CriptingPasswordService {
public:

	std::string applyCipherPassword(std::string password) {
		std::map<char, char> dictionary{ 
			{'a', 'e'}, {'b', 'd'}, {'c', 'a'}, {'d', 'f'}, {'e', 'j'}, {'f', 'i'},{'g', 'o'},
			{'h', 'w'}, {'i', 'c'}, {'l', 'b'}, {'m', 'r'}, {'n', '2'}, {'o', 's'},{'p', 'q'},
			{'q', 'v'}, {'r', 'p'}, {'s', 'l'}, {'t', 'n'}, {'u', 'm'}, {'v', 'z'},{'z', 'x'},
			{'1', '4'}, {'2', '1'}, {'3', '7'}, {'4', '8'}, {'5', '9'}, {'6', '0'},{'7', '3'},
			{'8', '6'}, {'9', '9'}
		};

		for (int i = 0; i < password.length(); i++) {
			if (dictionary.count(password[i]) == 0) {
				//std::cout << "strange element: " << password[i] << std::endl;
				password.replace(i, 1, 1, password[i]);
				continue;
			}
			//std::cout << dictionary[password[i]] << std::endl;
			password.replace(i, 1, 1, dictionary[password[i]]);
		}

		return password;
	}

	std::string decryptPassword(std::string password) {
		std::map<char, char> dictionary{
			{'a', 'c'}, {'b', 'l'}, {'c', 'i'}, {'d', 'b'}, {'e', 'a'}, {'f', 'd'},{'g', 'g'},
			{'w', 'h'}, {'i', 'f'}, {'l', 's'}, {'m', 'u'}, {'n', 't'}, {'o', 'g'},{'p', 'r'},
			{'q', 'p'}, {'r', 'm'}, {'s', 'o'}, {'t', 't'}, {'u', 'u'}, {'v', 'q'},{'z', 'v'},
			{'j', 'e'}, {'2', 'n'}, {'x', 'z'}, {'1', '2'}, {'3', '7'}, {'4', '1'}, {'5', '5'}, 
			{'6', '8'}, {'7', '3'}, {'8', '4'}, {'9', '5'}
		};

		for (int i = 0; i < password.length(); i++) {
			if (dictionary.count(password[i]) == 0) {
				//std::cout << "strange element: " << password[i] << std::endl;
				password.replace(i, 1, 1, password[i]);
				continue;
			}
			//std::cout << dictionary[password[i]] << std::endl;
			password.replace(i, 1, 1, dictionary[password[i]]);
		}

		return password;
	}


};

#endif // !CRIPTING_PASSWORD_SERVICE_H
