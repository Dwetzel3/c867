#include "securityStudent.h"

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, Degree degree) {};
SecurityStudent::~SecurityStudent() {};

Degree SecurityStudent::getDegree()
{
	return degree;
}