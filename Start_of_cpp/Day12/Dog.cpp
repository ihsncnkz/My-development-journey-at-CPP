#include "Dog.h"

int Dog::numberOfDog = 0;

Dog::Dog(string name) : Animal(name) {
	numberOfDog++;
}

Dog::~Dog() {
	numberOfDog--;
}

void Dog::bark() {
	cout << Animal::name << " is barking!" << endl;
}

void Dog::makeSound() {
	cout << "Hav Hav Hav\n";
}

void Dog::printToScreen() {
	cout << "The print method of the dog class was called.\n\n";
}

void Dog::makeSoundThreeTimes() {
	for (int i = 0; i < 3; i++) {
		cout << "Hav Hav Hav\n";
	}
}