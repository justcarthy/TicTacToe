// TicTacToe.cpp 
// Author: Justin McCarthy
// SIN: 5048673
// COSC 4F00

/////////////////////////////////////////////////////////////////////////
// This console program is a digitized version of 3d Tic-Tac-Toe.
// The player inputs their name, and whether they want to go first or second.
// The other player is automatically designated as an AI named Dolores, which makes decisions
// based on a minimax tree depth of 4. Input during the game is based on the players choice of 
// peg on the board (A-H). At the end of the game the player is given the coice of playing again
////////////////////////////////////////////////////////////////////////


#include "Player.h"
#include "Color.h"
#include "Board.h"
#include "MinMax.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <regex>
using namespace std;

/////////////////////////////////////////////////////////////////////////
// param int i, is a peg location on the board
// param int j, a location of 1-3 pieces on the peg
// param Board b, the current playing board
// This method is used by the displayBoard to get the propor ascii char for
// players and empty board pieces.
/////////////////////////////////////////////////////////////////////////
char GetPiece(int i, int j, Board b) {
	char tower = 179;
	char red = 177;
	char white = 178;
	if (b.pegs[i].getColorAt(j) == Color::RED) return red;
	if (b.pegs[i].getColorAt(j) == Color::WHITE) return white;
	else return tower;
}

/////////////////////////////////////////////////////////////////////////
// param Board b, is the current board state of the game to be printed
// param Player p1, details of player 1, such as color
// param p2, details of player 2, such as color
// This class provides the console UI for the game. As well as both player's score
// char base is the base of the pegs displayed.
/////////////////////////////////////////////////////////////////////////
void DisplayBoard(Board b, Player p1, Player p2) {
	char base = 193;
	cout << "\tA\tB\tC  \n";
	cout << "\t" << GetPiece(0, 2, b) << "\t" << GetPiece(1, 2, b) << "\t" << GetPiece(2, 2, b) << "  \n";
	cout << "\t" << GetPiece(0, 1, b) << "   D   " << GetPiece(1, 1, b) << "   E   " << GetPiece(2, 1, b) << "  \n";
	cout << "\t" << GetPiece(0, 0, b) << "   " << GetPiece(3, 2, b) << "   " << GetPiece(1, 0, b) << "   " << GetPiece(4, 2, b) << "   " << GetPiece(2, 0, b) << "  "
		<< "P1:RED: " <<p1.getName()<<" "<< b.scoreBoard(Color::RED)<< "\n";
	cout << "\t" << base << "   " << GetPiece(3, 1, b) << "   " << base << "   " << GetPiece(4, 1, b) << "   " << base << "  "
		<< "P2:WHITE: " << p2.getName() << " " << b.scoreBoard(Color::WHITE)<<"\n";
	cout << "\t" << "F" << "   " << GetPiece(3, 0, b) << "   " << "G" << "   " << GetPiece(4, 0, b) << "   " << "H" << "  \n";
	cout << "\t" << GetPiece(5, 2, b) << "   " << base << "   " << GetPiece(6, 2, b) << "   " << base << "   " << GetPiece(7, 2, b) << "  \n";
	cout << "\t" << GetPiece(5, 1, b) << "\t" << GetPiece(6, 1, b) << "\t" << GetPiece(7, 1, b) << "  \n";
	cout << "\t" << GetPiece(5, 0, b) << "\t" << GetPiece(6, 0, b) << "\t" << GetPiece(7, 0, b) << "  \n";
	cout << "\t" << base << "\t" << base << "\t" << base << "  \n\n";

}
/////////////////////////////////////////////////////////////////////////
// param Board game, current game state
// AskPlayer is the method of getting the player peg move from A-H.
// regex is used to ensure proper input.
// As well as checking peg capacity.
// If the input is correct it returns an int specifying the peg on the game.pegs array
/////////////////////////////////////////////////////////////////////////
int askPlayer(Board game) {
	regex regl("[a-hA-H]");
	string s;
	int m;
	cout << "please make your move A-H\n";
	while (true) {
		cin >> s;
		if (s.length() < 2 && (regex_search(s, regl))) {
			m = (s.at(0) + 7) % 8;
			if (game.pegs[m].isFull()) {
				cout << "\nunfortunately that peg is full..\n";
			}
			else break;
		}
		else cout << "\n incorrect input...\n";
	}
	return m;
}

