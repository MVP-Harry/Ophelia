#include "board.h"
#include <iostream>

int main() {
	
	char fen[100], fencolor[100], fencastling[100], fenenpessant[100], fenhalfmoveclock[100], fenfullmove[100];
	std::cin >> fen >> fencolor >> fencastling >> fenenpessant >> fenhalfmoveclock >> fenfullmove;
	Board sicilian(fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove);
	sicilian.display();
	return 0;
}
