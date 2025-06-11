#include <iostream>

using namespace std;

int aircraftDirectionCalculation(int x_) {
	// This function is basic function for use with pointer.
	x_ = (x_ * (360 / 3)) / 4;

	return x_;
}
// with pointer
void aircraftDirectionCalculation(int *p) {
	*p = (*p * (360 / 3)) / 4;
}

int* fonction(bool x) { 
	int* p = new int;
	if (x == true) {
		*p = 37;
	}
	else
		p = NULL;
	return p;
}


int main() {

	// Video 15.75
	
	int x = 7;
	int y = 8;

	cout << "y value: " << y << endl;

	int* ptr; // In C++, a pointer is a variable that stores the memory address of another variable. int* ptr = int *ptr
	ptr = &x; // gets the address of variable x.

	cout << "Adress of x: " << ptr << endl;
	cout << "Value of x: " << *ptr << endl;

	*ptr = 9;
	cout << "Value of x: " << x << endl;
	cout << "Value of x show with *ptr: " << *ptr << endl;

	ptr = &y;
	*ptr = 20;
	cout << "Value of y: " << y << endl;
	cout << "Value of y show with *ptr: " << *ptr << endl;
	

	// Video 15.76
	
	int x = 30;
	
	int *ptr;

	ptr = &x;

	cout << "Adres of x show with ptr: " << ptr << endl;
	cout << "Adres of x show with &x : " << &x << endl;
	

	//x = aircraftDirectionCalculation(x);
	int* p;
	p = &x;
	aircraftDirectionCalculation(p);
	cout << "New direction information: " << x << endl;
	


	// Video 15.77
	
	int arr[] = {8, 12, 20};
	int *p;
	p = arr;

	cout << "Address of arr show with p: " << p << endl;
	cout << "Address of arr show with arr: " << arr << endl;
	cout << endl;

	cout << "First value of arr show with *p: " << *p << endl; // *p = arr[0]
	cout << "Second value of arr show with *(p+1): " << *(p + 1) << endl; // *(p+1) = arr[1]
	cout << "Third value of arr show with *(p+2): " << *(p + 2) << endl; // *(p+2) = arr[2]
	cout << endl;

	*(p + 2) = *(p+2) * 2; // Change third value
	cout << "Third value of arr show with *(p+2): " << *(p + 2) << endl; // *(p+2) = arr[2]
	cout << "Third value of arr show with arr[2]: " << arr[2] << endl; // *(p+2) = arr[2]
	cout << endl;

	cout << "First value of adress of arr show with p: " << p << endl;
	cout << "Second value of address of arr show with p: " << (p + 1) << endl;
	cout << "Third value of address of arr show with p: " << (p + 2) << endl;
	cout << endl;
	

	// Video 16.80
	
	int* p = new int; // The 'new' code allocates memory in the RAM for the value of p.
	*p = 5;

	cout << *p << endl;

	delete p; // We need to delete the pointer p because it will continue to occupy space in RAM.

	p = NULL; // We must to assign the null value for p value becaise we dont use it.
	if (p != NULL)
		cout << *p << endl; 

	p = new int; // After setting p to null, you can't assign a value through it because it points to nothing. To assign a new value, you must allocate memory again using p = new int;.
	*p = 10;

	cout << *p << endl;
	delete p;
	

	// Video 16.81
	
	// int *p = new int(5) == *p = 5.
	int* p;
	p = NULL;

	if (p != NULL) {
		*p = 5;
	}
	else
	{
		p = new int(5);
	}

	cout << *p << endl;
	delete p;
	

	// Video 16.82
	
	int* ptr;
	ptr = fonction(false);
	
	if (ptr != NULL) {
		cout << *ptr << endl;
		delete ptr;
	}
	else
		cout << "Value Null" << endl;
	

	// Video 16.83
	
	int n, sumOfValue = 0;
	cout << "Please write how many integers it will contain: ";
	cin >> n;

	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		sumOfValue += p[i];
	}

	cout << "Sum of values: " << sumOfValue << endl;
	delete[] p;
	
	return 0;
}