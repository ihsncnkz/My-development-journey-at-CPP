#include <iostream>
#include "Bank.h"

using namespace std;

int main() 
{
	
	Bank account1 = Bank("Ali Kayahan", 172123, 250.75);

	account1.addMonye(200);
	try
	{
		account1.withdrawMoney(200);
	}
	catch (exception e)
	{
		cout << e.what();
	}

	account1.printInfo();
	cout << endl;
	

	Bank account2;

	account2.setAccountHolderName("Berna Ozan");
	account2.setAccountNumber(174153);

	account2.printInfo();
	cout << endl;

	try
	{
		account2.withdrawMoney(200);
	}
	catch (exception e)
	{
		cout << e.what();
	}

	
	return 0;
}