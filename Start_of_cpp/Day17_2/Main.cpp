#include <iostream>
#include <list>
#include <string>
#include "Student.h"

using namespace std;

void showManu()
{
	cout << "***** MENU *****" << endl;
	cout << "1. Add new save " << endl;
	cout << "2. Show all list" << endl;
	cout << "3. Delete student with id" << endl;
	cout << "4. Search student" << endl;
	cout << "5. Exit" << endl;
}

void addStudent(list<Student>* lst)
{
	int _sID, _sqr;
	string _sName;

	cout << "Please, Enter the ID of student: ";
	cin >> _sID;
	cin.ignore();

	cout << "Please, Enter the name of student: ";
	getline(cin, _sName);
	
	cout << "Please, Enter the Quiz result of student: ";
	cin >> _sqr;

	Student ogr(_sID, _sName, _sqr);

	lst->push_back(ogr);
}
void showList(list<Student>* lst)
{
	list<Student>::iterator it;

	if (lst->empty())
	{
		cout << "List is empty" << endl;
		return;
	}

	for (it = lst->begin(); it != lst->end(); it++)
	{
		it->printInfo();
	}
	cout << endl;
}

void deleteStudent(list<Student>* lst)
{
	if (lst->empty())
	{
		cout << "You cant delete any student because there is no student in list!" << endl;
		return;
	}

	int _sID;
	cout << "Please write the ID of the student to be deleted: ";
	cin >> _sID;

	list<Student>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++)
	{
		if (it->getSID() == _sID)
		{
			lst->erase(it);
			break;
		}
		else
		{
			cout << "There is no student in the ID you entered." << endl;
		}
	}
	/*
	if (it == lst->end())
	{
		cout << "Not deleted the student!";
	}
	else
		lst->erase(it);
	*/
}

void searchStudent(list<Student>* lst)
{
	if (lst->empty())
	{
		cout << "You cant search any student because there is no student in list!" << endl;
		return;
	}

	int _sID;
	cout << "Please write the ID of the student to be searched: ";
	cin >> _sID;

	list<Student>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++)
	{
		if (it->getSID() == _sID)
			break;
	}
	if (it == lst->end())
	{
		cout << "The specified id was not found." << endl;
	}
	else
	{
		cout << "The information you are looking for in learning." << endl;
		it->printInfo();
	}
		
}

int main() 
{
	list<Student>* pStudentList = new list<Student>();

	int userValue = 0;
	do
	{
		showManu();
		cout << "Your Choice: ";
		cin >> userValue;

		if (userValue == 1)
		{
			addStudent(pStudentList);
		}
		else if (userValue == 2)
		{
			showList(pStudentList);
		}
		else if (userValue == 3)
		{
			deleteStudent(pStudentList);
		}
		else if (userValue == 4)
		{
			searchStudent(pStudentList);
		}
		else if (userValue == 5)
		{
			cout << "You have logged out of the system" << endl;
		}
		else
		{
			cout << "Please enter one of the values in the menu" << endl;
		}

	} while (userValue != 5);

	delete pStudentList;

	return 0;
}