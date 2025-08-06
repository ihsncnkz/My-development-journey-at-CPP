#pragma once
#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

class Customer
{
private:
	int customID;
	string name;
	vector<Account> accounts;

public:

	Customer(int id, const string& n);

	Account* findAccount(int accNum);

	int getCustomID() const;
	void setCustomID(int id);

	string getName() const;
	void setName(string name);

	vector<Account>& getAccount();
	void setAccount(const vector<Account>& newAccount);
	void addAccount(const Account& a);
};

