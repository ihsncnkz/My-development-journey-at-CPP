#include <iostream>

using namespace std;

class staff {
private:
	string staffType;
	double salaryCoefficient;

public:
	/*
	staff() {
		staffType = "standard";
		salaryCoefficient = 1.0;
	}
	*/

	staff(string _type = "standard", double _coefficient = 1.0) : staffType(_type), salaryCoefficient(_coefficient)
	{
		//staffType = _type;
		//salaryCoefficient = _coefficient;
		//cout << "Using of initializer list" << endl;
	}

	void printInformation() {
		cout << "Type of staff: " << staffType << "  Salary Coefficient: " << salaryCoefficient << endl;
	}

};

int main() {
	staff s1;
	staff s2("Expert", 1.5);
	s1.printInformation();
	s2.printInformation();

	return 0;
}