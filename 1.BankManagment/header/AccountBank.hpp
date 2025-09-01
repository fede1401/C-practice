#ifndef ACCOUNT_BANK_H
#define ACCOUNT_BANK_H

#include <string>
#include <iostream>
#include <vector>

class AccountBank {
private:
	std::string nickname; 
	std::string accountNumber;
	float balance;
	std::vector < std::string> operation;

public: 
	AccountBank();
	AccountBank(std::string nickname, std::string accountNumber, float balance, std::vector < std::string> operation);

	// Getter and setter
	std::string getNickname();
	std::string getAccountNumber();
	float getBalance();
	std::vector<std::string> getOperation();

	void setNickname(std::string nickname);
	void setAccountNumber(std::string accountNumber);
	void setBalance(float balance);
	void setOperation(std::vector < std::string> operation);

	// Operation about account bank
	void depositeMoney(float money);
	void withdrawMoney(float money);

	// Print the data about account banking
	void toString();
};


#endif