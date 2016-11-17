
#include "Player.h"

Player::Player(int color, char * name)
{
	setColor(color);
	setName(name);
}

void Player::setColor(int i)
{
	color = i;
}


void Player::setName(char * n)
{
	name = n;
}

Player::~Player()
{
	delete &color;
	delete &name;
}
