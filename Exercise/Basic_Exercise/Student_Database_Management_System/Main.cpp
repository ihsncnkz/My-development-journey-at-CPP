#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include "Student.h"

using namespace std;

int main()
{
	try {
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con = nullptr;
		sql::Statement* stmt = nullptr;
		sql::ResultSet* res = nullptr;
		sql::PreparedStatement* pstmt = nullptr;

		driver = sql::mysql::get_mysql_driver_instance();
		if (!driver) {
			cerr << "No Connection MySQL" << endl;
			return 1;
		}
		con = driver->connect("host:port", "User Name", "Password");
		con->setSchema("school");



		map<int, Student> mStundet;
		bool value = true;

		while (value)
		{
			int userValue;
			int _id;
			string sn, sln;
			cout << "1 Add student" << endl;
			cout << "2 delete student" << endl;
			cout << "3 Print all student" << endl;
			cout << "4 Search student" << endl;
			cout << "5 Exit Program" << endl;
			cout << "Select anyone: ";
			cin >> userValue;

			switch (userValue)
			{
			case 1:
			{
				if (pstmt) {
					delete pstmt;
					pstmt = nullptr;
				}

				cout << "Enter id: ";
				cin >> _id;
				cin.ignore();

				cout << "Enter name: ";
				cin >> sn;

				cout << "Enter last name: ";
				cin >> sln;

				mStundet[_id] = Student(_id, sn, sln);

				pstmt = con->prepareStatement("INSERT INTO students (id, name, surname) VALUES (?,?,?)");
				pstmt->setInt(1, _id);
				pstmt->setString(2, sn);
				pstmt->setString(3, sln);
				pstmt->execute();
				break;
			}
			case 2:
			{
				if (pstmt) {
					delete pstmt;
					pstmt = nullptr;
				}

				cout << "Enter id for delete: ";
				cin >> _id;
				mStundet.erase(_id);

				pstmt = con->prepareStatement("DELETE FROM students WHERE id = ?");
				pstmt->setInt(1, _id);
				pstmt->execute();
				break;
			}
			case 3:
			{
				if (res) {
					delete res;
					res = nullptr;
				}
				if (stmt) {
					delete stmt;
					stmt = nullptr;
				}

				//for (const auto& pair : mStundet)
				//{
				//	pair.second.printInfo();
				//}

				stmt = con->createStatement();
				res = stmt->executeQuery("SELECT id, name, surname FROM students");

				while (res->next())
				{
					int id = res->getInt("id");
					std::string name = res->getString("name");
					std::string surname = res->getString("surname");

					cout << "ID: " << id << endl;
					cout << "Name: " << name << endl;
					cout << "Surname: " << surname << endl;
				}
				break;
			}
			case 4:
			{
				if (pstmt) {
					delete pstmt;
					pstmt = nullptr;
				}
				if (res) {
					delete res;
					res = nullptr;
				}

				cout << "Enter id for seach: ";
				cin >> _id;
				auto it = mStundet.find(_id);

				//if (it != mStundet.end())
				//{
				//	it->second.printInfo();
				//}

				pstmt = con->prepareStatement("SELECT id, name, surname FROM students WHERE id = ?");
				pstmt->setInt(1, _id);

				res = pstmt->executeQuery();

				if (res->next())
				{
					int id = res->getInt("id");
					std::string name = res->getString("name");
					std::string surname = res->getString("surname");

					cout << "ID: " << id << endl;
					cout << "Name: " << name << endl;
					cout << "Surname: " << surname << endl;
				}
				break;
			}
			case 5:
			{
				cout << "Thanks use my program!";
				value = false;
				break;
			}
			default:
			{
				cout << "Please enter in one to five.";
				break;
			}
			}
		}

		if (res) { delete res;    res = nullptr; }
		if (pstmt) { delete pstmt;  pstmt = nullptr; }
		if (stmt) { delete stmt;   stmt = nullptr; }
		if (con) { delete con;    con = nullptr; }

		return 0;
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Error: " << e.what() << endl;
	}
	catch (std::bad_alloc& e) {
		cerr << "Memory Error: " << e.what() << endl;
	}
	catch (...) {
		cerr << "An unknown error occurred!" << endl;
	}

    return 0;
}