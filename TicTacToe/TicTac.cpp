
#include "TicTac.h"


TicTac::TicTac() {
	color = Color::OTHER;
}

void TicTac::setColor(Color c)
{
	color = c;
}

Color TicTac::getColor()
{
	return color;
}

TicTac::~TicTac()
{

}
