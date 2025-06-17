#include <iostream>

using namespace std;

struct Person
{
	string name;
	int age;

	Person(const string& n, int ag) {
		name = n;
		age = ag;
	}

	void printInfo() {
		cout << "Name: " << name << " Age: " << age << endl;
	}
};

struct BankAccount {
private:
	double balance;

public:
	// Constrictor
	BankAccount(double initialBalance) {
		balance = initialBalance;
		cout << "Account created!";
	}
	
	// Destructor
	~BankAccount() {
		cout << "Account Closed!";
	}

	// Getter
	double getBalance() {
		return balance;
	}

	// Setter 
	void deposit(double amount) {
		balance += amount;
	}

	// withdrawal
	void withdraw(double amount) {
		balance -= amount;
	}
};

// c++ 11
auto add(int x, int y) -> int {
	return (x + y);
}

// c++ 14
auto subtraction(int x, int y) {
	return (x - y);
}

int main() {

	// Video 29.141
	
	Person p("Ali", 25);
	p.printInfo();

	p.age = 35;
	p.printInfo();
	

	// Video 29.142
	
	BankAccount myAccount(1000);
	cout << "Current Account: " << myAccount.getBalance() << endl;

	myAccount.deposit(500.0);
	cout << "After deposit, Current Account: " << myAccount.getBalance() << endl;

	myAccount.withdraw(300.0);
	cout << "After withdraw, Current Account: " << myAccount.getBalance() << endl;
	

	// Video 29.143
	
	BankAccount* pAccount = new BankAccount(1000);
	cout << "Current Account: " << pAccount->getBalance() << endl;

	pAccount->deposit(500.0);
	cout << "After deposit, Current Account: " << pAccount->getBalance() << endl;

	pAccount->withdraw(300.0);
	cout << "After withdraw, Current Account: " << pAccount->getBalance() << endl;

	delete pAccount;
	

	// Video 30.145
	
	auto number = 10; // Integer
	auto text = "Hello World"; // String
	auto decimal = 3.14; // Double

	cout << "Number: " << number << endl;
	cout << "Text: " << text << endl;
	cout << "Decimal: " << decimal << endl << endl;

	cout << "Add: " << add(3, 2) << endl;
	cout << "Subtraction: " << subtraction(3, 2) << endl;

	auto result = add(10, 20);
	cout << result << endl;
	

	// 31.148
	
	//auto add1 = [](int a, int b) { return a + b; }(3, 4);
	//cout << add1;
	
	
	auto add1 = [](int a, int b) { return a + b; };

	int x = 5;
	int y = 3;
	int result = add1(x, y);
	cout << "Result: " << result << endl;
	

	// [&] => captures all external changes as a reference
	// [=] => The count will be copied and will not be affected by external count changes.
	int count = 0;

	auto increase = [&]() { ++count; };
	auto copy = [=]() mutable{ 
		++count;
		cout << "Count in lambda: " << count << endl;
	};

	//increase();
	//increase();
	//increase();

	copy();
	copy();
	copy();
	copy();

	cout << "Real Count: " << count << endl;
	

	// Video 31.149
	
	auto ComplexLambda = [](bool condition) {
		if (condition) {
			return 42.0;
		}
		else {
			return 1.5;
		}
	};
	cout << ComplexLambda(true);
	
	return 0;
}