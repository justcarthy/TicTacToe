
#include "Board.h"
#include <iostream>



int Board::scoreLevels(Color c)
{
	int i;
	int score = 0;
	for (i = 0; i < 3; i++) {
		if (pegs[0].getColorAt(i) == c && pegs[1].getColorAt(i) == c && pegs[2].getColorAt(i) == c) //A-B-C
			score++;
		if (pegs[5].getColorAt(i) == c && pegs[6].getColorAt(i) == c && pegs[7].getColorAt(i) == c) //F-G-H
			score++;
		if (pegs[0].getColorAt(i) == c && pegs[3].getColorAt(i) == c && pegs[6].getColorAt(i) == c) //A-D-G
			score++;
		if (pegs[1].getColorAt(i) == c && pegs[3].getColorAt(i) == c && pegs[5].getColorAt(i) == c) //B-D-F
			score++;
		if (pegs[1].getColorAt(i) == c && pegs[4].getColorAt(i) == c && pegs[7].getColorAt(i) == c) //B-E-H
			score++;
		if (pegs[2].getColorAt(i) == c && pegs[4].getColorAt(i) == c && pegs[6].getColorAt(i) == c) //C-E-G
			score++;
	}
	return score;
}

int Board::scorePeg(Color c)
{
	int i, j;
	int score = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			if (pegs[i].getColorAt(j) != c)
				break;
			else if (j == 2) score++;
		}
	}
	return score;
}

int Board::scoreDiagonal(Color c)
{
	int score = 0;
	if (pegs[3].getColorAt(1) == c) {
		if (pegs[0].getColorAt(2) == c && pegs[6].getColorAt(0) == c) score++;
		if (pegs[0].getColorAt(0) == c && pegs[6].getColorAt(2) == c) score++;
		if (pegs[1].getColorAt(2) == c && pegs[5].getColorAt(0) == c) score++;
		if (pegs[1].getColorAt(0) == c && pegs[5].getColorAt(2) == c) score++;
	}
	if (pegs[4].getColorAt(1) == c) {
		if (pegs[1].getColorAt(2) == c && pegs[7].getColorAt(0) == c) score++;
		if (pegs[1].getColorAt(0) == c && pegs[7].getColorAt(2) == c) score++;
		if (pegs[2].getColorAt(2) == c && pegs[6].getColorAt(0) == c) score++;
		if (pegs[2].getColorAt(0) == c && pegs[6].getColorAt(2) == c) score++;
	}
	if (pegs[1].getColorAt(1) == c) {
		if (pegs[0].getColorAt(2) == c && pegs[2].getColorAt(0) == c) score++;
		if (pegs[0].getColorAt(0) == c && pegs[2].getColorAt(2) == c) score++;
	}
	if (pegs[6].getColorAt(1) == c) {
		if (pegs[5].getColorAt(2) == c && pegs[7].getColorAt(0) == c) score++;
		if (pegs[5].getColorAt(0) == c && pegs[7].getColorAt(2) == c) score++;
	}

	return score;
}

Board::Board()
{
}


int Board::scoreBoard(Color c)
{
	int score = scoreDiagonal(c) + scoreLevels(c) + scorePeg(c);
	return score;
}

bool Board::gameOver() {
	int i;
	for (i = 0; i < 8; i++) {
		if (!(pegs[i].isFull())) return false;
	}
	return true;
}


bool Board::isEmpty()
{
	int i;
	for (i = 0; i < 8; i++) {
		if (pegs[i].getCounter != 0)
			return false;
	}
	return true;
}

Board::~Board()
{
}
