#include "Cat.h"

Cat::Cat(string name) : Animal(name) {

}

void Cat::catchMouse() {
	cout << Animal::name << " is catching a mouse!" << endl;
}

void Cat::makeSound() {
	cout << "miyav miyav miyav\n";
}

void Cat::printToScreen() {
	cout << "The print method of the cat class was called.\n\n";
}

void Cat::makeSoundThreeTimes() {
	for (int i = 0; i < 3; i++) {
		cout << "miyav miyav miyav\n";
	}
}