#include <iostream>
#include "Car.h"

using namespace std;

/*
class Car {
public:
	string color;
};
*/


int main() {
	
	// Video 19.101
	
	Car car1;
	Car car2, car3;

	car1.color = "Black";
	car2.color = "Blue";
	car3.color = "Yellow";

	cout << "Car1 color: " << car1.color << endl;
	cout << "Car2 color: " << car2.color << endl;
	cout << "Car3 color: " << car3.color << endl;
	

	// Video 19.102

	
	Car car1, car2;

	car1.color = "Black";
	car1.horsepower = 90;
	car1.model = "Audi";

	car2.color = "Blue";
	car2.horsepower = 100;
	car2.model = "Opel";

	//cout << "Car1 color: " << car1.color << endl;
	//cout << "Car2 color: " << car2.color << endl;

	car1.licenseInformation();
	cout << endl;
	car2.licenseInformation();
	

	// Video 20.103
	
	Car car1("Black", "Audi", 90);
	Car car2("Blue", "Opel", 100);

	car1.licenseInformation();
	cout << endl;
	car2.licenseInformation();
	

	// Video 20.104
	
	Car car1("Black", "Audi", 90);
	car1.setCarColor("White");

	car1.licenseInformation();
	cout << endl;

	//cout << car1.getCarColor() << endl;

	Car car2("Blue", "Opel", 100);
	car2.setCarColor("Yellow");
	car2.setCarModel("Mercedes");
	car2.setCarHoursePower(1000);

	cout << "Car2 Model: " << car2.getCarModel() << endl;
	cout << "Car2 color: " << car2.getCarColor() << endl;
	cout << "Car2 Horse Power: " << car2.getCarHoursePower() << endl;


	car2.licenseInformation();
	cout << endl;
	

	// Video 20.105
	
	Car car2("Blue", "Opel", 100);
	car2.setCarColor("Yellow");
	car2.setCarModel("Mercedes");
	car2.setCarHoursePower(1000);
	car2.setCarModelYear(2022);


	cout << "Car2 Model: " << car2.getCarModel() << endl;
	cout << "Car2 color: " << car2.getCarColor() << endl;
	cout << "Car2 Horse Power: " << car2.getCarHoursePower() << endl;
	cout << "Car2 Model Year: " << car2.getCarModelYear() << endl;
	

	// Video 21.106
	
	Car car1("Black", "Audi", 90);
	Car car2("Blue", "Opel", 100);

	Car* p;
	//p = &car1;
	//p->licenseInformation();

	//p = &car2;
	//p->licenseInformation();

	p = new Car("White", "BMW", 600); // Car* p = new Car("White", "BMW", 600);
	p->setCarColor("Green");

	p->licenseInformation();
	delete p;
	

	// Video 21.107
	
	Car car1("Black", "Audi", 90);
	Car car2("Blue", "Opel", 100);

	Car* p;

	p = new Car("White", "BMW", 600); // Car* p = new Car("White", "BMW", 600);
	p->setCarColor("Green");

	p->licenseInformation();
	delete p;
	

	// Video 21.108

	Car car1("Black", "Audi", 90, 4);
	Car car2("Blue", "Opel", 100, 4);
	//cout << "Number of car1 doors: " << *(car1.numberOfDoors) << endl;
	//cout << "Number of car2 doors: " << *(car2.numberOfDoors) << endl;


	Car* p;
	p = new Car("White", "BMW", 600, 2);
	//cout << "Number of BMW doors: " << *(p->numberOfDoors) << endl;

	car1.licenseInformation();
	cout << endl;
	car2.licenseInformation();
	cout << endl;
	p->licenseInformation();
	cout << endl;

	delete p;

	// Video 23.111
	Car car1("Black", "Audi", 90, 4);
	Car car2("Blue", "Opel", 100, 4);
	//cout << "Number of car1 doors: " << *(car1.numberOfDoors) << endl;
	//cout << "Number of car2 doors: " << *(car2.numberOfDoors) << endl;


	Car* p;
	p = new Car("White", "BMW", 600, 2);
	//cout << "Number of BMW doors: " << *(p->numberOfDoors) << endl;

	car1.licenseInformation();
	cout << endl;
	car2.licenseInformation();
	cout << endl;
	p->licenseInformation();
	cout << endl;


	return 0;
}