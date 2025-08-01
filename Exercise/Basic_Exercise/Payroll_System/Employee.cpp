#include "Employee.h"

Employee::Employee(int _eID, string _eName, double _hR) : 
eID(_eID), eName(_eName), hourlyRate(_hR), hoursWorked(0), bonus(0){}

double Employee::calculateGrossSalary() const
{
	return hourlyRate * hourlyRate + bonus;
}

double Employee::calculateNetSalary() const
{
	return calculateGrossSalary() - deducate;
}