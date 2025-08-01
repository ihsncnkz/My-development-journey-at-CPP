#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Employee.h"

using namespace std;

class PyrollSystem
{
public:
	vector<Employee> employees;
	int nextId = 1;


	void addEmployee();

	Employee* findEmployeeById(int id);

	void updateHours();

	void updateDeductions();

	void updateBonus();

	void printPayrollReport() const;
};