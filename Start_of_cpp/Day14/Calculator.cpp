#include <iostream>

using namespace std;

int main2() {

	// Video 28.134
	/*
	try {
		int age;
		cout << "Your Age: ";
		cin >> age;

		if (age >= 18) {
			cout << "You can access it.";
		}
		else {
			throw (age);
		}
	}
	catch (int ErrorNo) {
		cout << "You cannot access it, you must be at least 18 years old.\n";
		cout << "Age: " << ErrorNo;
	}
	*/

	// Video 28.135
	/*
	try {
		int x = 30;
		int y;
		cout << "Please enter a positive number: ";
		cin >> y;

		if (y == 0)
			throw 100;
		else if (y < 0)
			throw 101;
		else {
			int z = x / y;
			cout << z << endl;
		}
	}
	catch (int ErrorCode) {
		//cout << "An exception occurred, error code: " << ErrorCode << endl;
		if (ErrorCode == 101) {
			cout << "Negative value entered!";
		}
		else if (ErrorCode == 100) {
			cout << "0 value entered!";
		}
	}
	*/

	return 0;
}