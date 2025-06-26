#include <iostream>

using namespace std;

class Car {
private:
	string brand;

public:
	int year;

	Car(string _brand, int _year) {
		brand = _brand;
		year = _year;
	}
	friend void showInformation(Car oto);
};

void showInformation(Car oto) {
	cout << oto.year << " " << oto.brand;
}


int main() {

	Car car1("Opel", 2012);

	showInformation(car1);

	return 0;
}
