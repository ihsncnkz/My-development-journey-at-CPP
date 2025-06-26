#pragma once

#include <iostream>

using namespace std;

class Player
{
private:
	string pName;
	int point;

public:

	Player(string _pName, int _point);

	void pointWin();
	void pointLoss();

	int getPoint();
	string getPName();

	void printInfo();

};