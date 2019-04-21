#include "Player.h"

Player::~Player()
{
}

void Player::MovePlayer()
{
	playerPosition.ChangePosition();
}

void Player::TakeDamage(int damage)
{
	hp -= damage;
}

int Player::DealDamage()
{
	return strenght;
}
