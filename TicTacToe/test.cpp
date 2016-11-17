
#include "Peg.h"
#include <iostream>





int main() {
	Peg p = Peg();
	int i;
	for (i = 0; i < 3; i++) {
		std::cout << "The colour int is " << p.getColorAt(i) << "\n" ;
	}


	return 0;
}