#pragma once

class Player
{
	int color;
	char* name;
public:
	Player(int, char*);
	int getColor() { return color; }
	void setColor(int i);
	char* getName() { return name; }
	void setName(char*);

	~Player();
};

