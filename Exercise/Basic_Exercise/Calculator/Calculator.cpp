#include "Calculator.h"

double Calculator::add(double a, double b)
{
	return a + b;
}

double Calculator::subtraction(double a, double b)
{
	return a - b;
}

double Calculator::Multiplication(double a, double b)
{
	return a * b;
}

double Calculator::division(double a, double b)
{
	return a / b;
}

double Calculator::mod(int a, int b)
{
	return (a % b);
}

double Calculator::pow(double a, double b)
{
	for (int i = 0; i < b-1; i++)
	{
		a *= a;
	}
	return a;
}

double Calculator::absoluteValue(double a)
{
	if (a < 0)
	{
		return a * -1;
	}
	else
		return a;
}