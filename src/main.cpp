#include "generator.h"
#include <global.h>
#include <iostream> 
#include <move.h>
#include <fstream>

int main() {
	std::fstream input("input.txt");
	std::string fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove;
	input >> fen >> fencolor >> fencastling >> fenenpessant >> fenhalfmoveclock >> fenfullmove;
	Board board(fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove);
	init();
	Generator gen(board);
	bitdisplay(GENERALIZED_ATTACK[2][1]);
	bitdisplay(gen.genDiagA1H8State(D3));
	return 0;
}
