#pragma once
#include "Peg.h"
#include "Color.h"

class Board
{
private:
	int scoreLevels(Color c);
	int scorePeg(Color c);
	int scoreDiagonal(Color c);

public:

	Board();
	int scoreBoard(Color c);
	bool gameOver();
	Peg pegs[8];
	~Board();

};

