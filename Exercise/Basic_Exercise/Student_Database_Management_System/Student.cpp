#include "Student.h"

Student::Student()
{
}

Student::Student(int _id, string sn, string sln) : id(_id), studentName(sn), studentLastName(sln)
{
}

void Student::setId(int _id)
{
	id = _id;
}

int Student::getId()
{
	return id;
}

void Student::setStudentName(string sn)
{
	studentName = sn;
}

string Student::getStudentName()
{
	return studentName;
}

void Student::setStudentLastName(string sln)
{
	studentLastName = sln;
}

string Student::getStudentLastName()
{
	return studentLastName;
}

void Student::printInfo() const
{
	cout << "Id: " << id << endl;
	cout << "Student Name: " << studentName << endl;
	cout << "Student Last Name: " << studentLastName << endl;
}