/////////////////////////////////////////////////////////////////////////
// param Board game, final board state to get score
// param Player p1, getting the name/ color details of the player to announce proper winner
// Displays the Board UI one last time to show the ending state.
// Calculates p1 p2 score and determines winner
// Closing game message for self esteem boost to either player or AI
/////////////////////////////////////////////////////////////////////////
void DisplayFinish(Board game, Player p1, Player p2) {
	DisplayBoard(game,p1, p2);
	int p1Score = game.scoreBoard(p1.getColor());
	int p2Score = game.scoreBoard(p2.getColor());
	Player winner;
	if (p1Score > p2Score) winner = p1;
	else winner = p2;

	cout << "\nCONGRAGULATIONS " << winner.getName() << " YOU ARE SMART\n";
	cout << "\n\n\nPress enter to exit";
	cin;
	
}

/////////////////////////////////////////////////////////////////////////
// Essentially the main mehtod of game.
/////////////////////////////////////////////////////////////////////////
void playGame() {
	string name; //Name of human player
	MinMax AI; // creating the minimax AI, Dolores
	vector<vector<int>> AImoveList; //This is how AI counterMoves are stored
	Board game; //game Board
	Board other;
	int playernum; //when taking input this will specify the p1 or p2
	int move = 0; //the current peg move made by player initialized to 0, changed during game
	Player p1;
	Player p2;
	cout << "What is your name?\n";
	cin >> name;
	cout << "Do you want to go first(1) or second(2)?\n";
	cin >> playernum;

	//Initializing player colors names, and which is AI
	if (playernum == 1) { 
		p1.setColor(Color::RED);
		p1.setName(name);
		p1.AIflag = false; // using AI flags to potentially support

		p2.setColor(Color::WHITE);
		p2.setName("Dolores");
		p2.AIflag = true;
		AI.setMinMax(Color::WHITE);
		AImoveList = AI.makeMoves(game); //AI generates first set of moves upon init
	}
	else {
		p1.setColor(Color::RED);
		p1.setName("Dolores");
		p1.AIflag = true;
		AI.setMinMax(Color::RED);
		AImoveList = AI.makeMoves(game); 

		p2.setColor(Color::WHITE);
		p2.setName(name);
		p2.AIflag = false;
	}
	//The game being played
	while (true) {
		if (p1.AIflag == true) { //checking if p1 is AI
			game.pegs[AImoveList[move][1]].addPiece(p1.getColor()); //plays preset move
			if (game.gameOver()) break;
			DisplayBoard(game, p1, p2); //Displays board to player
			AImoveList = AI.makeMoves(game); //generates moves while player can decide
			move = askPlayer(game);
			game.pegs[move].addPiece(p2.getColor());
			if (game.gameOver()) break;// checking after every move if game is finished
		}
		else { //p2 is AI
			DisplayBoard(game, p1, p2);
			AImoveList = AI.makeMoves(game);
			move = askPlayer(game);
			game.pegs[move].addPiece(p1.getColor());
			if (game.gameOver()) break;
			game.pegs[AImoveList[move][1]].addPiece(p2.getColor());
			if (game.gameOver()) break;

		}
	}
	DisplayFinish(game, p1, p2);
}

/////////////////////////////////////////////////////////////////////////
// Once game is finished this method simply asks through cin and cout 
// if player would like to play another game.
/////////////////////////////////////////////////////////////////////////
bool maybeAnother() {
	string s;
	while (true) {
		cout << "\nwould you like to play another game??? (y)es, (n)o \n";
		cin >> s;
		if (s.at(0) == 'y') break;
		if (s.at(0) == 'n') return false;
		else cout << "Hit the 'y' key or the 'n' key...";
	}
	return true;

}

//////////////////////////////////////////////////////////////////////////
// Actual main class, allows for game reset
/////////////////////////////////////////////////////////////////////////
int main() {
	playGame();
	while (true) {
		if (maybeAnother())
			playGame();
		else break;
	}

	return 0;
}

