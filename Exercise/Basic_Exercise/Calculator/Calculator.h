#pragma once
#include <iostream>

using namespace std;

class Calculator
{
public:
	double add(double a, double b);
	double subtraction(double a, double b);
	double Multiplication(double a, double b);
	double division(double a, double b);
	double mod(int a, int b);
	double pow(double a, double b);
	double absoluteValue(double a);
};