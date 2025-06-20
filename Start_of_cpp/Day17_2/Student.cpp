#include <iostream>
#include "Student.h"

Student::Student(int _sID, string _sName, int sqr) : sID(_sID), sName(_sName), sQuizResult(sqr) {}

void Student::printInfo() 
{
	cout << "Student ID: " << Student::sID << " Student name: " << Student::sName << " Students result of quiz: " << Student::sQuizResult << endl;
}

void Student::setSID(int _sID)
{
	sID = _sID;
}
void Student::setSName(string _sName)
{
	sName = _sName;
}
void Student::setSQuizResult(int sqr)
{
	sQuizResult = sqr;
}

int Student::getSID()
{
	return sID;
}
string Student::getSName()
{
	return sName;
}
int Student::getSQuizResult()
{
	return sQuizResult;
}