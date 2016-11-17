
#include "TicTac.h"


TicTac::TicTac() {
	setColor(-1);
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
	delete &color;

}
