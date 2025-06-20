#pragma once

#include <iostream>

using namespace std;

class Student {

private:
	int sID;
	string sName;
	int sQuizResult;

public:

	Student(int _sID, string _sName, int sqr);

	void printInfo();

	void setSID(int _sID);
	void setSName(string _sName);
	void setSQuizResult(int sqr);

	int getSID();
	string getSName();
	int getSQuizResult();


};