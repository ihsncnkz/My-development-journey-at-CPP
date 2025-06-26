#include <iostream>
#include <string>

using namespace std;

struct Point {
	int x;
	int y;
};

struct Rectangle {
	double width;
	double height;
};

struct Student {
	int studentNo;
	string name;
	double averageOfQuiz;
};

// print status for a single student
void studentStatusPrint(Student &sdt) { // (Student &sdt) call by refrence You can change in student values with this code
	if (sdt.averageOfQuiz < 50) {
		cout << "Statu:" << " Failed in class!";
	}
	else {
		cout << "Statu:" << " Pass in class!";
	}
	cout << endl;
}

void allStudentsStatusPrint(Student stundents[], int size) {
	cout << "\n* * Student Status * *\n";
	for (int i = 0; i < size; i++) {
		cout << stundents[i].studentNo << " " <<
			stundents[i].name << " " <<
			stundents[i].averageOfQuiz << " ";
		studentStatusPrint(stundents[i]);
	}
}

struct  Student2
{
	int studentNo;
	string name;
};

void writeInformation(Student2* student) {
	cout << "Student No: " << student->studentNo << ", Name: " << student->name << endl;
}

int main() {

	// Video 17.86
	
	int x, y; // Stack memory
	int z = 10; // stack memory

	int* p = new int(5); // p is in stack memory, but int of 5 is in heap memory
	delete p; // This code deleted int of 5 from heap memory

	int w = 20; // stack memory
	p = &w; // I didnt delete p value, I deleted value of p in heap memory
	cout << *p << endl;
	//delete p; // there is a error here!
	

	// Video 18.89
	
	Point pt;
	pt.x = 10;
	pt.y = 20;

	Point pt2;
	pt2.x = 50;
	pt2.y = 70;

	cout << "pt => x: " << pt.x << " " << "y: " << pt.y << endl;
	cout << "pt2 => x: " << pt2.x << " " << "y: " << pt2.y << endl;

	Rectangle rect1;
	rect1.width = 10.2;
	rect1.height = 5.5;

	cout << "rect1 => w: " << rect1.width << " " << "h: " << rect1.height << endl;
	

	// Video 18.90
	
	Student student1;
	// First way
	student1.studentNo = 100;
	student1.name = "Ahmet Yilmaz";
	student1.averageOfQuiz = 85.5;

	// Second way
	Student student2 = {101, "Ali Kaya", 90.2};

	cout << "Student1: " << student1.studentNo << " " << student1.name << " " << student1.averageOfQuiz << endl;
	cout << "Student2: " << student2.studentNo << " " << student2.name << " " << student2.averageOfQuiz << endl;
	

	// Video 18.91
	
	Student students[3];

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ". Student No: ";
		cin >> students[i].studentNo;
		cin.ignore(); // Since we entered integer data above, we clear the line.

		cout << i + 1 << ". Student Name: ";
		getline(cin, students[i].name);

		cout << i + 1 << ". Student Quiz Average: ";
		cin >> students[i].averageOfQuiz;
	}

	for (int i = 0; i < 3; i++) {
		cout << "Student" << i << ". " << students[i].studentNo << " " << students[i].name << " " << students[i].averageOfQuiz << endl;
	}
	

	// Video 18.92
	
	Student student1 = { 101, "Ali Kaya", 58.5 };
	studentStatusPrint(student1);
	

	// Video 18.93
	
	Student students[3] = {
	{ 101, "Ali Kaya", 58.5 },
	{ 102, "Elif Demir", 32.5 },
	{ 103, "Ahmet Ak", 77.5 } };

	allStudentsStatusPrint(students, 3);
	

	// Video 18.94
	
	Student student1 = { 100, "Hakan Kaya", 62.9 };
	Student* ptr = &student1;

	cout << "Student No: " << ptr->studentNo
		<< " Student Name: " << ptr->name
		<< " Student Average of quizs: " << ptr->averageOfQuiz << endl;

	Student student2 = { 101, "Ayse Kaya", 92.9 };
	ptr = &student2;

	cout << "Student No: " << ptr->studentNo
		<< " Student Name: " << ptr->name
		<< " Student Average of quizs: " << ptr->averageOfQuiz << endl;
	

	// Video 18.95
	
	Student* ptr = new Student;

	cout << "Enter, the student no: ";
	cin >> ptr->studentNo;
	cin.ignore();

	cout << "Enter, the student name: ";
	getline(cin, ptr->name);

	cout << "Enter, the student quiz of avreage: ";
	cin >> ptr->averageOfQuiz;

	cout << "Student No: " << ptr->studentNo
		<< " Student Name: " << ptr->name
		<< " Student Average of quizs: " << ptr->averageOfQuiz << endl;

	delete ptr;
	

	// Video 18.96
	
	int n;
	cout << "How many students will be registered: ";
	cin >> n;
	cin.ignore();

	Student* students = new Student[n];

	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". Student No: ";
		cin >> students[i].studentNo;
		cin.ignore();

		cout << "Student Name: ";
		getline(cin, students[i].name);

		cout << "Student Average of quizs: ";
		cin >> students[i].averageOfQuiz;
	}

	cout << "\nStudents Information:\n";
	for (int i = 0; i < n; i++) {
		cout << students[i].studentNo << "  "
			<< students[i].name << "  "
			<< students[i].averageOfQuiz << endl;
	}

	delete[] students;
	
	
	// Video 18.99

	Student2* student1 = new Student2;
	Student2* student2 = new Student2;

	student1->studentNo = 101;
	student1->name = "Ahmet";

	// Student2* pTemp = student2; // first way for , To make the following matching correctly
	delete student2; // Second way
	student2 = student1; // Incorrect matching

	student2->studentNo = 102;
	student2->name = "Gizem";

	writeInformation(student1);
	writeInformation(student2);

	delete student1;
	//delete student2;
	//delete pTemp;
	
	return 0;
}