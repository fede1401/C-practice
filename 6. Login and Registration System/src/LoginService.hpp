#ifndef LOGIN_SERVICE_H
#define LOGIN_SERVICE_H

#include "Account.hpp"
#include "CriptingPasswordService.hpp"
#include "SystemService.hpp"
#include <fstream> 
#include <iostream>
#include <ctime>

class LoginService {

public:
	LoginService() {}

	Account loginAccount(std::string userName, std::string inputPassword) {
		std::string text;
		std::ifstream Myfile("../data/regFile.txt");
		Account acc{};
		if (Myfile.is_open()) {
			// read file
			while (std::getline(Myfile, text)) { 
				//std::cout << text; 

				// take and decrypt password
				std::string passwordDb = SystemService().splitAndTakeStringAt(text, ',', 2);
				CriptingPasswordService criptPassw = CriptingPasswordService();
				std::string passwDecrypt = criptPassw.decryptPassword(passwordDb);
				std::cout << "\nPassword not decrypt db: " << passwordDb << std::endl;
				std::cout << "Password decrypt db: " << passwDecrypt << std::endl;

				if (passwDecrypt == inputPassword) {
					//std::cout << "Login effettuato con successo per " << userName << std::endl;
					acc = Account(userName, passwDecrypt);
				}	
			}
		}
		Myfile.close();
		return acc;
	}

	

};

#endif // !LOGIN_SERVICE_H
