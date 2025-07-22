#include "Product.h"

Product::Product(){}

Product::Product(string _bard, string _name, int _quantity, double _price) :
	bard(_bard), name(_name), quantity(_quantity), price(_price) {}

void Product::displayInfo() const
{
	cout << "ID: " << id << endl;
	cout << "Bard: " << bard << endl;
	cout << "Name: " << name << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price: " << price << endl;
}
