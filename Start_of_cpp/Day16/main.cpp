#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"

using namespace std;


void addEmployee(vector<Employee>& vEmployee)
{
	int _eNo;
	string _name, _staff;

	cout << "Please enter your employee no: ";
	cin >> _eNo;
	cin.ignore();

	cout << "Please enter your employee name: ";
	getline(cin, _name);

	cout << "Please enter your employee staff: ";
	cin >> _staff;

	//vEmployee.push_back(Employee(_eNo, _name, _staff));
	vEmployee.emplace_back(_eNo, _name, _staff);

	cout << "Employee added successfully!" << endl;
}

void listingEmployee(const vector<Employee>& vEmployee)
{
	if (vEmployee.empty()) 
	{
		cout << "The employee list is empty!" << endl;
		return;
	}
	cout << "--- Employee list ---" << endl;
	for (const auto& e : vEmployee)
	{
		e.printInformation();
	}
}

void searchEmployee(const vector<Employee>& vEmployee)
{
	int _eNo;
	cout << "Please enter your employee no for search employee: ";
	cin >> _eNo;

	for (const auto& e : vEmployee)
	{
		if (_eNo == e.getEmployeeNo())
		{
			cout << "The personnel you are looking for has been found in the system. Information:" << endl;
			e.printInformation();
			return;
		}
		cout << "The personnel you are looking for has been not found in the system." << endl;
	}

}

void deleteEmployee(vector<Employee>& vEmployee)
{
	int _eNo;
	cout << "Please enter your employee no for search employee: ";
	cin >> _eNo;

	for (auto it = vEmployee.begin(); it != vEmployee.end(); it++)
	{
		if (_eNo == it->getEmployeeNo())
		{
			vEmployee.erase(it);
			cout << "Employee deleted successfully." << endl;
			return;
		}
	}
	cout << "The personnel you are looking for has been not found in the system." << endl;
}

int main() {

	// Step 1 Create Employee class
	
	Employee emp1(20, "Ahmet", "Mudur");

	emp1.printInformation();

	emp1.setEmployeeNo(10);
	emp1.setName("ihsan");
	emp1.setStaff("Memur");

	emp1.printInformation();

	cout << emp1.getEmployeeNo() << endl;
	cout << emp1.getName() << endl;
	cout << emp1.getStaff() << endl;
	

	// Step 2 Create vector and testing
	
	vector<Employee> vEmployees;

	vEmployees.push_back(Employee(10, "Ayse", "Memur"));
	vEmployees.push_back(Employee(20, "Mehmet", "Memur"));
	vEmployees.push_back(Employee(30, "Hasan", "Memur"));
	vEmployees.push_back(Employee(40, "Tarik", "Mudur"));

	

	//vEmployees[0].printInformation();

	vEmployees.erase(vEmployees.begin() + 0);


	for (Employee& e : vEmployees) {
		e.printInformation();
	}
	

	// Step 3 Create a function for get employee data, First Way
	
	vector<Employee> vEmployee;
	int userValue;

	do {
		
		cout << "---- Personnel management system ----" << endl;
		cout << "1. Add Employee" << endl;
		cout << "2. Print Employee" << endl;
		cout << "3. Search Employee" << endl;
		cout << "4. Delete Employee" << endl;
		cout << "5. Close System" << endl;
		cout << "Make your choice: ";
		cin >> userValue;

		if (userValue == 1) {
			Employee emp(0,"","");
			int _eNo;
			string _name, _staff;

			cout << "Please enter your employee no: ";
			cin >> _eNo;
			cin.ignore();

			cout << "Please enter your employee name: ";
			getline(cin, _name);

			cout << "Please enter your employee staff: ";
			cin >> _staff;

			emp.setEmployeeNo(_eNo);
			emp.setName(_name);
			emp.setStaff(_staff);

			vEmployee.push_back(emp);
		}
		
		else if (userValue == 2)
		{
			for (Employee& e : vEmployee)
			{
				e.printInformation();
			}
		}

		else if (userValue == 3)
		{
			int _eNo;
			cout << "Please enter your employee no for search employee: ";
			cin >> _eNo;

			for(Employee& e: vEmployee)
			{
				if (_eNo == e.getEmployeeNo())
				{
					e.printInformation();
					break;
				}
			}
		}
		
		else if (userValue == 4)
		{
			int _eNo;
			cout << "Please enter your employee no for delete employee: ";
			cin >> _eNo;

			for (auto it = vEmployee.begin(); it != vEmployee.end(); ++it)
			{
				if (_eNo == it->getEmployeeNo())
				{
					vEmployee.erase(it);
					cout << "Employee deleted successfully." << endl;
					break;
				}
			}
		}
		else if (userValue == 5)
		{
			cout << "Exiting the system..." << endl;
		}
		else
		{
			cout << "You did not enter a value between 1 and 5. Please enter a value between 1 and 5!" << endl;
		}
		

	} while (userValue != 5);
	

	// Second Way

	vector<Employee> vEmployee;
	int userValue;

	do {

		cout << "---- Personnel management system ----" << endl;
		cout << "1. Add Employee" << endl;
		cout << "2. Print Employee" << endl;
		cout << "3. Search Employee" << endl;
		cout << "4. Delete Employee" << endl;
		cout << "5. Close System" << endl;
		cout << "Make your choice: ";
		cin >> userValue;

		switch (userValue)
		{
		case 1:
			addEmployee(vEmployee);
			break;
		case 2:
			listingEmployee(vEmployee);
			break;
		case 3:
			searchEmployee(vEmployee);
			break;
		case 4:
			deleteEmployee(vEmployee);
		case 5:
			cout << "Exiting the system..." << endl;
			break;

		default:
			cout << "You did not enter a value between 1 and 5. Please enter a value between 1 and 5!" << endl;
		}


	} while (userValue != 5);
	return 0;
}