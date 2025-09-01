#include "../header/AccountBank.hpp"

AccountBank::AccountBank() {}

AccountBank::AccountBank(std::string nickname, std::string accountNumber, float balance, std::vector < std::string> operation) {
	this->nickname = nickname;
	this->accountNumber = accountNumber;
	this->balance = balance;
	this->operation = operation;
}

//Getter and setter
std::string AccountBank::getNickname() { return nickname; }
std::string AccountBank::getAccountNumber() { return accountNumber; }
float AccountBank::getBalance() { return balance; }
std::vector<std::string> AccountBank::getOperation() { return operation; }

void AccountBank::setNickname(std::string nickname) { this->nickname = nickname; }
void AccountBank::setAccountNumber(std::string accountNumber) { this->accountNumber = accountNumber; }
void AccountBank::setBalance(float balance) { this->balance = balance; }
void AccountBank::setOperation(std::vector < std::string> operation) { this->operation = operation; }

void AccountBank::depositeMoney(float money) {
	if (money > 0) {
		balance += money;
		//std::cout << "Deposito di " << money;
		std::string logOper = "Deposito di " + std::to_string(money);
		operation.push_back(logOper);
	}
	return;
}
void AccountBank::withdrawMoney(float money) {
	if (balance >= money && money > 0) {
		balance -= money;
		//std::cout << "Prelievo di " << money;
		std::string logOper = "Prelievo di " + std::to_string(money);
		operation.push_back(logOper);
	}
	else {
		if (balance < money) {
			std::cout << "Saldo non sufficiente per il prelievo!!!" << std::endl;
			std::string logOper = "Prelievo non avvenuto con successo per fondi insufficienti di " + std::to_string(money);
			operation.push_back(logOper);
		}
		else if (money < 0) {
			std::cout << "Non può essere effettuato un prelievo di 0 euro!!!" << std::endl;
			std::string logOper = "Prelievo non avvenuto con successo per somma = 0 euro " ;
			operation.push_back(logOper);
		}
		
	}
	return;
}

void AccountBank::toString() {
	std::cout << "Account banking with this data:\nNickname: " << nickname << ", accountNumber: " << accountNumber << ", balance disponible: " << balance
		<< "\nOperations done: \n";
	for (int i = 0; i < operation.size(); i++) { 
		std::cout << "- " << operation[i] << "\n";
	}
	return;
}