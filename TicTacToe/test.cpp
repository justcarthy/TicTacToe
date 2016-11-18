
#include "Peg.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>
#include <future>
#include <functional>
#include "MinMax.h"
using namespace std;


int main() {
	future<vector<int>> fut = async(MinMax::makeMoves, 2);
	printf("hello \n");
	vector<int> r;
	r = fut.get();
}

