#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

const char HYDRO = 'H';
const char PYRO = 'P';
const char CRYO = 'C';

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

char random()
{
	srand(time(0));
	int num = rand() % 2 + 1;

	if (num == 0) return 'H';
	if (num == 1) return 'P';
	if (num == 2) return 'C';
}

char userselect()
{
	char select;
	cout << "\nPlease choose your attack element!";
	cin >> select;

	while(select != 'H' && select != 'P' && select != 'C')
	{
		cout << "\nPlease enter a valid element!!";
		cout << "\n 'H' for hydro, 'P' for pyro, and 'C' for cryo";
		cin >> select;
	}
	return select;
}

char winner(char p1choice, char p2choice)
{
	if(p1choice == HYDRO && p2choice == PYRO)
	{
		return '1';
	}
	else if(p1choice == HYDRO && p2choice == CRYO)
	{
		return '2';
	}
	else if(p1choice == PYRO && p2choice == HYDRO)
	{
		return '2';
	}
	else if(p1choice == PYRO && p2choice == CRYO)
	{
		return '1';
	}
	else if(p1choice == CRYO && p2choice == HYDRO)
	{
		return '1';
	}
	else if(p1choice == CRYO && p2choice == PYRO)
	{
		return '2';
	}
	else if(p1choice == p2choice)
	{
		return 'T';
	}
}

void queuecount(queue<string> scount)
{
	int count;
	while(scount.empty() != true)
	{
		scount.pop();
		count++;
	}
	return count;
}

void checkcombo(queue<string> player)
{

}

void singleplayer()
{
	queue<string> p1choice, comchoice;
	char p1, com;
	controls();
	p1 = userselect();
	com = random();

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
