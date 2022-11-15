#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

void controls()
{
	cout << "=============================================="
		"======================";
	cout << "\n---------------------------------\n";
	cout << "|  H- HYDRO(Best against Pyro)  |\n";
	cout << "---------------------------------\n";
	cout << "\n--------------------------------\n";
	cout << "|  P- PYRO(Best against Cryo)  |\n";
	cout << "--------------------------------\n";
	cout << "\n---------------------------------\n";
	cout << "|  C- CRYO(Best against Hydro)  |\n";
	cout << "---------------------------------\n";
	cout << "=============================================="
		"======================";
	cout << "\nPOSSIBLE COMBOS:";
	cout << "\nH + C + P = Freemelt";
	cout << "\nC + H + P = MeltFree";
	cout << "\nH + H + P = Vaporize";
	cout << "\nC + C + P = Melt";
	cout << "\nP + P + C = ReverseMelt\n";
	cout << "=============================================="
		"======================";
}


void random(queue<string> playerone)
{

}
void checkcombo(queue<string> playerone)
{

}

void singleplayer()
{
	controls();
}

void multiplayer()
{
	controls();
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
	queue<string> player;
	player.push("P");
	player.push("H");
	player.push("C");
	player.push("H");
	player.push("P");
	player.push("c");
	player.push("P");
	

	switch (selection)
	{
	case 1:
	{
		int temp;
		cout << "\nChoose a gamemode:\n";
		cout << "1.Single Player\n";
		cout << "2.Multiplayer\n";
		cin >> temp;
		while (temp < 1 || temp > 3)
		{
			cout << "\nPlease enter the proper gamemode:";
			cin >> temp;
		}
		switch (temp)
		{
		case 1:
		{
			singleplayer();
			break;
		}
		case 2:
		{
			multiplayer();
			break;
		}
		case 3:
		{
			//tournament mode
		}
		}
		break;
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
