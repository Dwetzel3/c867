#pragma once
#include "student.h"
#include "degree.h"

class SecurityStudent : public Student
{
private:
	Degree degree = SECURITY;
public:
	using Student::Student;
	Degree getDegree() override;
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, Degree degree);
	~SecurityStudent();
};