#pragma once
#include <iostream>

using namespace std;

class Employee {

private:
	int employeeNo;
	string name;
	string staff;
public:
	//Employee(int eNo, string _name, string _staff) : employeeNo(eNo), name(_name), staff(_staff) {}
	
	Employee(int employeeNo, string name, string staff);

	void printInformation() const;

	int getEmployeeNo() const;
	void setEmployeeNo(int _eNo);

	string getName() const;
	void setName(string _name);

	string getStaff() const;
	void setStaff(string _staff);
		
};