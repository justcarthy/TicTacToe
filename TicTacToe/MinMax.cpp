//MinMax.cpp
// Author: Justin McCarthy
// SIN: 5048673
// COSC 4F00

#include "MinMax.h"
/////////////////////////////////////////////////////////////////
// This class contains the MiniMax AI, appropriately called MinMax.
// Because the AI is supposed to be "thinking" while the opponent makes
// their move the AI is set to create it's set of counter moves to 
// the player while the board is displayed.
//
// How this class works is that it is given a board state.
// analyzes the board state, and creates a vector array of where the adversary
// can move. For each move available, the board state is given to the minimax
// which returns the optimal move from a depth of 4
// Returned to the game is a 2d vector array containing all counter moves
// to each human move available.
/////////////////////////////////////////////////////////////////

MinMax::MinMax()
{

}


/////////////////////////////////////////////////////////////////
// The called method from the main game class, iterates through 
// available moves and creates appropriate counter move
/////////////////////////////////////////////////////////////////
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
			//initialized with 0,0 since it will be changed anyway, similar to inf
		}
	}
	return returnedList;

}
/////////////////////////////////////////////////////////////////
//The minimax algorithm
/////////////////////////////////////////////////////////////////
vector<int> MinMax::counterMove(Board b, int depth, Color c, int peg ,int spot)
{
	vector<int> moveList; //stores all possible moves
	vector<int> bestValue(3, -1); //vector array
	// used vector array instead of int, because it made generating a heuristic value easier
	// since the heuristic takes into account the positional values of the board as well
	vector<int> v(3);
	// v is the bestValue comparator
	Board next; //new board state for manipulation of b
	moveList = moveGen(b);
	int i;

	if (depth == 0 || b.gameOver()){ // Base case
		bestValue = { heuristic(b, c, peg, spot), peg, spot };
		return bestValue;
	}
	if (c == Max) { //Calculating best move for the Max player AI
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
	else if (c == Min) { //Calculating best move for the Min player human
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

//////////////////////////////////////////////////////////////////
// Simple vector array returning the playability of pegs on 
// Board b
//////////////////////////////////////////////////////////////////

vector<int> MinMax::moveGen(Board b) {
	vector<int> moves(8, -1); //initialized to -1 as a check to see if a peg has moves
	int i;
	for (i = 0; i < 8; i++) {
		if (!(b.pegs[i].isFull()))
			moves[i] = 1;
	}
	return moves;
}

//////////////////////////////////////////////////////////////////
// Positional values of board locations
// Based on how many points are attainable from that board position
//////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////
// Calculates the heuristic value of a state
// The max players score minus min players, adding positional value
//////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////
// When game is started the main class specfies which player color
// is min and max, using this method
//////////////////////////////////////////////////////////////////
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
