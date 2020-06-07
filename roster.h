#pragma once
#include "degree.h"

string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Daniel,Wetzel,dwetze3@wgu.edu,31,12,25,45,SOFTWARE" };

class Roster {
private:
public:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int days1,
		int days2,
		int days3,
		Degree degree);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degree);
	~Roster();
};