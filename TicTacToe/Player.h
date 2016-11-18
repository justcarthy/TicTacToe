#pragma once
#include <string>
#include "Color.h"
class Player
{
	Color color;
	std::string name;
	int TicTacCount;
public:
	Player();
	Player(Color, std::string, bool);
	Color getColor() { return color; }
	void setColor(Color);
	std::string getName() { return name; }
	void setName(std::string);

	bool movesLeft();
	bool AIflag;

	~Player();
};

