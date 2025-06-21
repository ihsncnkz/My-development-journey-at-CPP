#include <iostream>

using namespace std;

int changeNumbers(int number)
{
	int result = number * number;
	return result;
}

void changeArray(int arr[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (arr[i] % 2 == 0)
		{
			arr[i] = arr[i] * arr[i];

		}
	}
}

int numberOfCharacher(char arr[])
{
	return strlen(arr);
}

int main()
{
	// Video 39.194
	
	int x = 1;

	do
	{
		x++;
		cout << "*";
	} while (x++ < 5);
	cout << endl << "x: " << x << endl;
	

	// Video 39.195
	
	int x = 1;

	do
	{
		x++;
		cout << "*";
	} while (++x < 5);
	cout << endl << "x: " << x << endl;
	
	

	// Video 39.196
	
	int x = 3;
	int y = 7;
	int* p1;
	int* p2;
	p1 = &x;
	p2 = &y;
	y = y + 3;
	*p1 = *p1 * 3;
	*p1 = *p1 * *p2;
	cout << *p1;

	cout << endl;
	

	// Video 39.197
	
	int numbers[] = { 2, 7, 13, 12 };

	// First Way
	
	for (int i = 0; i < 5; i++)
	{
		if (numbers[i] % 2 == 0)
		{
			numbers[i] = changeNumbers(numbers[i]);

		}

		cout << numbers[i] << "  ";
	}
	

	// Second Way
	
	int size = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;

	changeArray(numbers, size);

	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << ", ";
	}
	

	// Video 39.198
	
	char str[] = "Great things never come from comfort zones.";
	int size = numberOfCharacher(str);
	cout << "Array size: " << size << endl;
	

	// Video 40.202
	
	int userValue;

	cout << "How many number will you enter: ";
	cin >> userValue;
	int* numbers = new int[userValue];

	for (int i = 0; i < userValue; i++)
	{

		cout << "Please, Enter the " << i + 1 << ". number: ";
		cin >> numbers[i];
	}

	for (int i = userValue - 1; i >= 0; i--)
	{
		cout << numbers[i] << " ";
	}

	delete[] numbers;
	
	return 0;
}