#include <iostream>
#include <fstream>
#include <string>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Bird.h"

using namespace std;

// int Dog::numberOfDog = 0;

void makeSoundThreeTimes2(Animal* a) {
	for (int i = 0; i < 3; i++) {
		a->makeSound();
	}
}

int main() {

	// Video 22.109
	
	fstream file; // Declares a file stream object called 'file'. 
	file.open("testing.txt", ios::out | ios::binary | ios::app);

	if (!file.is_open()) {
		cout << "the file cannot be opened";
	}
	else {
		file << endl;
		string str = "Hello C++ !";
		file << str;
		file.close();
	}
	

	// Video 22.110
	
	fstream file; // Declares a file stream object called 'file'. 
	file.open("testing.txt", ios::in ); // | ios::binary, If I work on audio, image files i should add this.

	if (!file.is_open()) {
		cout << "the file cannot be opened";
	}
	else {
		string str;
		//getline(file, str); // Read first line
		while (getline(file, str))
		{
			cout << str << endl;
		}
		// cout << str << endl;
		file.close();
	}
	

	// Video 23.112
	
	Animal animal1("BlackHead");
	animal1.eat();
	animal1.sleep();
	

	// Video 23.113
	
	Cat tabby("Tabby");
	tabby.eat();
	tabby.sleep();
	tabby.catchMouse();
	

	// Video 23.114
	
	Dog dog1("Hachiko");
	dog1.eat();
	dog1.sleep();
	dog1.bark();
	
	cout << endl;

	Bird bird1("Blu");
	bird1.eat();
	bird1.sleep();
	bird1.fly();

	cout << endl;
	

	// Video 23.115
	
	Dog dog1("Hachiko");
	dog1.eat();
	dog1.sleep();
	dog1.bark();

	cout << endl;

	Bird bird1("Blu");
	bird1.eat();
	bird1.sleep();
	bird1.fly();
	

	// Video 23.116
	
	Dog dog1("Hachiko");
	dog1.eat();
	dog1.sleep();
	dog1.bark();

	Dog dog2("Warwick");
	Dog dog3("Tom");
	Dog dog4("alpha");

	Dog* dp = new Dog("Sam");

	cout << "Number of dog: " << Dog::numberOfDog << endl;

	delete dp;
	cout << "Number of dog: " << Dog::numberOfDog << endl;
	

	// Video 13.117
	
	Dog dog1("Hachiko");
	dog1.eat();
	dog1.sleep();
	dog1.bark();

	Dog dog2("Warwick");
	Dog dog3("Tom");
	Dog dog4("alpha");

	Dog* dp = new Dog("Sam");

	cout << "Number of dog: " << Dog::getnumberOfDog() << endl;

	delete dp;
	cout << "Number of dog: " << Dog::getnumberOfDog() << endl;
	

	// Video 24.120
	
	Animal* pAnimal;
	Cat tabby("Tabby");
	pAnimal = &tabby;

	pAnimal->makeSound();
	//pAnimal->printToScreen();

	Dog dog1("Warwick");
	pAnimal = &dog1;

	pAnimal->makeSound();

	Bird bird1("Blu");
	pAnimal = &bird1;

	pAnimal->makeSound();
	

	// Video 24.121
	
	Animal* pAnimal;
	Cat tabby("Tabby");
	pAnimal = &tabby;

	pAnimal->makeSoundThreeTimes();
	//pAnimal->printToScreen();

	Dog dog1("Warwick");
	pAnimal = &dog1;

	pAnimal->makeSoundThreeTimes();

	Bird bird1("Blu");
	pAnimal = &bird1;

	pAnimal->makeSoundThreeTimes();
	
	
	Animal* pAnimal;
	Cat tabby("Tabby");
	pAnimal = &tabby;

	makeSoundThreeTimes2(pAnimal); //makeSoundThreeTimes2(&tabby);
	//pAnimal->printToScreen();

	Dog dog1("Warwick");
	pAnimal = &dog1;
	makeSoundThreeTimes2(pAnimal); //makeSoundThreeTimes2(&dog1);
	

	Bird bird1("Blu");
	pAnimal = &bird1;
	makeSoundThreeTimes2(pAnimal); //makeSoundThreeTimes2(&bird1);
	
	
	
	return 0;
}