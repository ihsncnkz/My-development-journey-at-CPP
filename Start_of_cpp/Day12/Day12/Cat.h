#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
	Cat(string name);
	void catchMouse();

	void makeSound();
	void makeSoundThreeTimes();
	void printToScreen();

};