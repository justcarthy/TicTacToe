#pragma once
#include "TicTac.h"
class Peg
{
private:
	int pegCounter;

public:
	
	Peg();
	TicTac pieces[3];
	void addPiece(int);
	bool isFull();
	int getColorAt(int);
	void removePiece();
	int* getCounter() { return &pegCounter; }
	~Peg();
};

