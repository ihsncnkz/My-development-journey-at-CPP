#pragma once
#include <iostream>
#include <vector>
#include "Transaction.h"

using namespace std;

class Account
{
private:
	int accountNumber;
	double balance;
	vector<Transaction> transaction;

public:
	Account(int num);

	void deposit(double amount, const string& date);

	bool withdraw(double amount, const string& date);

	void addTransaction(const string& type, double amount, const string& date);

	void printInfo() const;

	void printTransaction() const;

	int getAccountNumber() const;
	void setAccountNumber(int accountNumber);

	double getBalance() const;
	void setBalance(double balance);

	const vector<Transaction>& getTransaction() const;
	void setTransaction(const vector<Transaction>& newTransaction);
	void addTransaction(const Transaction& t);

};

