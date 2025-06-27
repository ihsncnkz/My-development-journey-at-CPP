#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	bool value = true;
	map<string, string> mUserInfo;
	while (value)
	{
		int userChoose;
		
		cout << "1. Sign up" << endl;
		cout << "2. Sing in" << endl;
		cout << "3. Exit" << endl;
		cout << "choose someone: ";
		cin >> userChoose;
		cin.ignore();
		if (userChoose == 1)
		{
			string userName;
			string password;

			cout << "Please, Enter your user name: ";
			getline(cin, userName);

			cout << "Please, Enter your password: ";
			cin >> password;

			mUserInfo[userName] = password;
		}
		else if (userChoose == 2)
		{
			cout << " **** Login Information ****" << endl;
			string userName;
			string password;

			cout << "Please, Enter your user name: ";
			getline(cin, userName);

			cout << "Please, Enter your password: ";
			cin >> password;

			if (mUserInfo.find(userName) != mUserInfo.end())
			{
				if (mUserInfo[userName] == password)
				{
					cout << "Succesful Sing In" << endl;
				}
				else
				{
					cout << "Wrong Password" << endl;
				}
			}
			else
			{
				cout << "User not found" << endl;
			}
		}
		else if (userChoose == 3)
		{
			cout << "Thanks use our program. See You! :)";
			value = false;
		}
		else
		{
			cout << "You have entered incorrectly, please try again!" << endl;
		}
	}
	return 0;
}