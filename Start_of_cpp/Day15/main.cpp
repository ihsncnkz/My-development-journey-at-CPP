#include <iostream>
#include <random>
#include <list>
#include <vector>
#include <string>

using namespace std;

int add(int a, int b) {
	return a + b;
}

double add(double a, double b) {
	return a + b;
}

template <typename T> 
T add_tamplate(T a, T b) {
	return a + b;
}

template <typename T>
T subtraction_tamplate(T a, T b) {
	return a - b;
}

template <typename T>
class Square {
private:
	T side;
	
public:
	Square(T length) {
		side = length;
	}

	T Area() {
		return side * side;
	}

	void showSide() {
		cout << "Side lenght: " << side << endl;
	}
};

template <typename R>
class Rectangele {
private:
	R longSide;
	R shortSide;

public:
	Rectangele(R _longSide, R _shortSide) {
		longSide = _longSide;
		shortSide = _shortSide;
	}

	R Area() {
		return longSide * shortSide;
	}

	void showSides() {
		cout << "Long Side: " << longSide << " Short Side: " << shortSide << endl;
	}
};

void printList(list<int> l) {
	list<int>::iterator itr;
	for (itr = l.begin(); itr != l.end(); itr++) {
		cout << *itr << " ";
	}
}

void deleteList(list<int> *pl) {
	list<int>::iterator it;
	it = pl->begin();
	it++;
	it++;
	it++;
	pl->erase(it);
}

class Car {
private:
	string brand;
	string model;
	int year;

public:
	Car(string _brand, string _model, int _year) : brand(_brand), model(_model), year(_year){}

	void printInformation() const {
		cout << "Brand: " << brand << " Model: " << model << " Year: " << year << endl;
	}
};

int main() {

	// Video 32.151
	
	cout << add(3.4, 5.1) << endl;

	cout << add_tamplate(2, 9) << endl;

	cout << add_tamplate(8.9, 1.5) << endl;

	cout << add_tamplate(string("Hello "), string("World.")) << endl;
	

	// Video 32.152
	
	Square<int> s1(5);
	Square<double> s2(5.4);

	s1.showSide();
	cout << "s1 area: " << s1.Area() << endl;

	s2.showSide();
	cout << "s1 area: " << s2.Area() << endl;
	

	// Video 32.154
	
	Rectangele<int> r1(10, 4);
	Rectangele<double> r2(9.3, 3.6);

	r1.showSides();
	cout << "r1 area: " << r1.Area() << endl;

	r2.showSides();
	cout << "r2 area: " << r2.Area() << endl;

	cout << "Subtraction process: " << subtraction_tamplate(5, 7) << endl;
	cout << "Subtraction process: " << subtraction_tamplate(4.8, 2.3) << endl;
	

	// Video 32.155
	
	random_device rd; // True randomness source object (gets from hardware)
	mt19937 mt(rd()); // rastgele sayým üretim motoru (Mersenne Twister algorithm)

	uniform_int_distribution<int> distribution(1, 10);
	int randomNumber = distribution(mt);
	cout << "Integer produced: " << randomNumber << endl;

	uniform_real_distribution<double> distribution2(0.0, 1.0);
	double randomNumber2 = distribution2(mt);
	cout << "Integer produced 2: " << randomNumber2 << endl;
	

	// Video 33.156 , Video 33.157 , Video 33.158

	list<int> lst;
	lst.push_back(5);
	lst.push_back(8);
	lst.push_front(3);
	printList(lst);
	cout << endl;

	
	lst.pop_back();
	printList(lst);
	cout << endl;

	lst.pop_front();
	printList(lst);
	cout << endl;
	

	list<int>::iterator it;
	it = lst.begin();
	it++;
	it++;
	lst.insert(it, 9);
	printList(lst);
	cout << endl;

	it = lst.begin();
	it++;
	lst.insert(it, 2, 7);
	printList(lst);
	cout << endl;

	
	it = lst.begin();
	it++;
	it++;
	it++;
	lst.erase(it);
	

	deleteList(&lst);
	printList(lst);
	cout << endl;

	// Video 35.160 , 35.161,  35.162

	vector<int> vNumbers;
	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);

	cout << "Vector Size: " << vNumbers.size() << endl;

	for (int i = 0; i < vNumbers.size(); i++) {
		cout << "Element " << i << ": " << vNumbers[i] << endl; // cout << "Element " << i << ": " << vNumbers.at(i) << endl;
	}
	cout << endl;

	
	for (size_t i = 0; i < vNumbers.size(); i++) {
		cout << "Element " << i << ": " << vNumbers[i] << endl; // cout << "Element " << i << ": " << vNumbers.at(i) << endl;
	}

	cout << endl;

	
	cout << "Element 1: " << vNumbers[1] << endl;
	vNumbers[1] = 42;
	cout << "Element 1: " << vNumbers[1] << endl;
	cout << endl;

	for (size_t i = 0; i < vNumbers.size(); i++) {
		cout << "Element " << i << ": " << vNumbers[i] << endl; // cout << "Element " << i << ": " << vNumbers.at(i) << endl;
	}
	cout << endl;
	

	vector<string> vCars = { "Opel", "Audi", "BMW" };
	vCars.push_back("Seat");

	for (const string& car : vCars) {
		cout << car << " ";
	}
	cout << endl;
	

	vNumbers.insert(vNumbers.begin() + 1, 15);
	for (int& num : vNumbers) {
		cout << num << " ";
	}
	
	vNumbers.pop_back();
	vNumbers.erase(vNumbers.begin() + 1);
	vNumbers.clear();
	cout << "Vector Size: " << vNumbers.size() << endl;

	vector<int> myVector(5, 42);

	for (const int& num : myVector) {
		cout << num << " ";
	}
	cout << endl;

	// Video 34.163

	vector<Car> vGarage;

	vGarage.push_back(Car("Toyato", "Corolla", 2020));
	vGarage.push_back(Car("BMW", "X5", 2018));
	vGarage.push_back(Car("Mercedes", "C200", 2023));

	for (const Car& c : vGarage)
	{
		c.printInformation();
	}
	cout << endl;

	vGarage.erase(vGarage.begin() + 1);
	for (const Car& c : vGarage)
	{
		c.printInformation();
	}
	cout << endl;

	vGarage.push_back(Car("Ford", "Focus", 2023));
	for (const Car& c : vGarage)
	{
		c.printInformation();
	}
	cout << endl;

	cout << "First Element of vGarage: ";
	vGarage[0].printInformation();

	cout << "Last Element of vGarage: ";
	vGarage[vGarage.size() - 1].printInformation();

	return 0;
}