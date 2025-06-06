#include <iostream>
#include <cstdlib> // If you dont use visual studio 2022 you have to import this library! for use rand function!
#include <ctime> // for time fonction. If you dont use visual studio 2022 you have to import this library!

using namespace std;

// Video 6.37
int calculate(int x) {
	int result;
	result = 3 * x + 2;
	return result;
}

int Calculate0fArea0fTriangle(int base, int height) {
	int result;
	result = (base * height) / 2;
	return result;
}

void calculateOfAreaOfSquare(int edge) {
	cout << "Area of Square: " << (edge * edge) << endl;
}

// Video 6.38

string nameLastnameCombine() {
	string name, lastName, nameLastname;

	cout << "Please, Enter the your name: ";
	cin >> name;

	cout << "Please, Enter the your last name: ";
	cin >> lastName;

	nameLastname = name + " " + lastName;

	return nameLastname;
}

// Video 6.39

void errorMessage() {
	cout << "Attention: An error occurred in the program" << endl;
}

void errorMessage(string messages) {
	cout << messages << endl;
}

void errorMessage(int errorCode) {
	cout << "Error Code: " << errorCode << endl;
}

// Video 7.44

void randomNumberCreater(int min, int max) {
	int randomNumber;
	srand(time(0));
	
	do {
		randomNumber = rand();
	} while (!(randomNumber >= min && randomNumber <= max));

	cout << "Random number: " << randomNumber << endl;
}

// Secend Way

int randomNumberCreater2(int min, int max) {
	int randomNumber = min + (rand() % (min - max + 1));
	return randomNumber;
}

int main()
{
	// Video 6.37
	
	int calculation;
	calculation = calculate(2);

	cout << "Result of calculation: " << calculation << endl;
	cout << "Result of calculation: " << calculate(2) << endl;

	cout << "Area of triangle: " << Calculate0fArea0fTriangle(5, 8) << endl;

	calculateOfAreaOfSquare(5);
	
	// Video 6.38
	
	string nameLastname = nameLastnameCombine();
	cout << "Your name and Lastname: " << nameLastname << endl;

	cout << "Your name and Lastname: " << nameLastnameCombine() << endl;
	

	// Video 6.39
	
	errorMessage();
	errorMessage("Error");
	errorMessage(404);
	

	// Video 7.43
	
	cout << "Time(0): " << time(0) << endl; // Returns the number of seconds since 00:00:00 UTC on January 1, 1970.

	srand(time(0)); // To ensure that the rand function does not always produce the same number

	int randomNumber = rand();

	cout << "Create random number with rand() function: " << randomNumber << endl;

	// Example 2.
	// create a number between 1 to 10
	int randomNumber2 = (rand() % 10) + 1;
	cout << "Created a number between 1 to 10: " << randomNumber2 << endl;
	

	// Video 7.44

	randomNumberCreater(1, 5);
	cout << "Random number: " << randomNumberCreater2(1, 5) << endl;

	return 0;
}