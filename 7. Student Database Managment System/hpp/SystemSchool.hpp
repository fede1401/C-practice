#ifndef SYSTEM_SCHOOL_H
#define SYSTEM_SCHOOL_H

#include <string>
#include <vector>
#include <fstream> 
#include <unordered_set>

#include "Student.hpp"
#include "Report.hpp"

class SystemSchool {

private:
	std::string nameSchool;
	std::vector<Student> students;
	std::vector<Report> reports;

public:
	

	SystemSchool() {
		// Take students and reports from file and associate to variables.
		takesStudents();
		//takesReports();
	}

	SystemSchool(std::string nameSchool) {
		this->nameSchool = nameSchool;
		takesStudents();
		//takesReports();
	};

	void takesStudents() {
		std::ifstream Myfile("../data/students.txt");
		std::string text{};
		if (Myfile.is_open()) {
			// read file
			while (std::getline(Myfile, text)) {
				std::cout << text << std::endl;

				int i = 0; 

				std::vector<std::string > elements{};

				int count = 0;
				for (int j = 0; j < text.length(); j++) {
					if (text[j] == ',') {
						if (count == 0) {
							elements.push_back(text.substr(i, (j - i)));
							count += 1;
							i = j;
						}
						else {
							elements.push_back(text.substr(i+1, (j - i-1)));
							i = j;
						}
						
					}
				}

				for (int k = 0; k < elements.size(); k++) {
					std::cout << "Elements : " << elements[k] << std::endl;
				}

				Student student;
				student.setId(std::stoi(elements[0]));
				student.setFirstName(elements[1]);
				student.setLastName(elements[2]);
				//student.setBirthDate(elements[3]);

				students.push_back(student);

			}
		}

		Myfile.close();
		std::cout << "\nClose file! " << std::endl;
	}


	std::vector<std::string> takesAllIdStudent() {
		std::vector<std::string> result{};
		std::string text{};
		std::string id{};
		std::ifstream Myfile("../data/students.txt");
		if (Myfile.is_open()) {
			// read file
			while (std::getline(Myfile, text)) {
				int i = 0;
				for (int j = 0; j < text.length(); j++) {
					if (text[j] == ',') {
						id = text.substr(i, (j-i));
						break;
					}
				}				
				result.push_back(id);
			}
		}
		Myfile.close();

		/*
		std::cout << "Id's find: ";
		for (std::string id : result) {
			std::cout << id << std::endl;
		}
		*/
		
		return result;
	}

	
	void takesReports() {
		std::ifstream Myfile("../data/reports.txt");
		std::string text{};
		Report rep{};
		if (Myfile.is_open()) {
			// read file
			while (std::getline(Myfile, text)) {
				std::vector<std::size_t> positionsC{};  // posizioni delle virgole per QUESTA riga
				std::size_t pos = 0;
				while ((pos = text.find(',', pos)) != std::string::npos) {
					positionsC.push_back(pos);
					++pos; // avanza per evitare match infinito sulla stessa virgola
				}

				if (positionsC.size() > 1) {
					rep.setId(std::stoi(text.substr(0, positionsC[0])));
					rep.setIdStud(std::stoi(text.substr(positionsC[0] + 1, positionsC[1] - positionsC[0]-1)));

					// take records: difficult 
					std::size_t posSpaceBlank = 0;
					std::vector<std::size_t> positionsSpaceBlank{};  // posizioni dei spazi bianchi che separano le materie per QUESTA riga
					while ((posSpaceBlank = text.find(' ', posSpaceBlank)) != std::string::npos) {
						positionsSpaceBlank.push_back(posSpaceBlank);
						++posSpaceBlank; // avanza per evitare match infinito sulla stessa virgola
					}

					if (positionsSpaceBlank.size() > 1) {
						std::string recordText = text.substr(positionsC[1] + 1, positionsSpaceBlank[0] - 1);

					}

				}


				// take all reports
				//std::string student = text;
				//reports.push_back(rep);
			}
		}
		Myfile.close();
	}
	

	


