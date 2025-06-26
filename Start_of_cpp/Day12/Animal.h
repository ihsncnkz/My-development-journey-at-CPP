#pragma once
#include <iostream>

using namespace std;


class Animal {
public:
	Animal(string name);
	void eat();
	void sleep();

	void setName(string name);
	string getName();

	virtual void makeSound();
	virtual void makeSoundThreeTimes();

	void printToScreen();

protected:
	string name;
};