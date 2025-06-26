#include <iostream>
#include <chrono>

using namespace std;


void fonction1() {
	static int counter = 0;
	counter++;
	cout << "Fonction1 counter: " << counter << endl;
}
void fonction2() {
	static int counter = 0;
	counter++;
	cout << "Fonction2 counter: " << counter << endl;
}
void changer(int& value) { // int& call by reference
	value = value * 2;
}


int main() {
	
	// Video 11.63
	
	int number;
	cout << "Please, Enter the number: ";
	cin >> number;

	for (int i = 1; i <= number; i++) {
		int counter = 0;
		for (int j = 1; j <= i; j++) {		
			if (i % j == 0) {
				++counter;
			}
		}
		if (counter <= 2 && i != 1)
			cout << i << " ";
	}
	

	// Video 11.64
	
	int number;
	cout << "Please, Enter the number: ";
	cin >> number;

	for (int i = 1; i <= number; i++) {
		int counter = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				++counter;
			}

			if (counter > 2)
				break;
		}
		if (counter == 2 && i != 1)
			cout << i << " ";
	}
	

	// Video 11.65
	
	int number;
	cout << "Please, Enter the number: ";
	cin >> number;
	chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for (int i = 1; i <= number; i++) {
		int counter = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				++counter;
			}
			//if (counter > 2)
			//	break;
		}
		if (counter <= 2 && i != 1)
			cout << i << " ";
	}
	chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	cout << endl;

	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	

	// Video 11.66
	
	const int number = 9999;
	int counter_unique = 0;
	
	for (int i = 1000; i <= number; i++) {
		int numbers[4] = { 0, 0, 0, 0 };
		int counter = 0;
		// 1234
		numbers[0] = (int) (i % 10); // 4
		numbers[1] = (int) (((i % 100) - numbers[0]) / 10); // 3
		numbers[2] = (int) (((i % 1000) - (i % 100)) / 100); // 2
		numbers[3] = (int) ((i - (i % 1000)) / 1000); // 1

		
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (j == k)
					continue;
				else {
					if (numbers[j] == numbers[k])
						counter++;
				}
			}
			if (counter > 1)
				break;
		}
		if (counter == 0)
			counter_unique++;
	}

	cout << counter_unique << endl;
	
	// Second Way
	
	int counter = 0;
	int first, second, third, fourth;

	for (int i = 1000; i <= 9999; i++) {
		first = i % 10;
		second = (i / 10) % 10;
		third = (i / 100) % 10;
		fourth = i / 1000;

		if (first != second && first != third && first != fourth && second != third && second != fourth && third != fourth)
			counter = counter + 1;
	}

	cout << counter << endl;
	

	// Video 11.67
	
	for (int i = 20; i <= 40; i++) {
		cout << "Divisors of " << i << ": ";
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				cout << j << ", ";
		}
		cout << endl;
	}
	

	// Video 12.68
	
	const double pi = 3.14;
	
	// Video 12.69
	
	fonction1();
	fonction1();
	fonction1();

	fonction2();
	

	// Video 13.70
	
	int diversifiedNumber, dividingNumber;
	cout << "Please, Enter the number of diversified: ";
	cin >> diversifiedNumber;

	cout << "Please, Enter the number of dividing: ";
	cin >> dividingNumber;
	
	int result;
	try {
		if (dividingNumber == 0)
			throw 99;
		result = diversifiedNumber / dividingNumber;
		cout << "Result: " << result << endl;
	}
	catch (int hataKodu) {
		cout << "The number that divides should not be 0." << endl;
	}
	

	// Video 14.73

	int number = 5;
	changer(number);
	cout << "Number: " << number << endl;

	return 0;
}