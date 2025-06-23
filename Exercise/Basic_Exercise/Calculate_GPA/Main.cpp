#include <iostream>
#include <map>
#include <string>

using namespace std;

float noteCredit(float note)
{
	if (note <= 100 && note >= 70)
	{
		return 4.0f;
	}
	else if (note <= 69 && note >= 50)
	{
		return 3.0f;
	}
	else if (note <= 49 && note >= 20)
	{
		return 2.0f;
	}
	else if (note <= 19 && note > 0)
	{
		return 0.5f;
	}
	else
	{
		cout << "Please enter a value between 0 and 100.";
	}
}

int main()
{
	int lessonCount;
	float sumLessonCredit = 0.0f, sumNotePoint = 0.0f, GPA = 0.0f;

	cout << "How many lessons do you take: ";
	cin >> lessonCount;
	cin.ignore();

	for (int i = 0; i < lessonCount; i++)
	{
		int lessonNote, lessonCredit;
		string nameOfLesson;
		cout << "Name of lesson: ";
		getline(cin, nameOfLesson);

		cout << "Lesson note: ";
		cin >> lessonNote;

		cout << "Lesson credit: ";
		cin >> lessonCredit;
		cin.ignore();

		sumNotePoint = noteCredit(lessonNote) * lessonCredit;
		sumLessonCredit += lessonCredit;
	}

	GPA = sumNotePoint / sumLessonCredit;

	cout << "Sum Credits: " << sumLessonCredit << endl;
	cout << "Sum Note Point: " << sumNotePoint << endl;
	cout << "GPA (average): " << GPA << endl;
}