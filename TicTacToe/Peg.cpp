
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

	return (pegCounter == 3);
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
