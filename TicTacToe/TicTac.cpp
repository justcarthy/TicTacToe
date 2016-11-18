
#include "TicTac.h"


TicTac::TicTac() {
	color = -1;
}

void TicTac::setColor(int c)
{
	color = c;
}

int TicTac::getColor()
{
	return color;
}

TicTac::~TicTac()
{

}
