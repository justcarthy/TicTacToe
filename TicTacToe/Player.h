#pragma once
#include <string>
class Player
{
	int color;
	char* name;
	int TicTacCount;
public:
	Player(int, std::string, bool);
	int getColor() { return color; }
	void setColor(int i);
	char* getName() { return name; }
	void setName(char*);

	bool movesLeft();
	bool AIflag;

	~Player();
};

