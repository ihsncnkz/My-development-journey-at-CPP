#include <iostream>

using namespace std;

int main()
{
	// Video 5.29
	
	int index = 0;

	while (index <= 3)
	{
		cout << "Index is less than 3.\n";
		index++;
	}

	cout << "index: " << index << endl;

	cout << "End of Program...";
	

	// Video 5.30
	
	int startNumber, endNumber;

	cout << "Please, Enter the start of number: ";
	cin >> startNumber;

	cout << "Please, Enter the end of number: ";
	cin >> endNumber;

	while (startNumber <= endNumber)
	{
		if (startNumber % 5 == 0)
		{
			cout << "The number " << startNumber << " is divisible by 5." << endl;	
		}
		startNumber++;
	}

	cout << "End of Program!" << endl;
	

	// Video 5.31
	
	int password = 1234, userInput;

	do {
		cout << "Please, Enter the password: ";
		cin >> userInput;
	} while (userInput != password);

	cout << "Welcome to SkyNet!\n";

	

	// Video 5.32
	
	for (int i = 1; i <= 25; i++) {

		if (i % 2 == 0) {
			cout << i << " ";
		}
	}

	cout << endl;
	

	// Video 5.33
	
	int userNumber, result = 1;

	cout << "Please, Enter the number: ";
	cin >> userNumber;

	// First Way

	for (int i = 1; i <= userNumber; i++) {

		result = i * result;
	}

	cout << "Factorial calculation of number " << userNumber << ": " << result << endl;

	// Secend Way
	for (int i = userNumber; i > 0; i--) {
		result = i * result;
	}

	cout << "Factorial calculation of number " << userNumber << ": " << result << endl;
	

	// Video 5.34
	
	for (int i = 0; i <= 5; i++) {

		if (i == 3)
			break;

		cout << i << "  ";

	}

	cout << endl;

	for (int i = 0; i <= 5; i++) {

		if (i == 3)
			continue;

		cout << i << "  ";

	}

	cout << endl;
	
	
	// Video 5.35
	
	int x = 5;

	for (int i = 0; i <= 10; i++) {
		cout << i << " ";
	}
	

	// Video 5.36
	
	int userNumber, number1;
	cout << "Please, Enter the number: ";
	cin >> userNumber;
	cout << endl;

	for (int i = 1; i <= userNumber; i++) {
		for (int j = 1; j <= i; j++) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}