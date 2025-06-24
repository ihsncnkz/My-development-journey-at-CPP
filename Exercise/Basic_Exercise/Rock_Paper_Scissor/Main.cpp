#include <iostream>
#include <random>
using namespace std;


int main()
{
	string rps[] = { "rock", "paper", "scissor" };
	string userChoices;
	bool value = true;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 2);
	
	do
	{
		int randomNum = dist(gen);
		string computerChoices = rps[randomNum];

		cout << "You can choice: rock, paper, scissor" << endl;
		cout << "Please, Enter your choices: ";
		cin >> userChoices;

		if (userChoices == computerChoices)
		{
			cout << "Draw!" << endl;
			continue;
		}
		else if ((userChoices == "rock" && computerChoices == "scissor") && (computerChoices != "paper"))
		{
			cout << "Win User!" << endl;
			value = false;
		}
		else if ((userChoices == "paper" && computerChoices == "rock") && (computerChoices != "scissor"))
		{
			cout << "Win User" << endl;
			value = false;
		}
		else if ((userChoices == "scissor" && computerChoices == "paper") && (computerChoices != "rock"))
		{
			cout << "Win User" << endl;
			value = false;
		}
		else
		{
			cout << "Win Computer" << endl;
			value = false;
		}
		cout << "User Choice: " << userChoices << " Computer Choice: " << computerChoices << endl;
		
	} while (value);
	

	return 0;
}