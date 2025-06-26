#include <iostream>
#include "Calculator.h"

using namespace std;

int main()
{
	Calculator mathCall;

	cout << mathCall.add(5,5) << endl;
	cout << mathCall.subtraction(5, 5) << endl;
	cout << mathCall.Multiplication(5, 5) << endl;
	cout << mathCall.division(5, 5) << endl;
	cout << mathCall.mod(12, 5) << endl;
	cout << mathCall.pow(5, 2) << endl;
	cout << mathCall.absoluteValue(-5) << endl;
	return 0;
}