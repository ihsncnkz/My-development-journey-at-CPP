#include "PayrollSystem.h"

void PyrollSystem::addEmployee()
{
	string name;
	double hourlyRate;

	cout << "Enter employee name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter hourly rate: ";
	cin >> hourlyRate;

	employees.emplace_back(nextId++, name, hourlyRate);
	cout << "Employee added! ID: " << nextId - 1 << endl;
}

Employee* PyrollSystem::findEmployeeById(int id)
{
	for (auto& emp : employees)
	{
		if (emp.eID == id)
		{
			return &emp;
		}
	}
	return nullptr;
}

void PyrollSystem::updateHours()
{
	int id;
	double hours;

	cout << "Enter employee ID: ";
	cin >> id;
	Employee* emp = findEmployeeById(id);

	if (emp)
	{
		cout << "Enter hours worked: ";
		cin >> hours;
		emp->hoursWorked += hours;
		cout << "Update hours. Total: " << emp->hoursWorked << endl;
	}
	else
	{
		cout << "Employee not found!" << endl;
	}
}

void PyrollSystem::updateDeductions()
{
	int id;
	double deduction;
	cout << "Enter employee ID: ";
	cin >> id;

	Employee* emp = findEmployeeById(id);

	if (emp)
	{
		cout << "Enter deduction amount: ";
		cin >> deduction;
		emp->deducate += deduction;
		cout << "Deducation update. Total: " << emp->deducate << endl;
	}
	else
	{
		cout << "Employee not found!" << endl;
	}
}

void PyrollSystem::updateBonus()
{
	int id;
	double bonus;
	cout << "Enter employee ID: ";
	cin >> id;

	Employee* emp = findEmployeeById(id);
	if (emp)
	{
		cout << "Enter bonus amount: ";
		cin >> bonus;
		emp->bonus += bonus;
		cout << "Bonus update. Total: " << emp->bonus << endl;
	}
	else 
	{
		cout << "Employee not found!" << endl;
	}
}

void PyrollSystem::printPayrollReport() const
{
	cout << "\n========== Payroll Report ==========\n";
	cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Gross" << setw(10) << "Deductions" << setw(10) << "Bonus" << setw(10) << "Net" << endl;
	cout << "---------------------------------------------------------------\n";
	for (const auto& emp : employees) 
	{
		cout << left << setw(5) << emp.eID
			<< setw(20) << emp.eName
			<< setw(10) << emp.calculateGrossSalary()
			<< setw(10) << emp.deducate
			<< setw(10) << emp.bonus
			<< setw(10) << emp.calculateNetSalary() << endl;
	}
	cout << "====================================\n";
}
