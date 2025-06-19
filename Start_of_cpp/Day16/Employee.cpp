#include "Employee.h"

Employee::Employee(int eNo, string _name, string _staff) : employeeNo(eNo), name(_name), staff(_staff) {}

void Employee::printInformation() const {
	cout << "Employee no: " << Employee::employeeNo << " Name : " << Employee::name << " Staff: " << Employee::staff << endl;
}

void Employee::setEmployeeNo(int _eNo) {
	employeeNo = _eNo;
}

int Employee::getEmployeeNo() const {
	return employeeNo;
}

void Employee::setName(string _name) {
	name = _name;
}

string Employee::getName() const {
	return name;
}

void Employee::setStaff(string _staff) {
	staff = _staff;
}

string Employee::getStaff() const {
	return staff;
}