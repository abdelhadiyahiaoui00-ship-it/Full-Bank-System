#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
	static bool  _Login()
	{
		bool LoginFailed = false;
		short LoginFailedcount = 0;
		string Username, Password;

		do
		{
			if (LoginFailed)
			{
				LoginFailedcount++;
				cout << "\nInvalid UserName/Password!\n\n";
				cout << "You Have " << (3 - LoginFailedcount) << " Trail(s) to login.\n\n";
			}
			if (LoginFailedcount == 3)
			{
				cout << " Your Locked After three Failed Trails" << endl;
				return false;
			}

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenue();

		return true;
	}

public:

	static bool  ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}
};

