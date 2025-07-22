#include <iostream>
#include <memory>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/exception.h>
#include "Product.h"
#include "TechProduct.h"
#include "ClothingProduct.h"
#include "CleaningProduct.h"
#include "FoodProduct.h"

using namespace std;

void insertDB(int _insertValue, sql::Connection* con)
{
	switch (_insertValue)
	{
	case 1:
	{
		string bard, name, serialNumber;
		int quantity;
		double price;
		cout << "Please, Enter the Bard: ";
		getline(cin, bard);

		cout << "Please, Enter the Name: ";
		getline(cin, name);

		cout << "Please, Enter the Quantity: ";
		cin >> quantity;

		cout << "Please, Enter the Price: ";
		cin >> price;
		cin.ignore();

		cout << "Please, Enter the Serial Number: ";
		getline(cin, serialNumber);

		TechProduct t1(bard, name, quantity, price, serialNumber);

		t1.insertDB(con);

		break;
	}
	case 2:
	{
		string bard, name, size;
		int quantity;
		double price;
		cout << "Please, Enter the Bard: ";
		getline(cin, bard);

		cout << "Please, Enter the Name: ";
		getline(cin, name);

		cout << "Please, Enter the Quantity: ";
		cin >> quantity;

		cout << "Please, Enter the Price: ";
		cin >> price;
		cin.ignore();

		cout << "Please, Enter the size:";
		getline(cin, size);

		ClothingProduct c1(bard, name, quantity, price, size);

		c1.insertDB(con);

		break;
	}
	case 3:
	{
		string bard, name, usegeArea;
		int quantity;
		double price;
		cout << "Please, Enter the Bard: ";
		getline(cin, bard);

		cout << "Please, Enter the Name: ";
		getline(cin, name);

		cout << "Please, Enter the Quantity: ";
		cin >> quantity;

		cout << "Please, Enter the Price: ";
		cin >> price;
		cin.ignore();

		cout << "Please, Enter the Usege Area: ";
		getline(cin, usegeArea);

		CleaningProduct cl1(bard, name, quantity, price, usegeArea);

		cl1.insertDB(con);

		break;
	}
	case 4:
	{
		string bard, name, expirationDate;
		int quantity;
		double price;
		cout << "Please, Enter the Bard: ";
		getline(cin, bard);

		cout << "Please, Enter the Name: ";
		getline(cin, name);

		cout << "Please, Enter the Quantity: ";
		cin >> quantity;

		cout << "Please, Enter the Price: ";
		cin >> price;
		cin.ignore();

		cout << "Please, Enter the Expiration Date: ";
		getline(cin, expirationDate);

		FoodProduct f1(bard, name, quantity, price, expirationDate);
		
		f1.insertDB(con);

		break;
	}
	default:
	{
		cout << "Please enter in one to four.";
		break;
	}
		
	}
}

void deleteDB(int _deleteValue, sql::Connection* con)
{
	switch (_deleteValue)
	{

	case 1:
	{
		int deleteID;
		cout << "Please enter the ID of the data you want to delete: ";
		cin >> deleteID;
		
		TechProduct t;
		
		t.deleteFromDB(con, deleteID);
		break;
	}
	case 2:
	{
		int deleteID;
		cout << "Please enter the ID of the data you want to delete: ";
		cin >> deleteID;

		ClothingProduct c;

		c.deleteFromDB(con, deleteID);

		break;
	}
	case 3:
	{
		int deleteID;
		cout << "Please enter the ID of the data you want to delete: ";
		cin >> deleteID;

		CleaningProduct cl;

		cl.deleteFromDB(con, deleteID);

		break;
	}
	case 4:
	{
		int deleteID;
		cout << "Please enter the ID of the data you want to delete: ";
		cin >> deleteID;

		FoodProduct f;

		f.deleteFromDB(con, deleteID);
		
		break;
	}
	default:
	{
		cout << "Please enter in one to four.";
		break;
	}
	}
}

void searchDB(int searchValue, sql::Connection* con)
{
	switch (searchValue)
	{

	case 1:
	{
		int searchID;
		cout << "Please enter the ID of the data you want to delete: ";
		cin >> searchID;

		TechProduct t;

		t.searchInDB(con, searchID);
		break;
	}
	case 2:
	{
		int searchID;
		cout << "Please enter the ID of the data you want to delete: ";
		cin >> searchID;

		ClothingProduct c;

		c.searchInDB(con, searchID);

		break;
	}
	case 3:
	{
		int searchID;
		cout << "Please enter the ID of the data you want to delete: ";
		cin >> searchID;

		CleaningProduct cl;

		cl.searchInDB(con, searchID);

		break;
	}
	case 4:
	{
		int searchID;
		cout << "Please enter the ID of the data you want to delete: ";
		cin >> searchID;

		FoodProduct f;

		f.searchInDB(con, searchID);

		break;
	}
	default:
	{
		cout << "Please enter in one to four.";
		break;
	}
	}
}

