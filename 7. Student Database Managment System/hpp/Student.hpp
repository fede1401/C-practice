#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

int idSeq = 0;

class Student {

private:
	int id;
	std::string firstName;
	std::string lastName;
	time_t birthDate;

public:
	Student() {}
	Student(std::string firstName, std::string lastName, time_t birthDate) {
		idSeq += 1;
		this->id = idSeq;
		this->firstName = firstName;
		this->lastName = lastName;
		this->birthDate = birthDate;
	}

	// Getter and Setter
	int getId() const { return id; }
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	time_t getBirthDate() { return birthDate; }

	void setId() { 
		idSeq += 1;
		this->id = idSeq; 
	}

	void setId(int id) { this->id = id; }
	void setFirstName(std::string firstName) { this->firstName = firstName; }
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setBirthDate(time_t birthDate) { this->birthDate = birthDate; }

	void toString() const {
		std::cout << "Student " << firstName << " " << lastName <<
			" with id: " << id << std::endl;
	}

};

#endif // !STUDENT_H
