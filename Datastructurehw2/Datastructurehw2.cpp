#include <iostream>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <vector>
#include <algorithm>
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
	while (!temp.empty())
	{
		cout << temp.front();
		temp.pop();
	}
}

char randomm()
{
	srand(time(0));
	int num = (rand() % 3) + 1;
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

	while (select != 'H' && select != 'P' && select != 'C' && select != 'Q')
	{
		cout << "\nPlease enter a valid element!!";
		cout << "\n 'H' for hydro, 'P' for pyro, and 'C' for cryo OR Q to Quit";
		cin >> select;
	}
	return select;
}

string winner(string p1choice, string p2choice)
{
	if (p1choice == HYDRO && p2choice == PYRO)
	{
		return "Player 1";
	}
	else if (p1choice == HYDRO && p2choice == CRYO)
	{
		return "Player 2";
	}
	else if (p1choice == PYRO && p2choice == HYDRO)
	{
		return "Player 2";
	}
	else if (p1choice == PYRO && p2choice == CRYO)
	{
		return "Player 1";
	}
	else if (p1choice == CRYO && p2choice == HYDRO)
	{
		return "Player 1";
	}
	else if (p1choice == CRYO && p2choice == PYRO)
	{
		return "Player 2";
	}
	else
	{
		return "Tie";
	}
}

