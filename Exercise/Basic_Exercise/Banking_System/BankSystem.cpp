#include "BankSystem.h"
#include "Account.h"
#include "Transaction.h"

void BankSystem::menu() 
{
	while (true)
	{
		cout << "\n=== BANK MENU ===\n";
		cout << "1. Add Customer\n";
		cout << "2. Open Account\n";
		cout << "3. Deposit\n";
		cout << "4. Withdraw\n";
		cout << "5. Transfer\n";
		cout << "6. Print Account Info\n";
		cout << "7. Exit\n";
		cout << "Choice: ";
		int ch;
		cin >> ch;

		switch (ch) {
		case 1: addCustomer(); break;
		case 2: openAccount(); break;
		case 3: deposit(); break;
		case 4: withdraw(); break;
		case 5: transfer(); break;
		case 6: printAccountInfo(); break;
		case 7: cout << "Bye!\n"; return;
		default: cout << "Invalid choice!\n";
		}
	}
}

void BankSystem::addCustomer()
{
	string name;
	cout << "Enter customer name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	customers.emplace_back(nextCustomerID++, name);
	cout << "Customer created. ID: " << nextCustomerID - 1 << endl;
}

Customer* BankSystem::findCustomer(vector<Customer>& customers, int id)
{
	for (auto& c : customers)
	{
		if (c.getCustomID() == id) return &c;
	}
	return nullptr;
}

void BankSystem::openAccount() 
{
	int id;
	cout << "Enter customer ID: ";
	cin >> id;

	Customer* c = findCustomer(customers, id);
	if (c)
	{
		c->getAccount().emplace_back(nextAccountNum++);
		cout << "Account opened! Account Number: " << nextAccountNum - 1 << endl;
	}
	else
	{
		cout << "Customer not found!\n";
	}
}

void BankSystem::deposit() 
{
	int id, accNum;
	double amount;
	string date;
	cout << "Customer ID: "; cin >> id;
	cout << "Account Number: "; cin >> accNum;
	cout << "Amount: "; cin >> amount;
	cout << "Date: "; cin >> date;

	Customer* c = findCustomer(customers, id);
	if (c)
	{
		Account* a = c->findAccount(accNum);
		if (a)
		{
			a->deposit(amount, date);
			cout << "Deposit succesful. New balance: " << a->getBalance() << endl;
		}
		else
		{
			cout << "Account not found!\n";
		}
	}
	else
	{
		cout << "Customer not found!\n";
	}
}

void BankSystem::withdraw() 
{
	int id, accNum;
	double amount;
	string date;
	cout << "Custimer ID: "; cin >> id;
	cout << "Accunt Number: "; cin >> accNum;
	cout << "Amount: "; cin >> amount;
	cout << "Date: "; cin >> date;

	Customer* c = findCustomer(customers, id);
	if (c)
	{
		Account* a = c->findAccount(accNum);
		if (a && a->withdraw(amount, date))
		{
			cout << "Withdraw succesful. New balance: " << a->getBalance() << endl;
		}
		else
		{
			cout << "Insufficient balance or account not found!\n";
		}
	}
	else
	{
		cout << "Customer not found!\n";
	}
}

void BankSystem::transfer() 
{
	int fromId, fromAcc, toId, toAcc;
	double amount;
	string date;
	cout << "Sender Customer ID: "; cin >> fromId;
	cout << "Sender Account Number: "; cin >> fromAcc;
	cout << "Receiver Customer ID: "; cin >> toId;
	cout << "Receiver Account Number: "; cin >> toAcc;
	cout << "Amount: "; cin >> amount;
	cout << "Date: "; cin >> date;

	Customer* sender = findCustomer(customers, fromId);
	Customer* receiver = findCustomer(customers, toId);
	if (sender && receiver)
	{
		Account* accFrom = sender->findAccount(fromAcc);
		Account* accTo = receiver->findAccount(toAcc);
		if (accFrom && accTo && accFrom->withdraw(amount, date))
		{
			accTo->deposit(amount, date);
			accFrom->addTransaction("Transfer Sent", amount, date);
			accTo->addTransaction("Transfer Received", amount, date);
			cout << "Transfer succesful. \n";
		}
		else
		{
			cout << "Transfer failed. Check account numbers and balance.\n";
		}
	}
	else
	{
		cout << "Customer(s) not found!\n";
	}
}

void BankSystem::printAccountInfo() 
{
	int id, accNum;
	cout << "Customer ID: "; cin >> id;
	cout << "Account Number: "; cin >> accNum;
	Customer* c = findCustomer(customers, id);
	if (c)
	{
		Account* a = c->findAccount(accNum);
		if (a)
		{
			a->printInfo();
			a->printTransaction();
		}
		else
		{
			cout << "Account not found!\n";
		}
	}
	else
	{
		cout << "Customer not found!\n";
	}
}