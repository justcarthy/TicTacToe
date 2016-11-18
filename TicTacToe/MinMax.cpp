
#include "MinMax.h"


MinMax::MinMax()
{

}



vector<int> MinMax::makeMoves(Board b)
{
	Board next;
	moves = moveGen(b);
	int i;
	for (i = 0; i < moves.size(); i++) {
		if (moves[i] > -1) {
			next = b;
			next.
		}
	}
	return moves;
}

int MinMax::counterMove(Board b, int depth, Color c, int peg ,int spot)
{
	vector<int> moveList;
	Board next;
	moveList = moveGen(b);
	int bestValue;
	int i, v, pegSpot;

	if (depth == 0) 
		return heuristic(b, c, peg, spot);
	if (c == Max) {
		bestValue = -INFINITY;
		for (i = 0; i < moveList.size(); i++) {
			if (moveList[i] > -1) {
				next = b;
				next.pegs[moveList[i]].addPiece(c);
				v = counterMove(next, depth - 1, Min, i, b.pegs[i].getCounter() - 1);
				bestValue = max(v, bestValue);
				return bestValue;
			}
		}		
	}
	else if (c == Min) {
		bestValue = INFINITY;
		for (i = 0; i < moveList.size(); i++) {
			if (moveList[i] > -1) {
				next = b;
				next.pegs[moveList[i]].addPiece(c);

				v = counterMove(next, depth - 1, Max, i, b.pegs[i].getCounter() - 1); //in case the spot was the first on the peg
				bestValue = max(v, bestValue);
				return bestValue;
			}
		}
	}
}

vector<int> MinMax::moveGen(Board b) {
	vector<int> moves(8, -1); //initialized to -1 as a check to see if a peg has moves
	int i;
	for (i = 0; i < 8; i++) {
		if (!(b.pegs[i].isFull()))
			moves[i] = 1;
	}
	return moves;
}

int postitionalValue(int i, int j) {
	vector<int> x(3);
	vector<vector<int> > values(8, x);
	values[0] = { 5, 3, 5 };
	values[1] = { 6, 6, 6 };
	values[2] = { 5, 3, 5 };
	values[3] = { 3, 7, 3 };
	values[4] = { 3, 7, 3 };
	values[5] = { 5, 3, 5 };
	values[6] = { 6, 6, 6 };
	values[7] = { 5, 3, 5 };

	return values[i][j];
}

int MinMax::heuristic(Board b, Color c, int i, int j)
{
	Color max;
	Color min;
	int heuristic;
	if (c == Color::RED) {
		max = c;
		min = Color::WHITE;
	}
	else {
		max = c;
		min = Color::WHITE;
	}
	heuristic = (b.scoreBoard(max) - b.scoreBoard(min)) * 20 + postitionalValue(i, j);
	return heuristic;
}

void MinMax::setMinMax(Color c)
{
	if (c == Color::RED) {
		Max = c;
		Min = Color::WHITE;
	}
	else {
		Max = c;
		Min = Color::WHITE;
	}

}





MinMax::~MinMax()
{
}
