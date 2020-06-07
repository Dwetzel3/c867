#include "student.h"

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getNumOfDays()
{
	return numOfDays;
}

Degree Student::getDegree()
{
	return degree;
}

void Student::setStudentID(string ID)
{
	studentID = ID;
}

void Student::setFirstName(string firstN)
{
	firstName = firstN;
}

void Student::setLastName(string lastN)
{
	lastName = lastN;
}

void Student::setEmailAddress(string email)
{
	emailAddress = email;
}

void Student::setAge(int studentAge)
{
	age = studentAge;
}

void Student::setNumDays(int days[]) {
	for (int i = 0; i < 3; ++i) {
		numOfDays[i] = days[i];
	}
}


Student::Student()
{
	studentID = "Empty";
	firstName = "Empty";
	lastName = "Empty";
	emailAddress = "Empty";
	age = -1;
	numOfDays[0] = 0;
	numOfDays[1] = 0;
	numOfDays[2] = 0;
}

Student::Student(string ID, string firstN, string lastN, string email, int studentAge, int days[3], Degree studentDegree) {
	studentID = ID;
	firstName = firstN;
	lastName = lastN;
	emailAddress = email;
	age = studentAge;
	setNumDays(days);
	degree = degree;
};

void Student::print()
{
	cout << studentID << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Age: " << getAge() << "  ";
	cout << "Days In Course: {" << numOfDays[0] << ", " << numOfDays[1] << ", " << numOfDays[2] << "}" << "\t";
	cout << "Degree Program: ";
	if (getDegree() == SOFTWARE) {
		cout << "SOFTWARE" << endl;
	}
	else if (getDegree() == SECURITY) {
		cout << "SECURITY" << endl;
	}
	else if (getDegree() == NETWORK) {
		cout << "NETWORK" << endl;
	}
	return;
}

Student::~Student() {}