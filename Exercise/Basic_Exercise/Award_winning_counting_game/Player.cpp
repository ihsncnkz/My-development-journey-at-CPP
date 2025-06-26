
#include "Player.h"

Player::Player(string _pName, int _point) : point(50){}

void Player::pointWin()
{
	point += 10;
}

void Player::pointLoss()
{
	point -= 10;
}

void Player::printInfo()
{
	cout << "Player Name: " << Player::pName << endl;
	cout << "Player point: " << point << endl;
}

int Player::getPoint()
{
	return point;
}

string Player::getPName()
{
	return pName;
}