#pragma once
class Position
{
public:
	Position(int x, int y, int velocity) 
		:x(x), y(y), velocity(velocity) {}
	Position():x(0), y(0), velocity(0){}
	~Position();

	void ChangePosition();

private:
	int x, y, velocity;
};

