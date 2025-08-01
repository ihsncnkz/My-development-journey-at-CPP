#pragma once

#include <iostream>

using namespace std;

class Employee
{
public:
	int eID;
	string eName;
	string eSurName;
	double hourlyRate;
	double hoursWorked;
	double deducate;
	double bonus;

	Employee(int _eID, string _eName, double _hR);

	double calculateGrossSalary() const;

	double calculateNetSalary() const;

};