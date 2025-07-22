#include "CleaningProduct.h"

CleaningProduct::CleaningProduct() {}

CleaningProduct::CleaningProduct(string _bard, string _name, int _quantity, double _price, string uA) :
	Product(_bard, _name, _quantity, _price), usegeArea(uA){}

void CleaningProduct::insertDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"INSERT INTO cleaning_products (bard, name, quantity, price, usegeArea) VALUES (?, ?, ?, ?, ?)"
			)
		);
		pstmt->setString(1, bard);
		pstmt->setString(2, name);
		pstmt->setInt(3, quantity);
		pstmt->setDouble(4, price);
		pstmt->setString(5, usegeArea);
		pstmt->execute();
		cout << "CleaningProduct inserted to DB!" << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "SQL Exception " << e.what() << endl;
	}
}

void CleaningProduct::deleteFromDB(sql::Connection* con, int searchID)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"DELETE FROM cleaning_products WHERE id = ?"
			)
		);
		pstmt->setInt(1, searchID);
		pstmt->execute();
		cout << "CleaningProduct with ID " << searchID << " deleted from DB!" << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "SQL Exception " << e.what() << endl;
	}
}

void CleaningProduct::searchInDB(sql::Connection* con, int searchID)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"SELECT * FROM cleaning_products WHERE id = ?"
			)
		);
		pstmt->setInt(1, searchID);
		unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		if (res->next()) {
			cout << "ID: " << res->getInt("id") << std::endl;
			cout << "Bard: " << res->getString("bard") << std::endl;
			cout << "Name: " << res->getString("name") << std::endl;
			cout << "Quantity: " << res->getInt("quantity") << std::endl;
			cout << "Price: " << res->getDouble("price") << std::endl;
			cout << "Usage Area: " << res->getString("usegeArea") << std::endl;
		}
		else {
			cout << "CleaningProduct with ID " << searchID << " not found." << std::endl;
		}
	}
	catch (sql::SQLException e)
	{
		cout << "SQL Exception " << e.what() << endl;
	}
}

void CleaningProduct::displayInfo() const
{
	Product::displayInfo();
	cout << usegeArea << endl;
}

void CleaningProduct::displayAllFromDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("SELECT * FROM cleaning_products"));
		unique_ptr <sql::ResultSet> res(pstmt->executeQuery());
		std::cout << "---- ALL Tech Products ----" << std::endl;
		while (res->next())
		{
			std::cout << "ID: " << res->getInt("id") << " | ";
			std::cout << "Brand: " << res->getString("bard") << " | ";
			std::cout << "Name: " << res->getString("name") << " | ";
			std::cout << "Quantity: " << res->getInt("quantity") << " | ";
			std::cout << "Price: " << res->getDouble("price") << " | ";
			std::cout << "Usage Area: " << res->getString("usegeArea") << endl;
		}
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exception (displayAllFromDB): " << e.what() << endl;
	}

}

void CleaningProduct::deleteAllFromDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("DELETE FROM cleaning_products"));
		int affectedRows = pstmt->executeUpdate();
		cout << affectedRows << " rows deleted from cleaning_products!" << endl;
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exception (deleteAllFromDB): " << e.what() << endl;
	}
}