	bool checkIfStudentExist(Student student) {
		std::vector<std::string> ids = takesAllIdStudent();
		for (int i = 0; i < ids.size(); i++) {
			if (std::stoi(ids[i]) == student.getId()) {
				std::cout << "Student already exist! " << std::endl;
				return true;
			}
		}
		return false;
	}


	void addNewStudent(Student student) {

		// Check if student already exist
		bool studentExist = checkIfStudentExist(student);
		if (studentExist == true) {
			std::cout << "Fine!" << std::endl;
			return;
		}

		std::ofstream Myfile;
		Myfile.open("../data/students.txt", std::ios_base::app);
		if (Myfile.is_open()) {
			Myfile << student.getId() << "," << student.getFirstName() << "," << student.getLastName() << "," << student.getBirthDate() << "\n";
			Myfile.close();
		}

		students.push_back(student);
	}


	
	void addNewReport(Report report) {

		// Check if report already exist

		std::ofstream Myfile;
		Myfile.open("../data/reports.txt", std::ios_base::app);
		if (Myfile.is_open()) {
			Myfile << report.getId() << "," << report.getIdStud() << ",";
			for (auto record : report.getRecords()) {
				Myfile << record.first << ":";
				int i = 0;
				for (auto rec : record.second) {
					i += 1;
					if (i == record.second.size()) {
						Myfile << rec;
					}
					else { Myfile << rec << "-"; }
				}
				Myfile << " ";
			}
			Myfile << "\n";
			Myfile.close();
		}

		reports.push_back(report);
	}

	void deleteStudent(Student student) {
		// Check if student already exist
		if (!checkIfStudentExist(student)) {
			std::cout << "Student not found!" << std::endl;
			return;
		}

		std::ifstream Myfile("../data/students.txt");
		std::vector<std::string> lines;
		std::string text;

		if (Myfile.is_open()) {
			while (std::getline(Myfile, text)) {
				// Prendo l'ID dalla riga (prima della virgola)
				std::string::size_type pos = text.find(',');
				std::string id = text.substr(0, pos);

				// Se NON è lo studente da cancellare, salvo la riga
				if (id != std::to_string(student.getId())) {
					lines.push_back(text);
				}
			}
			Myfile.close();
		}

		// Riscrivo il file senza lo studente
		std::ofstream Outfile("../data/students.txt", std::ios::trunc);
		for (const auto& line : lines) {
			Outfile << line << "\n";
		}
		Outfile.close();

		// Rimuovo anche dal vettore in memoria
		for (auto it = students.begin(); it != students.end(); ++it) {
			if (it->getId() == student.getId()) {
				students.erase(it);
				break;
			}
		}

		std::cout << "Student deleted successfully!" << std::endl;
	}



	void modifyStudent(Student student) {
		// Check if student already exist
		bool studentExist = checkIfStudentExist(student);
		if (studentExist == true) {
			// work
		}
	}


	void deleteReport(Report report) {
		
		std::ifstream Myfile("../data/reports.txt");
		std::string text{};

		std::vector<std::string> newTextFile{};

		if (Myfile.is_open()) {
			while (std::getline(Myfile, text)) {
				std::vector<std::size_t> positionsC{};  // posizioni delle virgole per QUESTA riga
				std::size_t pos = 0;
				while ((pos = text.find(',', pos)) != std::string::npos) {
					positionsC.push_back(pos);
					++pos; // avanza per evitare match infinito sulla stessa virgola
				}

				if (positionsC.size() > 1) {
					std::string idReport = text.substr(0, positionsC[0]);
					int idReportInt = std::stoi(idReport);
					if (report.getId() != idReportInt) {
						std::cout << "!!!!!" << text << std::endl;
						newTextFile.push_back(text);
					}
				}
			
			}
			Myfile.clear();
		}
		Myfile.close();

		// Recreate the file without the report to erase.
		std::ofstream Outfile("../data/reports.txt");
		for (const auto& line : newTextFile) {
			Outfile << line << "\n";
		}
		Outfile.close();

		// Rimuovo anche dal vettore in memoria
			for (auto it = reports.begin(); it != reports.end(); ++it) {
				if (it->getId() == report.getId()) {
					reports.erase(it);
					break;
				}
			}

		std::cout << "Report deleted successfully!" << std::endl;




	
	}
	//void modifyReport(Report report) {}


