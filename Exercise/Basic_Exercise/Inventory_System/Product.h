#pragma once
#include <iostream>
#include <mysql_driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>

using namespace std;

class Product
{
protected:
	int id;
	string bard;
	string name;
	int quantity;
	double price;

public:
	Product();
	Product(string _bard, string _name, int _quantity, double _price);

	virtual void insertDB(sql::Connection* con) = 0;
	virtual void deleteFromDB(sql::Connection* con, int searchID) = 0;
	virtual void searchInDB(sql::Connection* con, int searchID) = 0;
	virtual void displayAllFromDB(sql::Connection* con) = 0;
	virtual void deleteAllFromDB(sql::Connection* con) = 0;

	virtual void displayInfo() const;

};