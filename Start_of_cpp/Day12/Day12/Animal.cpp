#include "Animal.h"

Animal::Animal(string name) {
	Animal::name = name;
}

void Animal::eat() {
	cout << Animal::name << " eating!" << endl;
}

void Animal::sleep() {
	cout << Animal::name << " sleeping!" << endl;
}

void Animal::setName(string name) {
	Animal::name = name;
}
string Animal::getName() {
	return Animal::name;
}

void Animal::makeSound() {
	cout << "The animal sound function was called.\n\n";
}

void Animal::printToScreen() {
	cout << "The print method of the animal class was called.\n\n";
}

void Animal::makeSoundThreeTimes() {
	cout << "The animal sound three times function was called.\n\n";
}