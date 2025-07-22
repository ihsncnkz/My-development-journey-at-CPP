#include "FoodProduct.h"

FoodProduct::FoodProduct() {}

FoodProduct::FoodProduct(string _bard, string _name, int _quantity, double _price, string epD) :
	Product(_bard, _name, _quantity, _price), expirationDate(epD) {}

void FoodProduct::insertDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"INSERT INTO food_products (bard, name, quantity, price, expirationDate) VALUES (?, ?, ?, ?, ?)"
			)
		);
		pstmt->setString(1, bard);
		pstmt->setString(2, name);
		pstmt->setInt(3, quantity);
		pstmt->setDouble(4, price);
		pstmt->setString(5, expirationDate);
		pstmt->execute();
		cout << "CleaningProduct inserted to DB!" << endl;
	}
	catch (sql::SQLException e)
	{
		cout << "SQL Exception " << e.what() << endl;
	}
}

void FoodProduct::deleteFromDB(sql::Connection* con, int searchID)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"DELETE FROM food_products WHERE id = ?"
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

void FoodProduct::searchInDB(sql::Connection* con, int searchID)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement(
				"SELECT * FROM food_products WHERE id = ?"
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
			cout << "Expiration Date: " << res->getString("expirationDate") << std::endl;
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

void FoodProduct::displayInfo() const
{
	Product::displayInfo();
	cout << expirationDate << endl;
}

void FoodProduct::displayAllFromDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("SELECT * FROM food_products"));
		unique_ptr <sql::ResultSet> res(pstmt->executeQuery());
		std::cout << "---- ALL Tech Products ----" << std::endl;
		while (res->next())
		{
			std::cout << "ID: " << res->getInt("id") << " | ";
			std::cout << "Brand: " << res->getString("bard") << " | ";
			std::cout << "Name: " << res->getString("name") << " | ";
			std::cout << "Quantity: " << res->getInt("quantity") << " | ";
			std::cout << "Price: " << res->getDouble("price") << " | ";
			std::cout << "Expiration Date: " << res->getString("expirationDate") << endl;
		}
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exception (displayAllFromDB): " << e.what() << endl;
	}

}

void FoodProduct::deleteAllFromDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("DELETE FROM food_products"));
		int affectedRows = pstmt->executeUpdate();
		cout << affectedRows << " rows deleted from food_products!" << endl;
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exception (deleteAllFromDB): " << e.what() << endl;
	}
}