#include <iostream>
#include <string>

using namespace std;

void changeArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = arr[i] + 1;
	}
}

void changeNumber(int number) {
	number = number + 1;
}

int aboveAverageGrades(int grades[], int size) {
	int average, gradesSum = 0, counter = 0;

	for (int i = 0; i < size; i++) {
		gradesSum = gradesSum + grades[i];
	}

	average = gradesSum / size;

	for (int i = 0; i < size; i++) {
		if (grades[i] > average) {
			counter++;
		}
	}

	return counter;
}

int main() {

	// Video 9.54
	
	int arr[7] = { 3, 9, 12, 5, 10, 1, 3 };

	changeArray(arr, 7);

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;

	int number = 10;
	changeNumber(number);
	cout << number << endl;
	

	// Video 9.55
	
	const int size = 4;
	int numbers[size];

	cout << "Enter, the numbers: \n";
	for (int i = 0; i < size; i++) {
		//cout << "Please, Enter the number: ";
		cin >> numbers[i]; // You can enter numbers on a single line, leaving spaces between them. Enter, the numbers: 1 2 3 4
		
	}

	for (int i = size-1; i >= 0; i--) {
		cout << numbers[i] << " ";
	}
	cout << endl;
	

	// Video 9.56
	
	const int size = 10;
	int gradesArr[size] = { 85, 78, 90, 66, 88, 72, 95, 80, 84, 77 };
	
	cout << "Above average grades: " << aboveAverageGrades(gradesArr, size) << endl;
	

	// Video 10.58
	
	char message[] = "Hello"; // This is a C type string.
	cout << message << endl;

	int lenght = 0;
	while (message[lenght] != '\0') {
		++lenght;
	}
	cout << lenght << endl;

	string newMessage = string(message); // Converting to modern C++ string type
	newMessage.append(" C++");
	cout << newMessage << endl;
	

	// Video 10.59
	
	string name = "Ahmet";
	cout << "Hello " << name << endl;

	string fruit = "Apple";

	cout << "Lenght: " << fruit.length() << endl;
	cout << "First letter: " << fruit.at(0) << endl;
	
	fruit.append(" juice");
	cout << "With append: " << fruit << endl;

	string newString = fruit + " is nice.";
	cout << newString << endl;

	cout << "Substr: " << newString.substr(0, 4) << endl; // substr(start, How many letters will you take?) 0 t0 0+4
	cout << "Substr2: " << newString.substr(0, 7) << endl; // substr(start, How many letters will you take?) 0 to 0+7

	string text = newString.substr(0, 4);
	cout << text << endl;

	size_t pos = newString.find("dice"); // size_t is an unsigned integer type used in C++ to represent sizes, lengths, and indexes — especially in arrays, strings, and memory-related operations.
	if (pos != string::npos)
		cout << "Found the searcing text. Posicion: " << pos << endl;
	else
		cout << "Not found!\n";

	newString.erase(5, 5); // Delete 5 from the 5th character.
	cout << "After the erase: " << newString << endl;

	newString.insert(4, " fresh");
	cout << "After the insert: " << newString << endl;

	newString.replace(0, 5, "Orange ");
	cout << "After the replace: " << newString << endl;
	
	return 0;
}