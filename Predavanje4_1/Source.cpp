#include <iostream>
#include <string>

class Player
{
public:
	int x, y, velocity, hp, strenght;
	std::string userName;

	Player( int positionX, int positionY, int currentVelocity, int hitPoints) 
	{
		x = positionX;
		y = positionY;
		velocity = currentVelocity;
		hp = hitPoints;
	}

	void move() 
	{
		x += velocity;
		y += velocity;
	}

	void damage(int ammount)
	{
		hp -= ammount;
	}

};



void move(int& x,int& y, int velocity) 
{
	x += velocity;
	y += velocity;
}
int main()
{
	Player playerOne(0, 0, 10, 30);
	playerOne.userName = "Trol 1";
	playerOne.strenght = 12;

	Player playerTwo(10, 15, 10, 30);
	playerTwo.userName = "Smurf 1";
	playerTwo.strenght = 11;

	playerOne.move();
	playerTwo.move();
	
	std::string losingPlayer;
	std::string winningPlayer;

	while (playerOne.hp > 0 && playerTwo.hp > 0)
	{
		std::cout << "Choose which player you want to hit: ";
		int check;
		std::cin >> check;
		std::cout << std::endl;

		std::cin.ignore(1000, '\n');
		std::cin.clear();

		switch (check)
		{
		case 1:
			playerOne.damage(playerTwo.strenght);
			std::cout << "Player one lost 5 hitpoints " << std::endl;
			break;
		case 2:
			playerTwo.damage(playerOne.strenght);
			std::cout << "Player two lost 5 hitpoints " << std::endl;
			break;
		default:
			break;
		}
		std::cout << "Player one hitpoints: " << playerOne.hp << std::endl;
		std::cout << "Player two hitpoints: " << playerTwo.hp << std::endl;

		if (playerOne.hp <= 0)
		{
			losingPlayer = playerOne.userName;
			winningPlayer = playerTwo.userName;
		}
		else if (playerTwo.hp <= 0)
		{
			losingPlayer = playerTwo.userName;
			winningPlayer = playerOne.userName;
		}
	}
	

	std::cout << std::endl << losingPlayer << " lost the game. "<< std::endl;

	std::cout << winningPlayer << " has won the game" << std::endl;

	std::cin.get();
	system("pause");
}

// 1) napraviti treceg player, postaviti mogucnost za biranje usernamea (korisnik sam unosi username)
// 2) prosiriti mogucnost damageanja playera tako da se bira koji ce kojeg udariti.
// 3) dodati dinamicki broj igraca (nije jos obavezno)

