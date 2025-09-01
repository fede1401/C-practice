#ifndef REGISTRATION_SERVICE_H
#define REGISTRATION_SERVICE_H

#include "Account.hpp"
#include "SystemService.hpp"
#include "CriptingPasswordService.hpp"
#include <fstream> 
#include <iostream>
#include <ctime>

class RegistrationService {

public:
	RegistrationService() {}

	bool registerAccount(Account& acc) {
		CriptingPasswordService criptPassw = CriptingPasswordService();
		time_t dateTime;
		time(&dateTime);
		
		/*
		* // Check if user already exists:
		std::ifstream MyfileRead("../data/regFile.txt");
		std::string text{};
		while (std::getline(MyfileRead, text)) {
			//std::cout << text;
			if (text.length() > 0) {
				// take password
				std::string userName = SystemService().splitAndTakeStringAt(text, ',', 1);
				
				if (userName == acc.getName()) {
					std::cout << "Username already exist: " << userName << std::endl;
					MyfileRead.close();
					return false;
				}
				
			}
		}
		MyfileRead.close();
		*/
		

		// Create new user
		std::ofstream Myfile;
		Myfile.open("../data/regFile.txt", std::ios_base::app);
		if (Myfile.is_open()) {
			Myfile << acc.getName() << ", " << criptPassw.applyCipherPassword(acc.getPassword()) << ", " << ctime(&dateTime) << "\n";
			Myfile.close();
		}
		// std::cout << "Registrazione effettuata con successo per " << acc.getName() << std::endl;
		return true;
	}

};

#endif // !REGISTRATION_SERVICE_H
