#include <iostream>
using namespace std;

class Complex {
private:
	double real, imag;

public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) {}

	Complex operator+(const Complex& other) {
		return Complex(real + other.real, imag + other.imag);
	}

	Complex operator-(const Complex& other) {
		return Complex(real - other.real, imag - other.imag);
	}

	Complex operator*(const Complex& other) {
		return Complex(((real * other.real) - (imag * other.imag)),((real * other.imag) + (imag * other.real)));
	}

	friend ostream& operator<<(ostream& os, const Complex& c) {
		os << c.real << " + " << c.imag << "i";
		return os;
	}

	void display() {
		cout << real << " + " << imag << "i" << endl;
	}
};

class Square {
private:
	double sideLenght;

public:
	
	Square(double sl = 0) : sideLenght(sl){}

	Square operator+(const Square& other) {	
		return Square(sideLenght + other.sideLenght);
	}

	friend ostream& operator<<(ostream& os, Square& s) {
		os << "Sum of the two edles: " << s.sideLenght << " ,Area of ​​square: " << (s.sideLenght *s.sideLenght);
		return os;
	}

};

int main() {

	// Video 27.131
	
	Complex c1(5, 3);
	Complex c2(2, 1);
	Complex c3 = c1 + c2;
	Complex c4 = c1 - c2;
	Complex c5 = c1 * c2;

	cout << c3 << endl; //c3.display();
	cout << c4 << endl; //c4.display();
	cout << c5 << endl; //c5.display();
	

	// Video 27.132

	Square s1(5);
	Square s2(3);

	Square s3 = s1 + s2;

	cout << s3;

	return 0;
}