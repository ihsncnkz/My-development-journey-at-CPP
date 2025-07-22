#pragma once

#include "Product.h"

class CleaningProduct : public Product
{
private:
	string usegeArea;

public:
	CleaningProduct();
	CleaningProduct(string _bard, string _name, int _quantity, double _price, string uA);

	void insertDB(sql::Connection* con) override;
	void deleteFromDB(sql::Connection* con, int searchID) override;
	void searchInDB(sql::Connection* con, int searchID) override;
	void displayAllFromDB(sql::Connection* con) override;
	void deleteAllFromDB(sql::Connection* con) override;

	void displayInfo() const override;
};

