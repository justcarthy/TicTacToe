
#include "Peg.h"


Peg::Peg()
{
	pegCounter = 0;
}

void Peg::addPiece(Color c)
{	
	pieces[pegCounter++].setColor(c);
}

bool Peg::isFull()
{
	if (pegCounter < 3) return false;
	else return true;
}

Color Peg::getColorAt(int i)
{
	return pieces[i].getColor();
}

void Peg::removePiece() 
{
	pieces[--pegCounter].setColor(Color::OTHER);
}



Peg::~Peg()
{
}