void printAllTable(int Value, sql::Connection* con)
{
	switch (Value)
	{

	case 1:
	{
		TechProduct t;

		t.displayAllFromDB(con);

		break;
	}
	case 2:
	{
		ClothingProduct c;

		c.displayAllFromDB(con);

		break;
	}
	case 3:
	{
		CleaningProduct cl;

		cl.displayAllFromDB(con);

		break;
	}
	case 4:
	{
		FoodProduct f;

		f.displayAllFromDB(con);

		break;
	}
	default:
	{
		cout << "Please enter in one to four.";
		break;
	}
	}
}

void deleteAllData(int deleteAllValue, sql::Connection* con)
{
	switch (deleteAllValue)
	{

	case 1:
	{
		TechProduct t;

		t.deleteAllFromDB(con);

		break;
	}
	case 2:
	{
		ClothingProduct c;

		c.deleteAllFromDB(con);

		break;
	}
	case 3:
	{
		CleaningProduct cl;

		cl.deleteAllFromDB(con);

		break;
	}
	case 4:
	{
		FoodProduct f;

		f.deleteAllFromDB(con);

		break;
	}
	default:
	{
		cout << "Please enter in one to four.";
		break;
	}
	}
}

int main()
{
	try
	{
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
		if (!driver) {
			cerr << "No Driver" << endl;
			return 1;
		}
		unique_ptr<sql::Connection> con(driver->connect("Your Path", "Your user name", "your password"));

		con->setSchema("inventory_db");
		
		bool value = true;

		while (value)
		{
			int userValue;
			cout << "1 : Insert Data" << endl;
			cout << "2 : Delete Data" << endl;
			cout << "3 : Search Data" << endl;
			cout << "4 : Print All Data" << endl;
			cout << "5 : Delete All Data" << endl;
			cout << "6 : Exit System!" << endl;
			cout << "Please, select what do you want: ";
			cin >> userValue;

			switch (userValue)
			{
			case 1:
			{
				int insertValue;
				cout << "Which table do you want to add data to ?" << endl;
				cout << "1 : Teach table" << endl;
				cout << "2 : Clothing table" << endl;
				cout << "3 : Cleaning table" << endl;
				cout << "4 : Food table" << endl;
				cout << "Please, select what do you want: ";
				cin >> insertValue;
				cin.ignore();

				insertDB(insertValue, con.get());

				break;
			}
			case 2:
			{
				int deleteValue;
				cout << "Which table do you want to add data to ?" << endl;
				cout << "1 : Teach table" << endl;
				cout << "2 : Clothing table" << endl;
				cout << "3 : Cleaning table" << endl;
				cout << "4 : Food table" << endl;
				cout << "Please, select what do you want: ";
				cin >> deleteValue;
				cin.ignore();

				deleteDB(deleteValue, con.get());

				break;
			}
			case 3:
			{
				int searchValue;
				cout << "Which table do you want to add data to ?" << endl;
				cout << "1 : Teach table" << endl;
				cout << "2 : Clothing table" << endl;
				cout << "3 : Cleaning table" << endl;
				cout << "4 : Food table" << endl;
				cout << "Please, select what do you want: ";
				cin >> searchValue;
				cin.ignore();

				searchDB(searchValue, con.get());

				break;
			}
			case 4:
			{
				int Value;
				cout << "Which table do you want to add data to ?" << endl;
				cout << "1 : Teach table" << endl;
				cout << "2 : Clothing table" << endl;
				cout << "3 : Cleaning table" << endl;
				cout << "4 : Food table" << endl;
				cout << "Please, select what do you want: ";
				cin >> Value;
				cin.ignore();

				printAllTable(Value, con.get());

				break;
			}
			case 5:
			{
				int deleteAllValue;
				cout << "Which table do you want to add data to ?" << endl;
				cout << "1 : Teach table" << endl;
				cout << "2 : Clothing table" << endl;
				cout << "3 : Cleaning table" << endl;
				cout << "4 : Food table" << endl;
				cout << "Please, select what do you want: ";
				cin >> deleteAllValue;
				cin.ignore();

				deleteAllData(deleteAllValue, con.get());

				break;
			}
			case 6:
			{
				cout << "Thanks use my program :)" << endl;
				value = false;
				break;
			}
			default:
				cout << "Please enter in one to six.";
				break;
			}
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Exception: " << e.what() << std::endl;
	}

	return 0;
}