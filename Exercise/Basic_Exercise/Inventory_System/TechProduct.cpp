#include "TechProduct.h"

TechProduct::TechProduct() {}

TechProduct::TechProduct(string _bard, string _name, int _quantity, double _price, string sN) :
	Product(_bard, _name, _quantity, _price), serialNumber(sN) {}

void TechProduct::displayInfo() const
{
	Product::displayInfo();
	cout << "SerialNumber: " << serialNumber;
}

void TechProduct::insertDB(sql::Connection* con)
{
	if (con == nullptr) {
		std::cerr << "[ERROR] 'con' pointer is NULL!" << std::endl;
		return;
	}

	

	std::unique_ptr<sql::PreparedStatement> pstmt(
		con->prepareStatement(
			"INSERT INTO tech_products (bard, name, quantity, price, serialNumber) VALUES (?, ?, ?, ?, ?)"
		)
	);

	if (!pstmt) {
		std::cerr << "[ERROR] pstmt (prepareStatement) NULL!" << std::endl;
		return;
	}

	pstmt->setString(1, bard);          
	pstmt->setString(2, name);          
	pstmt->setInt(3, quantity);         
	pstmt->setDouble(4, price);         
	pstmt->setString(5, serialNumber);  
	pstmt->execute();
	cout << "TechProduct inserted to DB!" << endl;
}

void TechProduct::deleteFromDB(sql::Connection* con, int searchID)
{
	try {
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("DELETE FROM tech_products WHERE id = ?"));

		pstmt->setInt(1, searchID);
		pstmt->execute();
		cout << "TechProduct with ID " << searchID << " deleted from DB!" << endl;
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exeception: " << e.what() << endl;
	}
	
}

void TechProduct::searchInDB(sql::Connection* con, int searchID)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("SELECT * FROM tech_products WHERE id = ?"));
		pstmt->setInt(1, searchID);
		unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		if (res->next())
		{
			cout << "ID: " << res->getInt("id") << endl;
			cout << "Brand: " << res->getString("bard") << endl;
			cout << "Name: " << res->getString("name") << endl;
			cout << "Quantity: " << res->getInt("quantity") << endl;
			cout << "Price: " << res->getDouble("price") << endl;
			cout << "SerialNumber: " << res->getString("serialNumber") << endl;
		}
		else
		{
			cout << "TechProduct with ID " << searchID << " not found." << endl;
		}
	}
	catch (sql::SQLException e)
	{
		cerr << "SQL Exception: " << e.what() << endl;
	}
}

void TechProduct::displayAllFromDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("SELECT * FROM tech_products"));
		unique_ptr <sql::ResultSet> res(pstmt->executeQuery());
		std::cout << "---- ALL Tech Products ----" << std::endl;
		while (res->next())
		{
			std::cout << "ID: " << res->getInt("id") << " | ";
			std::cout << "Brand: " << res->getString("bard") << " | ";
			std::cout << "Name: " << res->getString("name") << " | ";
			std::cout << "Quantity: " << res->getInt("quantity") << " | ";
			std::cout << "Price: " << res->getDouble("price") << " | ";
			std::cout << "SerialNumber: " << res->getString("serialNumber") << endl;
		}
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exception (displayAllFromDB): " << e.what() << endl;
	}
	
}

void TechProduct::deleteAllFromDB(sql::Connection* con)
{
	try
	{
		unique_ptr<sql::PreparedStatement> pstmt(
			con->prepareStatement("DELETE FROM tech_products"));
		int affectedRows = pstmt->executeUpdate();
		cout << affectedRows << " rows deleted from tech_products!" << endl;
	}
	catch (sql::SQLException& e)
	{
		cerr << "SQL Exception (deleteAllFromDB): " << e.what() << endl;
	}
}