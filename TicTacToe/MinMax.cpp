
#include "MinMax.h"


MinMax::MinMax()
{

}



vector<int> MinMax::makeMoves(int j)
{
	moves.reserve(8);
	srand(j);
	int i;
	moves;
	for (i = 0; i < moves.size(); i++) {
		moves[i] = rand();
	}
	return moves;
}



MinMax::~MinMax()
{
}
