#pragma once

#include "Board.h"
#include <vector>
#include <stdlib.h> 
using namespace std;

class MinMax
{
public:
	MinMax();
	static vector<int> moves;
	static vector<int> makeMoves(int i);
	vector<int> foo;
	~MinMax();
};

