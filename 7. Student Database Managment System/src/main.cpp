#include "../hpp/Report.hpp"
#include "../hpp/Student.hpp"
#include "../hpp/SystemSchool.hpp"

#include <string>
#include <iostream>
#include <ctime>

int main() {

	struct tm datetime;
	time_t timestamp;

	datetime.tm_year = 2002; 
	datetime.tm_mon = 9; 
	datetime.tm_mday = 12;
	// Daylight Savings must be specified
	// -1 uses the computer's timezone setting
	datetime.tm_isdst = -1;

	timestamp = mktime(&datetime);

	Student student = Student("Eva Lea", "Cali", timestamp);
	Student student1 = Student("Federico", "Ferdinandi", timestamp);
	
	student.toString();
	student1.toString();

	Report report = Report(1, 2);
	std::map<std::string, std::vector<float>> record = { {"Italiano",{8.0, 9.0, 10.0}} };
	report.setRecords(record);
	report.toString();

	std::cout << "\n\n\n";

	SystemSchool syst = SystemSchool("University");

	syst.addNewStudent(student);
	syst.addNewStudent(student1);
	//syst.addNewStudent(student1);

	//syst.deleteStudent(student);

	std::vector<Student> findF = syst.searchStudentFirstName("Federico");
	for (Student st : findF) {
		std::cout << st.getId() << ", " << st.getFirstName() << ", " << st.getLastName();
	}

	syst.addNewReport(report);

	Report report1 = Report(2, 2);
	std::map<std::string, std::vector<float>> record1 = { {"Matematica",{10.0, 10.0, 10.0}}, {"Informatica", {10.0, 10.0}} };

	report1.setRecords(record1);
	syst.addNewReport(report1);

	syst.deleteReport(report);

	std::cout << "\n";

	//syst.takesAllIdStudent();
	//syst.takesStudents();

	//for (Student stud : syst.students) {
//		stud.toString();
	//}

	//std::cout << syst.students.size();

}