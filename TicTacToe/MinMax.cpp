
#include "MinMax.h"


MinMax::MinMax()
{

}



vector<vector<int> > MinMax::makeMoves(Board b)
{
	Board next;
	vector<vector<int> > returnedList(8);
	vector<int>PotentialMoves = moveGen(b);
	int i;
	if (b.isEmpty()) { // If AI is p1 and makes first move
		for (i = 0; i < returnedList.size(); i++) {
			if (i == 6) returnedList[i] = { 0, 1, 0 };
			else returnedList[i] = { 0, 6, 0 };
		}
		return returnedList;
	}
	for (i = 0; i < PotentialMoves.size(); i++) {
		if (PotentialMoves[i] != -1) {
			next = b;
			next.pegs[i].addPiece(Min);
			returnedList[i] = counterMove(next, DEPTH, Max, 0, 0);
		}
	}
	return returnedList;

}

vector<int> MinMax::counterMove(Board b, int depth, Color c, int peg ,int spot)
{
	vector<int> moveList;
	vector<int> bestValue(3, -1);
	vector<int> v(3);
	Board next;
	moveList = moveGen(b);
	int i;

	if (depth == 0 || b.gameOver()){
		bestValue = { heuristic(b, c, peg, spot), peg, spot };
		return bestValue;
	}
	if (c == Max) {
		bestValue[0] =-1000;
		for (i = 0; i < moveList.size(); i++) {
			if (moveList[i] != -1) {
				next = b;
				next.pegs[i].addPiece(c);
				v = counterMove(next, depth - 1, Min, i, b.pegs[i].getCounter());
				if(v[0] > bestValue[0])
					bestValue = { v[0], i, b.pegs[i].getCounter() };
			};
		}
		return bestValue;
	}
	else if (c == Min) {
		bestValue[0] =1000;
		for (i = 0; i < moveList.size(); i++) {
			if (moveList[i] != -1) {
				next = b;
				next.pegs[i].addPiece(c);
				v = counterMove(next, depth - 1, Max, i, b.pegs[i].getCounter());
				if (v[0] < bestValue[0])
					bestValue = { v[0], i, b.pegs[i].getCounter() };
			}
		}
		return bestValue;
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
		max = Color::RED;
		min = Color::WHITE;
	}
	else {
		max = Color::WHITE;
		min = Color::RED;
	}
	heuristic = ((b.scoreBoard(max) - b.scoreBoard(min)) * 20) + postitionalValue(i, j);
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
		Min = Color::RED;
	}

}





MinMax::~MinMax()
{
}
