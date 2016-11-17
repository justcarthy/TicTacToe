#pragma once
#include "TicTac.h"
class Peg
{
	int pegCounter;

public:
	
	Peg();
	TicTac* pieces;
	void addPiece(int);
	bool isFull();
	int getColorAt(int);
	void removePiece();
	int* getCounter() { return &pegCounter; }
	~Peg();
};

