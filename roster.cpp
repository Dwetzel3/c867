#include <iostream>
#include <sstream>
#include <vector>
#include "student.h"
#include "roster.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "degree.h"

using namespace std;

const int studentDataSize = (sizeof(studentData) / sizeof(*studentData));

int main() {
	cout << "Scripting And Programming - Applications - C867" << endl;
	cout << "Programmed With C++" << endl;
	cout << "Student ID: #000975667" << endl;
	cout << "Daniel Wetzel" << endl << endl;

	Roster studentRoster;

	for (int i = 0; i < studentDataSize; i++) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string column[9];

		int a = 0;
		while (getline(ss, token, ',')) {
			column[a] = token;
			a += 1;
		}

		Degree degree;
		if (column[8] == "NETWORK") {
			degree = NETWORK;
		}
		else if (column[8] == "SECURITY") {
			degree = SECURITY;
		}
		else if (column[8] == "SOFTWARE") {
			degree = SOFTWARE;
		}

		studentRoster.add(column[0], column[1], column[2], column[3], stoi(column[4]), stoi(column[5]), stoi(column[6]), stoi(column[7]), degree);
	}
	cout << "Roster:" << endl;
	studentRoster.printAll();
	cout << endl;

	cout << "Invalid Emails:" << endl;
	studentRoster.printInvalidEmails();
	cout << endl;

	cout << "Average Days In Course:" << endl;
	for (int i = 0; i < studentDataSize; ++i) {
		studentRoster.printAverageDaysInCourse(studentRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "Students In Software Degree Program:" << endl;
	studentRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	studentRoster.remove("A3");
	studentRoster.remove("A3");
	cout << endl;

	cout << "Roster:" << endl;
	studentRoster.printAll();

	studentRoster.~Roster();
	system("pause");
}

void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int days1,
	int days2,
	int days3,
	Degree degree) {
	int days[3] = { days1, days2, days3 };
	int i = 0;
	while (classRosterArray[i] != nullptr) {
		i++;
	}
	if (degree == SOFTWARE) {
		classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
	}
	else if (degree == SECURITY) {
		classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
	}
	else if (degree == NETWORK) {
		classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
	}
};

void Roster::remove(string studentID) {
	cout << "Removing Student: " << studentID << "... ";
	for (int i = 0; i < studentDataSize; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "A Student With This ID Was Not Found." << endl;
			break;
		}
		else if (studentID == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			cout << "Student Removed." << endl;
		}
	}
};

void Roster::printAll() {
	for (int i = 0; i < studentDataSize; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
};

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < studentDataSize; ++i) {
		if (studentID == classRosterArray[i]->getStudentID()) {
			int* days = classRosterArray[i]->getNumOfDays();
			cout << studentID << " ";
			cout << (((double)days[0] + (double)days[1] + (double)days[2]) / numDays) << endl;
		}
	}
};

void Roster::printInvalidEmails() {
	vector<string> invalidEmails;
	for (int i = 0; i < studentDataSize; ++i) {
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find('@') != string::npos)
		{
			if (email.find('.') != string::npos) {
				if (email.find(' ') != string::npos) {
					cout << email << " is an invalid email!" << endl;
				}
			}
		}
		else
		{
			cout << email << " is an invalid email!" << endl;
		}
	}
};

void Roster::printByDegreeProgram(Degree degree) {
	for (int i = 0; i < studentDataSize; ++i) {
		Student* student = classRosterArray[i];
		if (student->getDegree() == degree) {
			student->print();
		}
	}
};

Roster::~Roster() {};