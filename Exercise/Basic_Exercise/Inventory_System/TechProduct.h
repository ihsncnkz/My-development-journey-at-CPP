#pragma once
#include "Product.h"

class TechProduct : public Product
{
private:
	string serialNumber;

public:
	TechProduct();
	TechProduct(string _bard, string _name, int _quantity, double _price, string serialNumber);

	void displayInfo() const override;

	void insertDB(sql::Connection* con) override;
	void deleteFromDB(sql::Connection* con, int searchID) override;
	void searchInDB(sql::Connection* con, int searchID) override;
	void displayAllFromDB(sql::Connection* con) override;
	void deleteAllFromDB(sql::Connection* con) override;

};