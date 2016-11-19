#pragma once

#include "Board.h"
#include "Color.h"
#include <vector>
#include <stdlib.h> 
#include <math.h>
#include <algorithm> 
using namespace std;
#define DEPTH 4 
class MinMax
{
public:
	MinMax();
	vector<vector<int> > makeMoves(Board);
	vector<int> counterMove(Board, int, Color, int, int);
	vector<int> moveGen(Board b);
	int heuristic(Board b, Color c, int i, int j);
	void setMinMax(Color c);
	Color Min;
	Color Max;
	~MinMax();
};

