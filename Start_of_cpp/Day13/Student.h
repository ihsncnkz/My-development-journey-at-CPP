#pragma once
#include <iostream>

using namespace std;

class Student {
private:
	int quiz1;
	int quiz2;
	string name;

public:
	Student(string _name, int _quiz1, int _quiz2);
	friend class Calculator;

};