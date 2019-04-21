#include <string>
#include "Position.h"


#pragma once
class Player
{
public:
	Player(std::string playerName, Position playerPosition, int hitPoints, int strenght)
		: userName(playerName), playerPosition(playerPosition), hp(hitPoints), strenght(strenght) {}
	
	Player()
		: userName("Player"), playerPosition(0,0,0), hp(30), strenght(10){}

	~Player();

	void MovePlayer();
	void TakeDamage(int damage);
	int DealDamage();
	int GetHp() { return hp; }
	std::string GetName() { return userName; }

private:
	int hp, strenght;
	std::string userName;
	Position playerPosition;
};

