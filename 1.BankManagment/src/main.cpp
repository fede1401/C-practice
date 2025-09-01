#include "../header/AccountBank.hpp"

int main() {
	bool isRun = true;

	std::vector<AccountBank> accsBank = {};
	while (isRun) {
		int choice;
		std::cout << "\n=== Bank Managment System ===\nChoice the operation: \n1. Create Account\n2. Deposit money\n3. Withdraw Money\n4. Show Display Account Details\n5. Exit\n\nEnter you chioce: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
		{
			AccountBank acc = AccountBank();
			std::cout << "Enter nickname for application: ";
			std::string nickName;
			// use std::getline();
			std::cin >> nickName;
			acc.setNickname(nickName);
			std::cout << "Enter account number: ";
			std::string accountNumber;
			std::cin >> accountNumber;
			acc.setAccountNumber(accountNumber);
			float initialBal;
			std::cout << "Enter Initial Balance: ";
			std::cin >> initialBal;
			acc.setBalance(initialBal);
			acc.setOperation({ "Creation an account from" + accountNumber });
			accsBank.push_back(acc);
			std::cout << "Welcome, creation account successfully completed!\n";
		}
		break;

		case 2:
		{
			std::cout << "Enter your account number: ";
			std::string accNumber;
			std::cin >> accNumber;
			bool find = false;
			
			for (int i = 0; i < accsBank.size(); i++) {
				if (accsBank[i].getAccountNumber() == accNumber) {
					find = true;
					std::cout << "How much money do you would deposit: ";
					float depositMoney;
					std::cin >> depositMoney;
					accsBank[i].depositeMoney(depositMoney);
					std::cout << "Deposit " << depositMoney << " successfully completed!";
				}
			}
			if (find == false)  std::cout << "Account not found!" << std::endl;
		}
		break;

		case 3:
		{
			std::cout << "Enter your account number: ";
			std::string accNumber;
			std::cin >> accNumber;
			bool find = false;

			for (int i = 0; i < accsBank.size(); i++) {
				if (accsBank[i].getAccountNumber() == accNumber) {
					find = true;
					std::cout << "\nHow much money do you would Withdraw: ";
					float withdrawMoney;
					std::cin >> withdrawMoney;
					accsBank[i].withdrawMoney(withdrawMoney);
					std::cout << "Withdraw " << withdrawMoney << " successfully completed!";
				}
			}
			if (find == false)  std::cout << "Account not found!" << std::endl;
		}
		break;

		case 4:
		{
			std::cout << "Insert you accountNumber: ";
			std::string accNumber;
			std::cin >> accNumber;
			bool find = false;

			for (int i = 0; i < accsBank.size(); i++) {
				if (accsBank[i].getAccountNumber() == accNumber) {
					find = true;
					accsBank[i].toString();
				}
			}
			if (find == false)  std::cout << "Account not found!" << std::endl;
			std::cout << "\n";
		
		}
		break;

		case 5:
		{
			isRun = false;
		}
		break;
		}
	}
	/*
	* AccountBank a1 = AccountBank("Federico", "2diosjdo1", 2500.90, {});
	a1.depositeMoney(10.0);
	a1.withdrawMoney(3000.0);
	a1.withdrawMoney(100.0);
	a1.depositeMoney(10000);
	a1.toString();
	*/
}