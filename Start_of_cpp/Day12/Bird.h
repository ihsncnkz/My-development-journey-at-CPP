#pragma once
#include "Animal.h"

class Bird : public Animal {

public:
	Bird(string name);
	void fly();

	void makeSound();
	void makeSoundThreeTimes();
	void printToScreen();
};