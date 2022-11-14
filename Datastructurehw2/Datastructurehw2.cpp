#include <queue>
#include <iostream>
using namespace std;

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
		while (temp != 1 && temp != 2)
		{
			cout << "\nPlease enter the proper gamemode:";
			cin >> temp;
		}
	}
	case 2:
	{
		//settings
	}
	case 3:
	{
		//EXIT
	}
	default:
		break;
	}
}
