#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
	Dog(string name);
	~Dog();
	void bark();
	
	static int getnumberOfDog() {
		return numberOfDog;
	}

	void makeSound();
	void makeSoundThreeTimes();
	void printToScreen();

private:
	static int numberOfDog;
};