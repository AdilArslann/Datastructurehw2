#include <queue>
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

void random(string playerone)
{

}

void singleplayer()
{

}

void multiplayer()
{
}

void Menu()
{
	cout << "=============================================="
		"======================";
	cout << "\nMenu:\n";
	cout << "1.Start the game\n";
	cout << "2.Settings\n";
	cout << "3.Exit\n";
	cout << "=============================================="
		"======================";
	cout << "\nYour choice:";
}
int main()
{
	int selection;
	Menu();
	cin >> selection;
	switch (selection)
	{
	case 1:
	{
		int temp;
		cout << "\nChoose a gamemode:\n";
		cout << "1.Single Player\n";
		cout << "2.Multiplayer\n";
		cin >> temp;
		while (temp <= 1 || temp >= 3)
		{
			cout << "\nPlease enter the proper gamemode:";
			cin >> temp;
		}
		switch (temp)
		{
		case 1:
		{
			singleplayer();
		}
		case 2:
		{
			multiplayer();
		}
		case 3:
		{
			//tournament mode
		}
		default:
			break;
		}
	}
	case 2:
	{
		//settings
	}
	case 3:
	{
		exit(0);
	}
	default:
		break;
	}
}