	std::vector<Student> searchStudentFirstName(const std::string& firstName) {
		std::ifstream Myfile("../data/students.txt");
		std::vector<Student> result;
		std::string text;

		if (Myfile.is_open()) {

			while (std::getline(Myfile, text)) {
				std::vector<std::size_t> positionsC;  // posizioni delle virgole per QUESTA riga
				std::size_t pos = 0;
				while ((pos = text.find(',', pos)) != std::string::npos) {
					positionsC.push_back(pos);
					++pos; // avanza per evitare match infinito sulla stessa virgola
				}

				if (positionsC.size() < 2) continue; // servono almeno ID, FirstName, ...

				// Estrai i campi principali
				std::string idStr = text.substr(0, positionsC[0]);
				std::string firstField = text.substr(positionsC[0] + 1, positionsC[1] - positionsC[0] - 1);

				if (firstField == firstName) {
					Student st;
					st.setId(std::stoi(idStr));
					st.setFirstName(firstField);

					if (positionsC.size() >= 3) {
						st.setLastName(text.substr(positionsC[1] + 1, positionsC[2] - positionsC[1] - 1));
					}
					else {
						// se non c'è la terza virgola, prendi fino a fine riga
						st.setLastName(text.substr(positionsC[1] + 1));
					}

					result.push_back(st);
				}
			}
		}
		return result;
	}

	std::vector<Student> searchStudentLastName(std::string lastName) {
		std::ifstream Myfile("../data/students.txt");
		std::vector<Student> result;
		std::string text;

		if (Myfile.is_open()) {

			while (std::getline(Myfile, text)) {
				std::vector<std::size_t> positionsC;  // posizioni delle virgole per QUESTA riga
				std::size_t pos = 0;
				while ((pos = text.find(',', pos)) != std::string::npos) {
					positionsC.push_back(pos);
					++pos; // avanza per evitare match infinito sulla stessa virgola
				}

				if (positionsC.size() < 2) continue; // servono almeno ID, FirstName, ...

				// Estrai i campi principali
				std::string idStr = text.substr(0, positionsC[0]);
				std::string secondField = text.substr(positionsC[1] + 1, positionsC[2] - positionsC[1] - 1);


				if (secondField == lastName) {
					Student st;
					st.setId(std::stoi(idStr));
					st.setLastName(secondField);

					st.setFirstName(text.substr(positionsC[0] + 1, positionsC[1] - positionsC[0] - 1));

					result.push_back(st);
				}
			}
		}
		return result;
	}
	
	
	
	Student searchStudentId(int id) {
		std::ifstream Myfile("../data/students.txt");
		Student studRes{};
		std::string text;

		if (Myfile.is_open()) {

			while (std::getline(Myfile, text)) {
				std::vector<std::size_t> positionsC;  // posizioni delle virgole per QUESTA riga
				std::size_t pos = 0;
				while ((pos = text.find(',', pos)) != std::string::npos) {
					positionsC.push_back(pos);
					++pos; // avanza per evitare match infinito sulla stessa virgola
				}

				if (positionsC.size() < 2) continue; // servono almeno ID, FirstName, ...

				// Estrai id
				std::string idStr = text.substr(0, positionsC[0]);
				int idFile = std::stoi(idStr);

				if (idFile == id) {
					studRes.setId(std::stoi(idStr));
					studRes.setFirstName(text.substr(positionsC[0] + 1, positionsC[1] - positionsC[0] - 1));
					studRes.setLastName(text.substr(positionsC[1] + 1, positionsC[2] - positionsC[1] - 1));
					return studRes;
				}
			}
		}
		return studRes;
	}

	//std::vector < std::map<int, std::vector<float>>> searchGradesStudents(std::string subject) {}


	// Getter and Setter


};





#endif // !SYSTEM_SCHOOL_H
