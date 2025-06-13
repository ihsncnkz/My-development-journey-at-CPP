#include "Car.h"

// Car Constructor
Car::Car(string _color, string _model, int _horsepower, int _numberOfDoors) {
	cout << "The Constructor called!" << endl;
	color = _color;
	model = _model;
	horsepower = _horsepower;
	numberOfDoors = new int(_numberOfDoors); // *numberOfDoors = _numberOfDoors;
}

// Car Destructor
Car::~Car() {
	cout << "The Destructor of "<< Car::model << " called!" << endl;
}

void Car::licenseInformation() {
	cout << "Model: " << Car::model << endl;
	cout << "Color: " << Car::color << endl;
	cout << "Horse Power: " << Car::horsepower << endl;
	cout << "Number of doors: " << *(Car::numberOfDoors) << endl;
}

void Car::setCarColor(string _color) {
	color = _color;
}

string Car::getCarColor() {
	return color;
}

void Car::setCarModel(string _model) {
	model = _model;
}
string Car::getCarModel() {
	return model;
}

void Car::setCarHoursePower(int _horsepower) {
	horsepower = _horsepower;
}
int Car::getCarHoursePower() {
	return horsepower;
}

/*
void Car::setCarModelYear(int _modelyear) {
	modelyear = _modelyear;
}

int Car::getCarModelYear() {
	return modelyear;
}
*/