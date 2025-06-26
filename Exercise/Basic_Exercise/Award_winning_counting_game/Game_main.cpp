#include <iostream>
#include <random>
#include <string>

#include "Player.h"

using namespace std;

int main()
{
	cout << " **** Welcome Number Guessing Game ****" << endl;
	cout << "Try to guess the number the computer is picking" << endl;
	cout << "You have 50 points.If you guess correctly, " << endl;
	cout << "you get + 10 points.If you guess incorrectly, you get - 10 points." << endl;
	cout << "The numbers will be between 0 and 50!" << endl;
	cout << "If you pass 100 points you win!" << endl;
	
	bool value = true;
	int userNumber;
	string userName;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);

	cout << "Enter your name: ";
	getline(cin, userName);

	Player player1(userName, 50);

	while (value)
	{
		int randomNumber = dist(gen);

		cout << "Enter your number: ";
		cin >> userNumber;
		cin.ignore();

		if (userNumber >= 51)
		{
			cout << "Please enter a number between 0 and 50." << endl;
		}
		else if (userNumber == randomNumber)
		{
			cout << "User: " << userNumber << endl;
			cout << "Computer: " << randomNumber << endl;
			player1.pointWin();

			cout << "Correct Guess Won 10 Point. Your point: " << player1.getPoint() << endl;
		}
		else
		{
			cout << "User: " << userNumber << endl;
			cout << "Computer: " << randomNumber << endl;
			player1.pointLoss();
			cout << "Wrong  Guess Loss 10 Point. Your point: " << player1.getPoint() << endl;
		}

		if (player1.getPoint() <= 0)
		{
			cout << "Loss This Game!" << endl;
			value = false;
		}
		else if (player1.getPoint() == 100)
		{
			cout << "Won Thin Game! Congratulations" << endl;
			value = false;
		}

	}

	cout << " **** Finish This Game **** " << endl;
	player1.printInfo();

	return 0;
}