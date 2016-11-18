// TicTacToe.cpp : Defines the entry point for the console application.
//


#include "Player.h"
#include "Color.h"
#include "Board.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <regex>
using namespace std;


char GetPiece(int i, int j, Board b) {
	char tower = 179;
	char red = 177;
	char white = 178;
	if (b.pegs[i].getColorAt(j) == Color::RED) return red;
	if (b.pegs[i].getColorAt(j) == Color::WHITE) return white;
	else return tower;
}

void DisplayBoard(Board b) {
	char base = 193;
	cout << "\tA\tB\tC  \n";
	cout << "\t" << GetPiece(0, 2, b) << "\t" << GetPiece(1, 2, b) << "\t" << GetPiece(2, 2, b) << "  \n";
	cout << "\t" << GetPiece(0, 1, b) << "   D   " << GetPiece(1, 1, b) << "   E   " << GetPiece(2, 1, b) << "  \n";
	cout << "\t" << GetPiece(0, 0, b) << "   " << GetPiece(3, 2, b) << "   " << GetPiece(1, 0, b) << "   " << GetPiece(4, 2, b) << "   " << GetPiece(2, 0, b) << "  "
		<< "P1:RED: " << b.scoreBoard(Color::RED)<< "\n";
	cout << "\t" << base << "   " << GetPiece(3, 1, b) << "   " << base << "   " << GetPiece(4, 1, b) << "   " << base << "  "
		<< "P2:WHITE: " << b.scoreBoard(Color::WHITE)<<"\n";
	cout << "\t" << "F" << "   " << GetPiece(3, 0, b) << "   " << "G" << "   " << GetPiece(4, 0, b) << "   " << "H" << "  \n";
	cout << "\t" << GetPiece(5, 2, b) << "   " << base << "   " << GetPiece(6, 2, b) << "   " << base << "   " << GetPiece(7, 2, b) << "  \n";
	cout << "\t" << GetPiece(5, 1, b) << "\t" << GetPiece(6, 1, b) << "\t" << GetPiece(7, 1, b) << "  \n";
	cout << "\t" << GetPiece(5, 0, b) << "\t" << GetPiece(6, 0, b) << "\t" << GetPiece(7, 0, b) << "  \n";
	cout << "\t" << base << "\t" << base << "\t" << base << "  \n\n";

}

int askPlayer() {
	regex regl("[a-hA-H]");
	string s;
	cout << "please make your move A-H\n";
	while (true) {
		cin >> s;
		if (s.length() < 2 && (regex_search(s, regl))) break;
		else cout << "\n incorrect input...";
	}
	int m = (s.at(0) + 7) % 8;
	return m;
}

//int main() {
//	string name;
//	Board game;
//	Board other;
//	int playernum, move;
//	Player p1;
//	Player p2;
//	regex regl("[a-zA-Z]");
//	cout << "What is your name?\n";
//	cin >> name;
//	cout << "Do you want to go first(1) or second(2)?\n";
//	cin >> playernum; //TODO: plan for different inputs
//	
//	if (playernum == 1) {
//		p1.setColor(Color::RED);
//		p1.setName(name);
//		p1.AIflag = false;
//		
//		p2.setColor(Color::WHITE);
//		p1.setName("AI");
//		p1.AIflag = true;
//	}
//	else {
//		p1.setColor(Color::RED);
//		p1.setName("AI");
//		p1.AIflag = true;
//
//		p2.setColor(Color::WHITE);
//		p1.setName(name);
//		p1.AIflag = false;
//	}
//	while (true) {
//		int i;
//		DisplayBoard(game);
//		move = askPlayer();
//		game.pegs[move].addPiece(p1.getColor());
//		DisplayBoard(game);
//		move = askPlayer();
//		game.pegs[move].addPiece(p2.getColor());
//
//
//	}

//	return 0;
//}

