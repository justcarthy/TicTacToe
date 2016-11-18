
#include "Player.h"


Player::Player()
{
}

Player::Player(Color, std::string , bool ai)
{
	setColor(color);
	setName(name);
	TicTacCount = 12;
	AIflag = ai;
}

void Player::setColor(Color c)
{
	color = c;
}

void Player::setName(std::string n)
{
	name = n;
}

bool Player::movesLeft() {
	return(TicTacCount>0);
}
Player::~Player()
{
}
