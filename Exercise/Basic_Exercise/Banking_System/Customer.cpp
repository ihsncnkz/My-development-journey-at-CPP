#include "Customer.h"

Customer::Customer(int id, const string& n) : customID(id), name(n) {}

Account* Customer::findAccount(int accNum)
{
	for (auto& acc : accounts)
	{
		if (acc.getAccountNumber() == accNum) return &acc;
	}
	return nullptr;
}

int Customer::getCustomID() const
{
	return customID;
}

void Customer::setCustomID(int id)
{
	this->customID = id;
}

string Customer::getName() const
{
	return name;
}

void Customer::setName(string name)
{
	this->name = name;
}

vector<Account>& Customer::getAccount()
{
	return accounts;
}

void Customer::setAccount(const vector<Account>& newAccount)
{
	accounts = newAccount;
}

void Customer::addAccount(const Account& a)
{
	accounts.push_back(a);
}