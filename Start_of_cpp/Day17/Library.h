#pragma once
#include <iostream>

using namespace std;

class Library {
private:
	int bookID;
	string bookName;
	string authorName;
	int shelfNo;

public:

	Library();

	Library(int bookID, string bookName, string authorName, int shelfNo);

	void printInfo() const;

	int getBookID() const;
	void setBookID(int _bookID);

	string getBookName() const;
	void setBookName(string _bookName);

	string getAuthorName() const;
	void setAuthorName(string _authorName);

	int getShelfNo() const;
	void setSelfNo(int _shelfNo);

};