
#include "Peg.h"


Peg::Peg()
{
	TicTac pieces[3];
}

void Peg::addPiece(int c)
{	
	pieces[pegCounter++].setColor(c);
}

bool Peg::isFull()
{
	return (pegCounter==3);
}

int Peg::getColorAt(int i)
{
	return pieces[i].getColor();
}

void Peg::removePiece() 
{
	pieces[--pegCounter].setColor(-1);
}



Peg::~Peg()
{
	int i;
	for (i = 0; i < 3; i++) {
		delete &pieces[i];
	}
	delete &i;
}
