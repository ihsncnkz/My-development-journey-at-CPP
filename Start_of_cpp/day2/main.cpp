#include <iostream> // There is the cmath library in this library for windows
#include <iomanip>
#include <cmath>
using namespace std;

int main() 
{

	// Video 2.10
	
	double value = 123.456789;
	cout << value << endl;

	/*setprecision(N) is a function (commonly from C++'s <iomanip> library) that sets the number of digits displayed 
	after the decimal point (or total significant digits) when printing floating-point numbers.*/
	cout << setprecision(2) << value << endl;

	// fixed tells the output stream to display floating-point numbers in fixed-point notation
	cout << fixed << setprecision(2) << value << endl;
	
	// Video 2.12
	
	int x = 7;
	x++; // x = x + 1  Increasing operator (postfix)

	int y = 10;
	y--; // x = x - 1  decrease operator (postfix)

	int z = 7;
	++z; // Increasing operator (prefix)

	int a = 10; 
	--a; // decrease operator (prefix)

	cout << a << endl;

	int b = 8;
	int c = b++;
	cout << b << endl;
	cout << c << endl;

	int d = 8;
	int e = ++d;
	cout << d << endl;
	cout << e << endl;
	

	// Video 3.18
	
	string name;
	int width, size, area;

	cout << "Please, write your name: ";
	cin >> name;
	cout << "Hello " << name << " Welcome to c++ programing course.\n";

	cout << "Geomretric Operation" << endl;

	cout << "Please, enter the width of the rectangle: ";
	cin >> width;

	cout << "Please, enter the size of the rectangle: ";
	cin >> size;

	area = width * size;

	cout << "Dear " << name << " Result of your operation: " << area << endl;
	

	// Video 3.19
	
	int result, x, y;
	cout << "write number of the x value: ";
	cin >> x;

	cout << "write number of the y value: ";
	cin >> y;

	result = pow(x, y); // 2 raised to the power of 3

	cout << "Result: " << result << endl;
	

	int resultfloor;

	resultfloor = floor(2.7); // uses the floor function from the <cmath> library, which returns the largest integer less than or equal to the input.
	cout << "Result of floor: " << resultfloor << endl;

	int resultceil;

	resultceil = ceil(2.1); // uses the ceil function from the <cmath> library, which returns the smallest integer greater than or equal to the input.
	cout << "Result of ceil: " << resultceil << endl;

	int resultround;

	resultround = round(2.51); // uses the round function from the <cmath> library, which returns the nearest integer to the given number.
	cout << "Result of round: " << resultround << endl;
	

	// Video 3.20
	
	int quiz1, quiz2, quiz3;
	double averageOfquizResult;
	
	cout << "Please, Write result of 1. quiz: ";
	cin >> quiz1;

	cout << "Please, Write result of 2. quiz: ";
	cin >> quiz2;

	cout << "Please, Write result of 3. quiz: ";
	cin >> quiz3;

	averageOfquizResult = (double) (quiz1 + quiz2 + quiz3) / 3.0;

	cout << "Average of quiz results 1: " << fixed << setprecision(2) << averageOfquizResult <<endl;

	cout << "Average of quiz results 2: " << round(averageOfquizResult) << endl;
	
	// Secend way

	cout << "Please, Write result of quizs: ";
	cin >> quiz1 >> quiz2 >> quiz3;

	averageOfquizResult = (double) (quiz1 + quiz2 + quiz3) / 3.0;

	int averageOfquizResultint = (int)round(averageOfquizResult);
	cout << "Average of quiz results: " << averageOfquizResultint << endl;


	return 0;
}