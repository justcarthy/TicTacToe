#pragma once
#include "Color.h"

class TicTac
{
	Color color;
public:
	TicTac();
	void setColor(Color);
	Color getColor();
	~TicTac();
};

