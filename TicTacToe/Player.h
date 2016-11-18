#pragma once
#include <string>
#include "Color.h"
class Player
{
	Color color;
	char* name;
	int TicTacCount;
public:
	Player(Color, std::string, bool);
	Color getColor() { return color; }
	void setColor(Color);
	char* getName() { return name; }
	void setName(char*);

	bool movesLeft();
	bool AIflag;

	~Player();
};

