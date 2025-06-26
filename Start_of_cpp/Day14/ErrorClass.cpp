#include <iostream>
#include "ErrorClass.h"

using namespace std;

ErrorClass::ErrorClass(string _ErrorMessage) : errorMessage(_ErrorMessage) {}

string ErrorClass::getErrorMessage() {
	return errorMessage;
}