#include "Student.h"
#include <iostream>

using namespace std;

class Calculator {
public:
	void averageCalculator(Student student) {
		int average = (student.quiz1 + student.quiz2) / 2;
		cout << student.name << "'s GPA:" << average << endl;
	}
};


int main() {

	Student student1("Jo", 89, 99);
	Student student2("Tom", 45, 100);
	Calculator calculator;
	calculator.averageCalculator(student1);
	calculator.averageCalculator(student2);

	return 0;
}
