#include <iostream>
#include "ErrorClass.h"

using namespace std;


int main() {
	// Video 28.136
	
	try {
		throw ErrorClass("Error Message no:1");
	}
	catch (ErrorClass e) {
		cout << "Exception caught! Custom error message: " << e.getErrorMessage() << endl;
	}
	

	// Video 28.137 and 28.138
	
	try {
		int x;
		cout << "Enter the x value: ";
		cin >> x;
		if (x < 0)
			throw ErrorClass("Error Message no: 1");
		else if (x == 0)
			throw 101;
		cout << "End Of Try... x: " << x << endl;
	}
	
	catch (...) {
		cout << "Exception caught!" << endl;
	}

	catch (ErrorClass e) {
		cout << "Exception caught! Custom error message: " << e.getErrorMessage() << endl;
	}
	catch (int ErrorCode) {
		cout << "Exception caught! Error Code: " << ErrorCode << endl;
	}
	

	return 0;
}