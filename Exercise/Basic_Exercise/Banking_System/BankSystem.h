#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Customer.h"
using namespace std;


class BankSystem
{
private:
	vector<Customer> customers;
	int nextCustomerID = 1;
	int nextAccountNum = 1001;

public:

	void addCustomer();

	Customer* findCustomer(vector<Customer>& customers,int id);

	void openAccount();

	void deposit();

	void withdraw();

	void transfer();
	
	void printAccountInfo();

	void menu();
};

