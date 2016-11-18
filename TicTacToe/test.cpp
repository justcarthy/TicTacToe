
#include "Peg.h"
#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


enum{RED, WHITE};

int main() {
	Peg p;
	string name;
	int playernum;
	cout << "What is your name?";
	cin >> name;
	cout << "Do you want to go first(1) or second(2)?";
	cin >> playernum; //TODO: plan for different inputs
	if (playernum == 1) {
		Player p1 = Player(RED, name, false);
		Player p2 = Player(WHITE, "AI", true);
	}








	return 0;
}