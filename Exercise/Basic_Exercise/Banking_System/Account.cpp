#include "Account.h"

Account::Account(int num) : accountNumber(num), balance(0) {}

void Account::deposit(double amount, const string& date) {
	balance += amount;
	transaction.emplace_back("Deposit", amount, date);
}

bool Account::withdraw(double amount, const string& date)
{
	if (amount > balance) return false;
	balance -= amount;
	transaction.emplace_back("Withdraw", amount, date);
}

void Account::addTransaction(const string& type, double amount, const string& date)
{
	transaction.emplace_back(type, amount, date);
}

void Account::printInfo() const
{
	cout << "Acount Number:" << accountNumber << "\nBalance: " << balance << endl;
}

void Account::printTransaction() const
{
	cout << "Recent Transactions:\n";
	for (const auto& t : transaction)
	{
		cout << t.getDate() << " | " << t.getType() << " | " << t.getAmount() << endl;
	}
}

int Account::getAccountNumber() const
{
	return accountNumber;
}

void Account::setAccountNumber(int accountNumber)
{
	this->accountNumber = accountNumber;
}

double Account::getBalance() const
{
	return balance;
}

void Account::setBalance(double balance)
{
	this->balance = balance;
}

const vector<Transaction>& Account::getTransaction() const
{
	return transaction;
}

void Account::setTransaction(const vector<Transaction>& newTransaction)
{
	transaction = newTransaction;
}

void Account::addTransaction(const Transaction& t)
{
	transaction.push_back(t);
}