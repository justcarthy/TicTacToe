// TicTacToe.cpp : Defines the entry point for the console application.
//


#include "Player.h"
#include "Color.h"
#include "Board.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	string name;
	Board game;
	int playernum;
	cout << "What is your name?";
	cin >> name;
	cout << "Do you want to go first(1) or second(2)?";
	cin >> playernum; //TODO: plan for different inputs
	if (playernum == 1) {
		Player p1 = Player(Color::RED, name, false);
		Player p2 = Player(Color::WHITE, "AI", true);
	}
	else {
		Player p1 = Player(Color::RED, "AI", true);
		Player p2 = Player(Color::WHITE, name, false);
	}
	while () {
		if ();
	}








	return 0;
}


//
//TicTacToe::TicTacToe()
//{
//}
//
//
//TicTacToe::~TicTacToe()
//{
//}
