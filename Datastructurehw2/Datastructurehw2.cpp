#include <iostream>
#include <cstdlib>
#include <queue>
#include <ctime>
using namespace std;

const string HYDRO = "H";
const string PYRO = "P";
const string CRYO = "C";
queue<string> freezemelt, meltfreeze, vaporize, melt, reversemelt;


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
	cout << "\nH + C + P = Freezemelt";
	cout << "\nC + H + P = MeltFreeze";
	cout << "\nH + H + P = Vaporize";
	cout << "\nC + C + P = Melt";
	cout << "\nP + P + C = ReverseMelt\n";
	cout << "=============================================="
		"======================";
}

void outputqueue(queue<string> choice)
{
	queue<string> temp;
	temp = choice;
	while(!temp.empty())
	{
		cout << temp.front();
		temp.pop();
	}
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

bool winner(string p1choice, string p2choice)
{
	if(p1choice == HYDRO && p2choice == PYRO)
	{
		return 1;
	}
	else if(p1choice == HYDRO && p2choice == CRYO)
	{
		return 2;
	}
	else if(p1choice == PYRO && p2choice == HYDRO)
	{
		return 2;
	}
	else if(p1choice == PYRO && p2choice == CRYO)
	{
		return 1;
	}
	else if(p1choice == CRYO && p2choice == HYDRO)
	{
		return 1;
	}
	else if(p1choice == CRYO && p2choice == PYRO)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

bool checkcombo(queue<string> player)
{
	if(player == freezemelt)
	{
		cout << "\n----------------------------------------\n";
		cout << "|  COMBO!!!!! You did Freezemelt combo  |\n";
		cout << "-----------------------------------------\n";
		return true;
	}
	else if(player == meltfreeze)
	{
		cout << "\n----------------------------------------\n";
		cout << "|  COMBO!!!!! You did Meltfreeze combo  |\n";
		cout << "-----------------------------------------\n";
		return true;
	}
	else if(player == vaporize)
	{
		cout << "\n----------------------------------------\n";
		cout << "|  COMBO!!!!! You did Vaporize combo  |\n";
		cout << "---------------------------------------\n";
		return true;
	}
	else if(player == melt)
	{
		cout << "\n-----------------------------------\n";
		cout << "|  COMBO!!!!! You did Melt combo  |\n";
		cout << "-----------------------------------\n";
		return true;
	}
	else if(player == reversemelt)
	{
		cout << "\n------------------------------------------\n";
		cout << "|  COMBO!!!!! You did Reversemelt combo  |\n";
		cout << "-----------------------------------------\n";
		return true;
	}
	else
	{
		cout << "\n-----------------------\n";
		cout << "|  No combo for you.  |\n";
		cout << "-----------------------\n";
		return false;
	}
}
 
void output(int h1, int h2, queue<string> p1, queue<string> p2)
{
	cout << "______________________________________________________________________________________________________\n";
	cout << "|                                                                                                     |\n";
	cout << "|        ____                                                                       ____              |\n";
	cout << "|       |    |                                                                     |    |             |\n";
	cout << "|      / _  _ \\                                                       / \\         / -  - \\            |\n";
	cout << "|     |  o  O  |        _                                             | |        |  w   w |           |\n";
	cout << "|      \\  W   /        /_\\                                            | |         \\  \\/  /            |\n";
	cout << "|       \\____/         | |                                            | |          \\____/             |\n";
	cout << "|    ____|  |______    | |                                            | |     ______|  |____          |\n";
	cout << "|   \\ \\            \\   | |                                            | |    /            / /         |\n";
	cout << "|   |\\ \\         |\\ \\  |_|                                            / \\   / /|         / /|         |\n";
	cout << "|   | \\ \\        | \\ \\|   |                                          /[ ]\\ / / |        / / |         |\n";
	cout << "|   |  \\ \\_______|__\\/|   |                                           [ ]  \\/__|_______/ /  |         |\n";
	cout << "|   |   \\___________| |___|                                           [_]  |____________/   |         |\n";
	cout << "|                                                                                                     |\n";
	cout << "|                                                                                                     |\n";
	cout << "|      HEALTH: " << h1 << "                                                             HEALTH: " << h2 << "             |\n";
	cout << "|      CHOICES: "; outputqueue(p1); cout << "                                                           CHOICES: "; outputqueue(p2); cout << "            |\n";
}

void singleplayer()
{
	queue<string> p1choice, cchoice;
	string p1, com;
	int p1life, clife, win;
	p1life = 100; clife = 100;

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
		cchoice.push(com);
		if (cchoice.size() > 3)
		{
			cchoice.pop();
		}
		win = winner(p1, com);
		if(win == 1)
		{
			clife = clife - 5;
		}
		else if(win == 2)
		{
			clife = clife - 5;
		}
		else
		{
			p1life = p1life - 3;
			clife = clife - 3;
		}
		output(p1life, clife, p1choice, cchoice);
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
	freezemelt.push("H"); freezemelt.push("C"); freezemelt.push("P");
	meltfreeze.push("C"); meltfreeze.push("H"); meltfreeze.push("P");
	vaporize.push("H"); vaporize.push("H"); vaporize.push("P");
	melt.push("C"); melt.push("C"); melt.push("P");
	reversemelt.push("P"); reversemelt.push("P"); reversemelt.push("C");
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
