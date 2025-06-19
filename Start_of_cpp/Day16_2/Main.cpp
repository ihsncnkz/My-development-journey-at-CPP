#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() 
{

	// Video 36.174, 36.175, 36.176
	map<int, float> mStudentNotes; // If you want to rank from largest to smallest = map<int, float, greater<int>> mStudentNotes;
	// map<int, float, less> mStudentNotes; = smallest to largest

	// Add
	mStudentNotes[101] = 85.5;
	mStudentNotes[102] = 90.3;
	mStudentNotes[100] = 78.8;

	// Add with insert
	mStudentNotes.insert({ 104, 92.4 });

	// Listing
	for (const auto& student : mStudentNotes)
	{
		cout << "Student no: " << student.first << ", Average of notes: " << student.second << endl;
	}
	cout << endl;
	// Search
	int searchStudentNo = 102;
	if (mStudentNotes.find(searchStudentNo) != mStudentNotes.end())
	{
		cout << endl << "The grade point average of student number " << searchStudentNo << " " << mStudentNotes[searchStudentNo] << endl;
	}
	else
	{
		cout << "Student number " << searchStudentNo << " does not exist in the map.";
	}

	// Delete
	mStudentNotes.erase(102);
	cout << "Deleted the student number 102." << endl;

	// Listing
	for (const auto& student : mStudentNotes)
	{
		cout << "Student no: " << student.first << ", Average of notes: " << student.second << endl;
	}
	cout << endl;

	// Change values
	mStudentNotes[101] = 59.4;
	for (const auto& student : mStudentNotes)
	{
		cout << "Student no: " << student.first << ", Average of notes: " << student.second << endl;
	}
	cout << endl;



	return 0;
}