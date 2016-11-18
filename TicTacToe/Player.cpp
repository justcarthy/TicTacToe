
#include "Player.h"

Player::Player(int color, std::string , bool ai)
{
	setColor(color);
	setName(name);
	TicTacCount = 12;
	AIflag = ai;
}

void Player::setColor(int i)
{
	color = i;
}

void Player::setName(char * n)
{
	name = n;
}

bool Player::movesLeft() {
	return(TicTacCount>0);
}
Player::~Player()
{
}
