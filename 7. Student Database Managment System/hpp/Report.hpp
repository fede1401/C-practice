#ifndef REPORT_H
#define REPORT_H

#include <map>
#include <vector>
#include <string>
#include <iostream>


class Report {
private:
	int id;
	int id_student;
	std::map<std::string, std::vector<float>> records;

public:
	Report() {}
	Report(int id, int id_student) {
		this->id = id;
		this->id_student = id_student;
		records = {};
	}

	// Getter and Setter
	int getId() const { return id; }
	int getIdStud() const { return id_student; }
	std::map<std::string, std::vector<float>> getRecords() { return records; }

	void setId(int id) { this->id = id; }
	void setIdStud(int id_student) { this->id_student = id_student; }
	void setRecords(std::map<std::string, std::vector<float>> records) { this->records = records; }

	
	void toString() {
		std::cout << "Student with id: " << id_student << " have this records:" << std::endl;
		for (auto record : records) {
			std::cout << "Subject: " << record.first << "\n" << "Records: " ;
			int i = 0;
			for (auto rec : record.second) {
				i += 1;
				if (i == record.second.size()) {
					std::cout << rec;
				}
				else{ std::cout << rec << ","; }
			}
			std::cout << "\n";
		}
	}


};



#endif // !REPORT_H
