#pragma once
#include <iostream>

using namespace std;

class Bank
{
private:
	string accountHolderName;
	int accountNumber;
	double balance;

public:

	Bank();

	Bank(string ahn, int an, double bln);

	void setAccountHolderName(string ahn);
	string getAccountHolderName();

	void setAccountNumber(int an);
	int getAccountNumber();

	void setBalance(double bln);
	double getBalance();

	void addMonye(double money);
	void withdrawMoney(double money);

	void printInfo() const;

};