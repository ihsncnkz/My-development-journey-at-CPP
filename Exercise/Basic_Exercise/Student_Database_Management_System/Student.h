#pragma once

#pragma once
#include <iostream>
using namespace std;
class Student
{
private:
	int id;
	string studentName;
	string studentLastName;

public:
	Student();

	Student(int _id, string sn, string sln);

	void setId(int _id);
	int getId();

	void setStudentName(string sn);
	string getStudentName();

	void setStudentLastName(string sln);
	string getStudentLastName();

	void printInfo() const;
};