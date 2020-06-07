#pragma once
#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student
{
private:
	Degree degree = SOFTWARE;
public:
	using Student::Student;
	Degree getDegree() override;
	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, Degree degree);
	~SoftwareStudent();
};