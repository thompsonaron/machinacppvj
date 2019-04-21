#include "Position.h"

Position::~Position()
{
}

void Position::ChangePosition()
{
	x += velocity;
	y += velocity;
}