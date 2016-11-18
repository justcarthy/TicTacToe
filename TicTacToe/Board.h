#pragma once
#include "Peg.h"

class Board
{
private:
	int scoreBottom(int c);
	int scoreTop(int c);
	int scorePeg(int c);
	int scoreDiagonal(int c);

public:

	Board();
	void scoreBoard(int c);
	Peg pegs[8];
	~Board();

};