bool checkcombo(queue<string> player)
{
	if (player == freezemelt)
	{
		cout << "\n----------------------------------------\n";
		cout << "|  COMBO!!!!! You did Freezemelt combo  |\n";
		cout << "-----------------------------------------\n";
		return true;
	}
	else if (player == meltfreeze)
	{
		cout << "\n----------------------------------------\n";
		cout << "|  COMBO!!!!! You did Meltfreeze combo  |\n";
		cout << "-----------------------------------------\n";
		return true;
	}
	else if (player == vaporize)
	{
		cout << "\n----------------------------------------\n";
		cout << "|  COMBO!!!!! You did Vaporize combo  |\n";
		cout << "---------------------------------------\n";
		return true;
	}
	else if (player == melt)
	{
		cout << "\n-----------------------------------\n";
		cout << "|  COMBO!!!!! You did Melt combo  |\n";
		cout << "-----------------------------------\n";
		return true;
	}
	else if (player == reversemelt)
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

void output(int h1, int h2, queue<string> p1, queue<string> p2, string win, string dmg)
{
	cout << "\n______________________________________________________________________________________________________\n";
	cout << "|                                     " << win << " SUCCESSFULL!!                                         | \n";
	cout << "|        ____                         WITH A DAMAGE OF " << dmg << "                            ____              | \n";
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
	cout << "|      CHOICES: "; outputqueue(p1); cout << "                                                             CHOICES: "; outputqueue(p2); cout << "          |\n";
	cout << "|                                                                                                     |\n";
	cout << "|_____________________________________________________________________________________________________|\n";
}

void singleplayer(int comb)
{
	queue<string> p1choice, cchoice;
	string p1, com, win;
	int p1life, clife;
	p1life = 100; clife = 100;

	while (p1life > 0 && clife > 0)
	{
		controls();
		p1 = userselect();
		com = randomm();
		if (p1 == "Q")
		{
			break;
		}
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
		if (win == "Player 1")
		{
			clife = clife - 5;
			output(p1life, clife, p1choice, cchoice, win, "5");
		}
		else if (win == "Player 2")
		{
			p1life = p1life - 5;
			output(p1life, clife, p1choice, cchoice, win, "5");
		}
		else
		{
			p1life = p1life - 3;
			clife = clife - 3;
			output(p1life, clife, p1choice, cchoice, win, "3 To BOTH SIDES!!");
		}

		if (checkcombo(p1choice) == true)
		{
			clife = clife - 10;
			output(p1life, clife, p1choice, cchoice, "COMBOOOOO FROM PLAYER 1", "10");
		}
		if (comb == 1 && checkcombo(cchoice) == true)
		{
			p1life = p1life - 10;
			output(p1life, clife, p1choice, cchoice, "COMBO FROM COMPUTER", "10");
		}
	}
}

bool multiplayer()
{
	queue<string> p1choice, p2choice;
	string p1, p2, win;
	int p1life, p2life;
	p1life = 100; p2life = 100;

	while (p1life > 0 && p2life > 0)
	{
		controls();
		p1 = userselect();
		p2 = userselect();
		if (p1 == "Q" || p2 == "Q")
		{
			break;
		}
		p1choice.push(p1);
		if (p1choice.size() > 3)
		{
			p1choice.pop();
		}
		p2choice.push(p2);
		if (p2choice.size() > 3)
		{
			p2choice.pop();
		}
		win = winner(p1, p2);
		if (win == "Player 1")
		{
			p2life = p2life - 5;
		}
		else if (win == "Player 2")
		{
			p1life = p1life - 5;
		}
		else
		{
			p1life = p1life - 3;
			p2life = p2life - 3;
		}
		output(p1life, p2life, p1choice, p2choice, win, "5");
		if (checkcombo(p1choice) == true)
		{
			p2life = p2life - 10;
			output(p1life, p2life, p1choice, p2choice, "COMBOOOOO FROM PLAYER 1", "10");
		}
		if (checkcombo(p2choice) == true)
		{
			p1life = p1life - 10;
			output(p1life, p2life, p1choice, p2choice, "COMBOOOOO FROM PLAYER 2", "10");
		}
	}
	if (p1life == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void newround()
{
	cout << R"(           _ _     _   _______   _                _            
	  |   \   | | |   ____| | \      __      / |           
	  | |\ \  | | |  |____   \ \    /  \    / /            
	  | | \ \ | | |   ____|   \ \  / /\ \  / /             
	  | |  \ \/ | |  |____     \ \/ /  \ \/ /              
	  |_|   \__/  |_______|     \__/    \__/               
	   ____    _______   _       _   _ _     _   _____     
	  |  _ \  |  ___  | | |     | | |   \   | | | ___ \    
	  | |_|/  | |   | | | |     | | | |\ \  | | ||   | |   
	  |    \  | |   | | | |     | | | | \ \ | | ||   | |   
	  | |\  \ | |___| | | |_____| | | |  \ \/ | ||___| |   
	  \_| \_| |_______| |_________| |_|   \__/  |_____/    )" << endl;
}

void gamename()
{
	cout << R"(   _     _   _       _   ______     ______     ________   
  | |   | | \ \     / / |  ___ \   |  __  \   |  ____  |   
  | |___| |  \ \   / /  | |   | |  | |__| /   | |    | |          
  |  ___  |   \_\ /_/   | |   | |  |  __ /    | |    | |  
  | |   | |     | |     | |   | |  | |  \ \   | |    | |  
  | |   | |     | |     | |___| |  | |   \ \  | |____| |  
  |_|   |_|     |_|     |______/   \_|    \_\ |________|  
   _______  _         _  ______     ________              
  |  ___  | \ \     / / |  __  \   |  ____  |    
  | |___| |  \ \   / /  | |__| /   | |    | |   
  |  _____|   \_\ /_/   |  __ /    | |    | |  
  | |           | |     | |  \ \   | |    | |  
  | |           | |     | |   \ \  | |____| |  
  |_|           |_|     \_|    \_\ |________|  
    ______   ______    _         _  ________   
   /  ____| |  __  \   \ \     / / |  ____  |  
  /  /      | |__| /    \ \   / /  | |    | |  
  |  |      |  __ /      \_\ /_/   | |    | |  
  |  |      | |  \ \       | |     | |    | |  
  \  \____  | |   \ \      | |     | |____| |  
   \______| \_|    \_\     |_|     |________| )" << endl;
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
	int selection, comb;
	comb = 0;
	gamename();

	do
	{
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
			cout << "3.Tournament mode\n";
			cin >> temp;
			while (temp < 1 && temp < 4)
			{
				cout << "\nPlease enter the proper gamemode:";
				cin >> temp;
			}
			switch (temp)
			{
			case 1:
			{
				singleplayer(comb);
				break;
			}
			case 2:
			{
				multiplayer();
				break;
			}
			case 3:
			{
				int num;
				vector<string> players;
				string temp;
				cout << "\nEnter the number of players competing:";
				cin >> num;

				for (int i = 0; i < num; i++)
				{
					cout << "\n COMPETITOR " << i + 1 << ":";
					cin >> temp;
					players.push_back(temp);
				}
				while (num > 1)
				{
					newround();
					string& tempp = players[1];
					cout << "\n\n\n\n\n\n\nPlayer 1:" << players.front() << "   Player 2:" << tempp << endl;
					if (multiplayer() == true)
					{
						players.erase(players.begin());
						rotate(players.begin(), players.end() - 1, players.end());
						num--;
					}
					else
					{
						rotate(players.begin(), players.end() - 1, players.end());
						players.erase(players.begin());
						num--;
					}

				}
				if (num == 1)
				{
					cout << "\nWinner is:" << players.front();
				}
				break;
			}
			}
			break;
		}
		case 2:
		{
			cout << "SETTINGS:\n";
			cout << "1. Type '1' to activate combos for computer\n";
			cout << "2. Type '0' to deactivate the combos for the computer\n";
			cout << "Your choice:";
			cin >> comb;
			break;
		}
		case 3:
		{
			exit(0);
		}
		default:
			break;
		}
	} while (true);

}