#pragma once

#include "Product.h"

class FoodProduct : public Product
{
private:
	string expirationDate;

public:
	FoodProduct();
	FoodProduct(string _bard, string _name, int _quantity, double _price, string epD);

	void insertDB(sql::Connection* con) override;
	void deleteFromDB(sql::Connection* con, int searchID) override;
	void searchInDB(sql::Connection* con, int searchID) override;
	void displayAllFromDB(sql::Connection* con) override;
	void deleteAllFromDB(sql::Connection* con) override;

	void displayInfo() const override;
};

