#include "Library.h"

Library::Library() : bookID(0), bookName(""), authorName(""), shelfNo(0) {}

Library::Library(int _bookID, string _bookName, string _authorName, int _shelfNo) : bookID(_bookID), bookName(_bookName), authorName(_authorName), shelfNo(_shelfNo) {}

void Library::printInfo() const 
{
	cout << "BookID: " << Library::bookID << " Book Name: " << Library::bookName << " Author Name: " << Library::authorName << " Shelf No: " << Library::shelfNo << endl;
}

void Library::setBookID(int _bookID)
{
	bookID = _bookID;
}

int Library::getBookID() const
{
	return bookID;
}

void Library::setBookName(string _bookName)
{
	bookName = _bookName;
}

string Library::getBookName() const
{
	return bookName;
}

void Library::setAuthorName(string _authorName)
{
	authorName = _authorName;
}

string Library::getAuthorName() const
{
	return authorName;
}

void Library::setSelfNo(int _shelfNo)
{
	shelfNo = _shelfNo;
}

int Library::getShelfNo() const
{
	return shelfNo;
}