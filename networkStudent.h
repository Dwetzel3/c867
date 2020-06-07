#pragma once
#include "student.h"
#include "degree.h"

class NetworkStudent : public Student
{
private:
	Degree degree = NETWORK;
public:
	using Student::Student;
	Degree getDegree() override;
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, Degree degree);
	~NetworkStudent();
};