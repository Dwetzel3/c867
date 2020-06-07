#pragma once
#include <iostream>
#include "degree.h"
#include <string>
using namespace std;

const int numDays = 3;

class Student {
protected: // variables for student class
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numOfDays[3];
	Degree degree;
public:
	Student();
	Student(string ID, string firstN, string lastN, string email, int studentAge, int days[], Degree studentDegree);
	//Accessors(Getters) for student class
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumOfDays();
	virtual Degree getDegree();
	//Mutators(Setters) for student class
	void setStudentID(string ID);
	void setFirstName(string firstN);
	void setLastName(string lastN);
	void setEmailAddress(string email);
	void setAge(int studentAge);
	void setNumDays(int days[]);

	~Student();
	virtual void print();
};