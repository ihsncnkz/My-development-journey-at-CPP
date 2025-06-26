#include <iostream>
using namespace std;

int main()
{
	// Video 4.21
	
	int temperature = 22;
	bool ishot = false;

	if (temperature >= 35)
	{
		cout << "Enviroment is hot!";
	}
	else
	{
		cout << "Enviroment is not hot!";
	}
	
	// Video 4.22
	
	int temperature;

	cout << "Please, Enter the information of temperature: ";
	cin >> temperature;

	if (temperature >= 35)
	{
		cout << "Enviroment is hot";
	}
	else
	{
		cout << "Enviroment is not hot";
	}


	int password = 1234;
	int userInput;
	cout << "Please, Enter the information of password: ";
	cin >> userInput;

	if (userInput == password)
	{
		cout << "Welcome to system!\n";
	}
	else
	{
		cout << "Password is rong. Please enter the correct password." << endl;
	}
	

	// Video 4.23
	
	int number1, number2, result;
	int operation;

	cout << "Operation:\n 1 - additon\n 2 - subtraction\n 3 - multiplication\n 4 - divison\n";
	cout << "Please, Choose the operation: ";
	cin >> operation;

	cout << "Please, Enter the number1: ";
	cin >> number1;

	cout << "Please, Enter the number2: ";
	cin >> number2;

	if (operation == 1)
	{
		result = number1 + number2;
		//cout << "Result: " << result << endl;
	}
	else if (operation == 2)
	{
		result = number1 - number2;
		//cout << "Result: " << result << endl;
	}
	else if (operation == 3)
	{
		result = number1 * number2;
		//cout << "Result: " << result << endl;
	}
	else if (operation == 4)
	{
		result = number1 / number2;
		//cout << "Result: " << result << endl;
	}
	else
	{
		cout << "Rong choose, Please Enter correct choose!";
		return 0;
	}

	cout << "Result: " << result << endl;
	

	// Video 4.25

	// !=
	
	int password = 1234;
	int userEnter = 123;

	if (password != userEnter)
	{
		cout << "Password is rong!";
	}
	else
	{
		cout << "Password is correct!";
	}
	
	
	int number1, number2;
	cout << "Enter the number1: ";
	cin >> number1;

	cout << "Enter the number2: ";
	cin >> number2;

	if (number1 > 0 && number2 > 0)
	{
		cout << "Your two numbers are positive";
	}
	else if (number1 < 0 && number2 < 0)
	{
		cout << "Your two numbers are negative";
	}
	else if (number1 < 0 || number2 < 0)
	{
		cout << "At least one of your numbers is negative.";
	}
	

	// ! not
	
	int x = 3;

	if (!(x == 5))
	{
		cout << "x is not 5";
	}
	else
	{
		cout << "x is 5";
	}
	

	// Video 4.26
	
	int number1, number2, number3, smallestNumber;
	cout << "Please, Enter the number1: ";
	cin >> number1;

	cout << "Please, Enter the number2: ";
	cin >> number2;

	cout << "Please, Enter the number3: ";
	cin >> number3;

	if (number1 <= number2 && number1 <= number3)
	{
		smallestNumber = number1;
	}
	else if (number2 <= number1 && number2 <= number3)
	{
		smallestNumber = number2;
	}
	else
	{
		smallestNumber = number3;
	}

	cout << "Smallest number is " << smallestNumber << endl;
	

	// Video 4. 27
	
	int x = 5;
	int y = 10;

	if (x = 20) //  x = 20 means true
	{
		if (y == 10)
		{
			cout << "** ";
		}
	}
	else cout << "*****";
	

	// Video 4.28
	
	int numberOfWeekDay;
	cout << "Enter the day of the week as a number: ";
	cin >> numberOfWeekDay;

	switch (numberOfWeekDay)
	{
		case 1:
			cout << "Monday";
			break;
		case 2:
			cout << "Tuesday";
			break;
		case 3:
			cout << "Wednesday";
			break;
		case 4:
			cout << "Thursday";
			break;
		case 5:
			cout << "Friday";
			break;
		case 6:
			cout << "Saturday";
			break;
		case 7:
			cout << "Sunday";
			break;
		default:
			cout << "You have entered an incorrect number. Please enter a number between 1 and 7.";
			break;
	}

	cout << endl;
	

	// Video 4.29
	
	int x = 5, y = 9, z = 7.4, w;
	w = (z > x) - (y <= 11);
	cout << w << endl;

	w = z > x - y <= 11;
	cout << w << endl;
	
	
	// Video 4.30
	setlocale(LC_ALL, "Turkish");
	cout << "Çalışkan öğrenci, güneşli öğleden sonra şiir okuyarak yürüyüş yaptı.\n";

	return 0;
}