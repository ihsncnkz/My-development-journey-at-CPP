#include "ClothingProduct.h"

ClothingProduct::ClothingProduct(){}

ClothingProduct::ClothingProduct(string _bard, string _name, int _quantity, double _price, string _size) :
	Product(_bard, _name, _quantity, _price), size(_size) {}

void ClothingProduct::insertDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"INSERT INTO clothing_products (bard, name, quantity, price, size) VALUES (?, ?, ?, ?, ?)"
			)
		);
		pstmt->setString(1, bard);
		pstmt->setString(2, name);
		pstmt->setInt(3, quantity);
		pstmt->setDouble(4, price);
		pstmt->setString(5, size);
		pstmt->execute();
		cout << "ClothingProduct inserted to DB!" << endl;
	}
	catch (sql::SQLException e)
	{
		cerr << "SQL Exception" << e.what() << endl;
	}
}

void ClothingProduct::deleteFromDB(sql::Connection* con, int searchID)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"DELETE FROM clothing_products WHERE id = ?"
			)
		);
		pstmt->setInt(1, searchID);
		pstmt->execute();
		cout << "ClothingProduct with ID " << searchID << " deleted from DB!\n";
	}
	catch (sql::SQLException e)
	{
		cerr << "SQL Exception" << e.what() << endl;
	}
}

void ClothingProduct::searchInDB(sql::Connection* con, int searchID)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"SELECT * FROM clothing_products WHERE id = ?"
			)
		);
		pstmt->setInt(1, searchID);
		unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		if (res->next())
		{
			cout << "ID: " << res->getInt("id") << endl;
			cout << "Bard: " << res->getString("bard") << endl;
			cout << "Name: " << res->getString("name") << endl;
			cout << "Quantity: " << res->getInt("quantity") << endl;
			cout << "Price: " << res->getDouble("price") << endl;
			cout << "Size: " << res->getString("size") << endl;
		}
		else
		{
			cout << "ClothingProduct with ID " << searchID << " not found." << endl;
		}
	}
	catch (sql::SQLException e)
	{
		cerr << "SQL Exception" << e.what() << endl;
	}
}

void ClothingProduct::displayInfo() const
{
	Product::displayInfo();
	cout << size << endl;
}

void ClothingProduct::displayAllFromDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("SELECT * FROM clothing_products"));
		unique_ptr <sql::ResultSet> res(pstmt->executeQuery());
		std::cout << "---- ALL Tech Products ----" << std::endl;
		while (res->next())
		{
			std::cout << "ID: " << res->getInt("id") << " | ";
			std::cout << "Brand: " << res->getString("bard") << " | ";
			std::cout << "Name: " << res->getString("name") << " | ";
			std::cout << "Quantity: " << res->getInt("quantity") << " | ";
			std::cout << "Price: " << res->getDouble("price") << " | ";
			std::cout << "Size: " << res->getString("size") << endl;
		}
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exception (displayAllFromDB): " << e.what() << endl;
	}

}

void ClothingProduct::deleteAllFromDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("DELETE FROM clothing_products"));
		int affectedRows = pstmt->executeUpdate();
		cout << affectedRows << " rows deleted from clothing_products!" << endl;
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exception (deleteAllFromDB): " << e.what() << endl;
	}
}