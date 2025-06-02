#include <iostream>

using namespace std;

int main()
{
	/*
	This long comment area.
	*/

	// This code is the same as below: cout << "Hello c++ Programing language\n"
	cout << "Hello c++ Programing language" << endl;

	// 2.4 Video from my course
	
	string name; // declaration
	name = "Ali"; // initialization
	
	int age = 22; // declaration and initialization

	cout << "Once upon a time there was a young man named " << name << "." << endl << "He was " << age << " years old." << endl;

	name = "Veli";
	age = 25;

	cout << name << " liked her name but He didn't like her age of " << age << ". He wanted to be older.\n";
	
	// 2.7, 2.8, 2.9 Video from my course
	
	int birthYear = 1980;
	string name = "Kaan Kaya";
	float numericalGradePointAverage = 3.47f; // have to write 'f' beacause if we cant write 'f' The computer think double.
	double pi = 3.1415926535;
	bool isSuccessful = true;
	char gradePointLatter = 65; // the 65 of means is 'a' at the ascii table.

	float quizPoint1 = 72.f;
	int quizPoint2 = 51;
	//float quizAvreage = (float) (quizPoint1 + quizPoint2) / 2;
	float quizAvreage = (quizPoint1 + quizPoint2) / 2;

	cout << "Hello " << name << endl;
	cout << "Birth year: " << birthYear << endl;
	cout << "Numerical Grade Point Average: " << numericalGradePointAverage << endl;
	cout << "isSuccessful: " << isSuccessful << endl;
	cout << "Grade Point Latter : " << gradePointLatter << endl;
	
	cout << "Avreage of quizs: " << quizAvreage << endl;
	

	int x = 10;
	int y = 20;
	int z = 12 % 10; // % : mod (modulus) operator
	cout << z << endl;


	return 0;
}