#include "Transaction.h"

Transaction::Transaction(const string& type, double amount, const string& date) : type(type), amount(amount), date(date){}

string Transaction::getType() const
{
	return type;
}
void Transaction::setType(string type)
{
	this->type = type;
}

double Transaction::getAmount() const
{
	return amount;
}
void Transaction::setAmount(double amount)
{
	this->amount = amount;
}

string Transaction::getDate() const
{
	return date;
}
void Transaction::setDate(string date)
{
	this->date = date;
}