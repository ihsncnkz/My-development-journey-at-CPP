#include "Bank.h"

Bank::Bank() : accountHolderName(""), accountNumber(0), balance(0) {}

Bank::Bank(string ahn, int an, double bln) : accountHolderName(ahn), accountNumber(an), balance(bln) {}

void Bank::setAccountHolderName(string ahn)
{
	accountHolderName = ahn;
}
string Bank::getAccountHolderName()
{
	return accountHolderName;
}

void Bank::setAccountNumber(int an)
{
	accountNumber = an;
}
int Bank::getAccountNumber()
{
	return accountNumber;
}

void Bank::setBalance(double bln)
{
	balance = bln;
}
double Bank::getBalance()
{
	return balance;
}

void Bank::addMonye(double money)
{
	balance = balance + money;
}
void Bank::withdrawMoney(double money)
{
	/*
	if (balance == 0)
	{
		cout << "You cant withdraw the money because You dont have money!";
		return;
	}
	else
	{
		if (balance <= -1000)
		{
			cout << "You cant withdraw the money because You dont have money!";
			return;
		}
		else
		{
			balance = balance - money;
			if (balance < 0)
			{
				cout << "The dealership was dropped below 0!";
			}
		}
	}
	*/

	if (balance < money)
	{
		cout << "Insufficient funds! " << endl;
		throw exception("Exception message: Insufficient funds!");
	}
	else
	{
		balance = balance - money;
	}
}

void Bank::printInfo() const
{
	cout << "Account Holder Name: " << accountHolderName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: " << balance << endl;
}