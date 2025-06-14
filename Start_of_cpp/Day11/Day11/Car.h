#pragma once
#include <iostream>
// Video 19.102

using namespace std;

class Car {
public:
	//string color;
	//string model;
	//int horsepower;
	
	// Car Constructor
	Car(string _color, string _model, int _horsepower, int _numberOfDoors);

	// Car Destructor
	~Car();


	void licenseInformation();
	
	void setCarColor(string _color);
	string getCarColor();

	void setCarModel(string _model);
	string getCarModel();

	void setCarHoursePower(int _horsepower);
	int getCarHoursePower();

	/*
	void setCarModelYear(int _modelyear);
	int getCarModelYear();
	*/

	int* pnumberOfDoors;

private:
	string color;
	string model;
	int horsepower;
	//int modelyear;
};
