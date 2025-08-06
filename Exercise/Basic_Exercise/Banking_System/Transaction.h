#pragma once
#include <iostream>

using namespace std;

class Transaction
{
private:
	string type;
	double amount;
	string date;

public:
	Transaction(const string& type, double amount, const string& date);

	string getType() const;
	void setType(string type);

	double getAmount() const;
	void setAmount(double amount);

	string getDate() const;
	void setDate(string date);

};