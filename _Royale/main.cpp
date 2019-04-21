#include <iostream>
#include <string>
#include "src/Player.h"
#include <vector>

void LoadPlayers(std::vector<Player>& playerList) {
	std::cout << "---Loading players---" << std::endl;
	std::cout << "---------------------" << std::endl;

	bool addAnotherPlayer = true;
	do {
		std::cout << "Your nick: ";
		std::string name;
		std::getline(std::cin, name);
		std::cout << std::endl;

		// TODO mod strenght

		Position pos(0, 0, 0);
		Player player(name, pos, 30, 12);
		playerList.push_back(player);

		std::cout << "Add another player? y/n: ";
		std::string choice;
		std::getline(std::cin, choice);

		if (choice != "y" && choice != "Y")
		{
			addAnotherPlayer = false;
		}
	} while (addAnotherPlayer);
}

bool GameOver(std::vector<Player>& playerList) {
	int numPlayersAlive = 0;
	bool gameOver = true;
	for (size_t i = 0; i < playerList.size(); i++)
	{
		if (playerList[i].GetHp() > 0)
		{
			numPlayersAlive++;
			if (numPlayersAlive > 1)
			{
				gameOver = false;
				break;
			}
		}
	}

	return gameOver;
}

Player FirstLivePlayer(std::vector<Player>& playerList) {
	Player p;
	for (size_t i = 0; i < playerList.size(); i++)
	{
		if (playerList[i].GetHp() > 0)
		{
			return playerList[i];
		}
	}
	return p;
}

int main()
{
	std::vector<Player> playerList;
	LoadPlayers(playerList);
	
	std::string losingPlayer;
	std::string winningPlayer;

	bool gameOn = true;
	while (gameOn)
	{
		
		for (size_t i = 0; i < playerList.size(); i++)
		{
			if (playerList[i].GetHp() > 0)
			{
				std::cout << "Choose which player you want to hit (number)" << std::endl;

				// TODO nothing is rly getting checked... 

				for (size_t j = 0; j < playerList.size(); j++)
				{
					if (i != j && playerList[j].GetHp() > 0)
					{
						std::cout << j+1 << ")" << playerList[j].GetName() << std::endl;
					}
				}
				// TODO can hit self, or anything rly
				int playerToHit;
				std::cin >> playerToHit;
				std::cout << std::endl;
				--playerToHit;

				std::cin.ignore(1000, '\n');
				std::cin.clear();

				if (playerToHit <= playerList.size() -1)
				{
					playerList[playerToHit].TakeDamage(playerList[i].DealDamage());
					std::cout << playerList[playerToHit].GetName() + " lost " << playerList[i].DealDamage() << " hitpoints." << std::endl;
				}
			}
		}
		std::cout<< std::endl << "---------------------" << std::endl;
		std::cout << "Player status " << std::endl;
		for (size_t i = 0; i < playerList.size(); i++)
		{
			if (playerList[i].GetHp() > 0)
			{
				std::cout << playerList[i].GetName() << " has " << playerList[i].GetHp() <<" hp." << std::endl;
			}
			else
			{
				std::cout << playerList[i].GetName() << " is dead." << std::endl;
			}
		}
		std::cout << "---------------------" << std::endl << std::endl;
				
		if (GameOver(playerList))
		{
			Player victor = FirstLivePlayer(playerList);
			std::cout << victor.GetName() << " has won the game" << std::endl;
			gameOn = false;
		}
	}
	system("pause");
}

// 1) napraviti treceg player, postaviti mogucnost za biranje usernamea (korisnik sam unosi username)
// 2) prosiriti mogucnost damageanja playera tako da se bira koji ce kojeg udariti.
// 3) dodati dinamicki broj igraca (nije jos obavezno)
