#include "Bird.h"

Bird::Bird(string name) : Animal(name) {

}

void Bird::fly() {
	cout << Animal::getName() << " is flying!" << endl;
}

void Bird::makeSound() {
	cout << "Cik Cik Cik\n";
}

void Bird::printToScreen() {
	cout << "The print method of the bird class was called.\n\n";
}

void Bird::makeSoundThreeTimes() {
	for (int i = 0; i < 3; i++) {
		cout << "Cik Cik Cik\n";
	}
}