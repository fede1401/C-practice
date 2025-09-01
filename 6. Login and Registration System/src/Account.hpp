#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account {

private:
	std::string name;
	std::string password;

public:
	Account() {}
	Account(std::string name, std::string password) {
		this->name = name;
		this->password = password;
	}

	//Getter and setter
	std::string getName() { return this->name; }
	std::string getPassword() { return this->password; }

	void setName(std::string name) { this->name = name; }
	void setPassword(std::string password) { this->password = password; }

	void toString() const { std::cout << "Account " << name << " with password: " << password << std::endl; }

};


#endif // !ACCOUNT_H
