#pragma once
#include <iostream>


using namespace std;

class ErrorClass {

private:
	string errorMessage;

public:
	ErrorClass(string _errorMessage);
	string getErrorMessage();

};