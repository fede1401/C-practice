#include "Account.hpp"
#include "RegistrationService.hpp"
#include "LoginService.hpp"
#include "CriptingPasswordService.hpp"
#include "SystemService.hpp"
#include <vector>



	
int main() {

	bool isRunning = true;
	RegistrationService regServ = RegistrationService();
	LoginService logServ = LoginService();
	CriptingPasswordService criptPassServ = CriptingPasswordService();

	std::vector<std::string> usernames = SystemService().updateRegisteredUsers();
	std::vector<Account> accountLogged{};

	while (isRunning) {
		std::string userName{};
		std::string password{};
		std::string choice{};

		std::cout << "\n\nDo you wanna login (1), create new account (2) or exit(3) ? Enter '1' or '2' or '3': ";
		std::getline(std::cin, choice);
		if (choice.length() < 0 || choice.length() > 1) { std::cout << "\nYou must enter '1' or '2' or '3'." << std::endl; }

		// Registration
		if (choice[0] == '2') {
			std::cout << "Enter your new username: ";
			std::getline(std::cin, userName);

			// Check if user exits
			int find = SystemService().checkIfUserExist(userName, usernames);

			if (find != -1) {
				std::cout << "Username already exist: " << userName << std::endl;
			}

			if (find == -1) {
				std::cout << "Enter your new password: ";
				std::getline(std::cin, password);
				Account acc = Account(userName, password);
				bool statusOperation = regServ.registerAccount(acc);
				if (statusOperation == true) {
					std::cout << "Registrazione effettuata con successo per " << acc.getName() << std::endl;
					usernames = SystemService().updateRegisteredUsers();
				}
				
			}
		}

		// Login
		else if (choice[0] == '1') {
			std::cout << "Enter your username: ";
			std::getline(std::cin, userName);

			// Check if user exits
			int find = SystemService().checkIfUserExist(userName, usernames);
			if (find == -1) {
				std::cout << "User doesn't exist! Register you!!" << std::endl;
			}

			// Check if user already logged
			int logged = SystemService().checkIfUserLogged(userName, accountLogged);

			if (logged != -1) {
				std::cout << "User already logged : " << userName << std::endl;
			}

			if (logged == -1) {
				std::cout << "Enter your password: ";
				std::getline(std::cin, password);
				Account acc = logServ.loginAccount(userName, password);
				if (acc.getName().length() > 1) {
					std::cout << "Login effettuato con successo per " << userName << std::endl;
					accountLogged.push_back(acc);
				}
			}
		}

		// Exit
		else if (choice[0] == '3') {
			isRunning = false;
			std::cout << "\n\nGoodbye!!!!! :)))))" << std::endl;
		}

		else {
			std::cout << "\nYou must enter '1' or '2' or '3'." << std::endl;
		}


		/*
		Account acc = Account("Federico3", "tavolo12!?");
		//std::string newPassw = criptPassServ.applyCipherPassword();
		//std::cout << "new passw: " <<  newPassw;
		bool statusOperation = regServ.registerAccount(acc);
		logServ.loginAccount(acc, "tavolo12!?");
		isRunning = false;
		*/
		

	}
	
	

}