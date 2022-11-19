#include <iostream>
#include <cstdlib>
#include <queue>
#include <ctime>
using namespace std;

const string HYDRO = "H";
const string PYRO = "P";
const string CRYO = "C";

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

char randomm()
{
	srand(time(0));
	int num = (rand() % 3) + 1;
	cout << num;
	if (num == 1) 
	{
		return 'H';
	}
	else if (num == 2)
	{
		return 'P';
	}
	else
	{
		return 'C';
	}
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

char winner(string p1choice, string p2choice)
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
	else
	{
		return 'T';
	}
}

void checkcombo(queue<string> player)
{

}


void singleplayer()
{
	queue<string> p1choice, cchoice;
	string p1, com;
	int p1life, clife;
	p1life = 100;
	clife = 100;
	while(p1life != 0 || clife != 0)
	{
		controls();
		p1 = userselect();
		com = randomm();
		p1choice.push(p1);
		if (p1choice.size() > 3)
		{
			p1choice.pop();
		}
		cout << "\nSIZE:" << p1choice.size() << endl;
		cchoice.push(com);
		cout << winner(p1, com);
	}
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
