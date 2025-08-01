#include <iostream>

#include "Employee.h"
#include "PayrollSystem.h"

using namespace std;

int main() {
    PyrollSystem system;
    int choice;

    while (true) {
        cout << "\n==== Payroll System Menu ====\n";
        cout << "1. Add Employee\n";
        cout << "2. Update Hours Worked\n";
        cout << "3. Update Deductions\n";
        cout << "4. Update Bonus\n";
        cout << "5. Print Payroll Report\n";
        cout << "6. Exit\n";
        cout << "Select: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addEmployee();
            break;
        case 2:
            system.updateHours();
            break;
        case 3:
            system.updateDeductions();
            break;
        case 4:
            system.updateBonus();
            break;
        case 5:
            system.printPayrollReport();
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}