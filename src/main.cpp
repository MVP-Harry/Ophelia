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
	bitdisplay(gen.genDiagA8H1State(D3));
	bitdisplay(DIAG_A8H1_ATTACK[D3][gen.genDiagA8H1State(D3)]);
	return 0;
}
