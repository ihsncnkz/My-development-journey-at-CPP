#include <iostream>
#include <map>
#include <string>
#include "Library.h"

using namespace std;

void addBook(map<int, Library>& mBook)
{
	int bID, sNO;
	string bName, aName;

	cout << "Please, Enter the ID of book: ";
	cin >> bID;
	cin.ignore();

	cout << "Please, Enter the name of book: ";
	getline(cin, bName);

	cout << "Please, Enter the author name of book: ";
	getline(cin, aName);

	cout << "Please, Enter the shelf of book: ";
	cin >> sNO;
	/*
	Library lbr;
	lbr.setBookID(bID);
	lbr.setBookName(bName);
	lbr.setAuthorName(aName);
	lbr.setSelfNo(sNO);
	*/

	mBook.emplace(bID, Library(bID, bName, aName, sNO));

	cout << "Book added successfully!" << endl;
}

void showBookInfo(map<int, Library>& mBook)
{
	int bID;
	cout << "Please, Enter the ID of book:  ";
	cin >> bID;

	for (const auto& mb : mBook)
	{
		if (bID == mb.first)
		{
			cout << "The book you are looking for has been found. Information: ";
			mb.second.printInfo();
			cout << endl;
			return;
		}
	}
	cout << "The book you are looking for hasn't been found. " << endl;
}

void deleteBook(map<int, Library>& mBook)
{
	int bID;
	cout << "Please, Enter the ID of book:  ";
	cin >> bID;

	for (const auto& mb : mBook)
	{
		if (bID == mb.first)
		{
			mBook.erase(bID);
			cout << "Deleted the book information ..." << endl;
			return;
		}
	}
	cout << "The book you are looking for hasn't been found. " << endl;
}

void listBook(map<int, Library>& mBook)
{
	if (mBook.empty())
	{
		cout << "The registered book cannot be found in the library..." << endl;
		return;
	}
	/*
	for (const auto& bm : mBook)
	{
		cout << bm.first << " ";
		bm.second.printInfo();
		cout << endl;
	}
	cout << endl;
	*/

	cout << "***** The Books in Library *****" << endl;
	for (auto it = mBook.begin(); it != mBook.end(); it++)
	{
		int id = it->first;
		const Library& book = it->second;
		//cout << "BookID: " << book.getBookID() << " Book Name: " << book.getBookName() << " Author Name: " << book.getAuthorName() << " Shelf No: " << book.getShelfNo() << endl;
		book.printInfo();
	}
	
}

int main() {

	// Testing Lbirary Class
	
	Library lbr1(1, "Sefiller", "Victor Hugo", 129);

	lbr1.printInfo();

	lbr1.setBookID(2);
	lbr1.setBookName("ABC");
	lbr1.setAuthorName("ihsan cenkiz");
	lbr1.setSelfNo(100);

	cout << lbr1.getBookID() << endl;
	cout << lbr1.getBookName() << endl;
	cout << lbr1.getAuthorName() << endl;
	cout << lbr1.getShelfNo() << endl;
	

	// Create Map with Library Class
	
	map<int, Library> bookMap;

	bookMap[101] = Library(101, "1984", "George Orwell", 3);
	bookMap[102] = Library(102, "Brave New World", "Aldous Huxley", 5);
	bookMap[107] = Library(107, "The Hobbit", "J.R.R. Tolkien", 6);
	bookMap[108] = Library(108, "Fahrenheit 451", "Ray Bradbury", 5);

	for (const auto& bm : bookMap)
	{
		cout << bm.first << " ";
		bm.second.printInfo();
	}
	cout << endl;

	int searchID = 101;
	if (bookMap.find(searchID) != bookMap.end())
	{
		cout << endl << "The grade point average of student number " << searchID << " ";
		bookMap[searchID].printInfo();
	}
	cout << endl;

	bookMap.erase(101);

	for (const auto& bm : bookMap)
	{
		cout << bm.first << " ";
		bm.second.printInfo();
	}
	cout << endl;

	bookMap[102] = Library(102, "War and Peace", "Leo Tolstoy", 9);

	for (const auto& bm : bookMap)
	{
		cout << bm.first << " ";
		bm.second.printInfo();
	}
	cout << endl;
	

	// First Way
	map<int, Library> mBook;
	int userValue = 0;
	
	do
	{
		cout << "--- Welcome to Library ---" << endl;
		cout << "1. Add Book" << endl;
		cout << "2. Show the information of book" << endl;
		cout << "3. Delete Book" << endl;
		cout << "4. Listing Book" << endl;
		cout << "5. Exit" << endl;
		cout << "Please, Make a choise: ";
		cin >> userValue;

		switch (userValue)
		{
		case 1:
			addBook(mBook);
			break;
		case 2:
			showBookInfo(mBook);
			break;
		case 3:
			deleteBook(mBook);
			break;
		case 4:
			listBook(mBook);
			break;
		case 5:
			cout << "Exiting the system..." << endl;
			break;
		default:
			cout << "You did not enter a value between 1 and 5. Please enter a value between 1 and 5!" << endl;
			break;
		}

	} while (userValue != 5);
	
	// Second Way

	do
	{
		cout << "--- Welcome to Library ---" << endl;
		cout << "1. Add Book" << endl;
		cout << "2. Show the information of book" << endl;
		cout << "3. Delete Book" << endl;
		cout << "4. Listing Book" << endl;
		cout << "5. Exit" << endl;
		cout << "Please, Make a choise: ";
		cin >> userValue;

		switch (userValue)
		{
		case 1:
		{
			int bID, sNO;
			string bName, aName;
			cout << endl;
			cout << "Please, Enter the ID of book: ";
			cin >> bID;
			cin.ignore();

			cout << "Please, Enter the name of book: ";
			getline(cin, bName);

			cout << "Please, Enter the author name of book: ";
			getline(cin, aName);

			cout << "Please, Enter the shelf of book: ";
			cin >> sNO;
			/*
			Library lbr;
			lbr.setBookID(bID);
			lbr.setBookName(bName);
			lbr.setAuthorName(aName);
			lbr.setSelfNo(sNO);
			*/

			mBook.emplace(bID, Library(bID, bName, aName, sNO));

			cout << "Book added successfully!" << endl;
			break;
		}
		case 2:
		{
			int bID;
			cout << "Please, Enter the ID of book:  ";
			cin >> bID;

			auto it = mBook.find(bID); // map<int, Library>::const_iterator it = mBook.find(bID);
			if (it != mBook.end())
			{
				cout << "The book you are looking for has been found. Information: " << endl;
				const Library& book = it->second;
				cout << "BookID: " << book.getBookID() << " Book Name: " << book.getBookName() << " Author Name: " << book.getAuthorName() << " Shelf No: " << book.getShelfNo() << endl;
			}
			else
			{
				cout << "The book you are looking for hasn't been found. " << endl;
			}
			break;
		}
		case 3:
		{
			int bID;
			cout << "Please, Enter the ID of book:  ";
			cin >> bID;

			if (mBook.erase(bID))
			{
				cout << "Deleted the book information ..." << endl;
			}
			else
			{
				cout << "The book you are looking for hasn't been found. " << endl;
			}
			break;
		}
		case 4:
			listBook(mBook);
			break;

		case 5:
			cout << "Exiting the system..." << endl;
			break;

		default:
			cout << "You did not enter a value between 1 and 5. Please enter a value between 1 and 5!" << endl;
			break;
		}

	} while (userValue != 5);

	return 0;
}