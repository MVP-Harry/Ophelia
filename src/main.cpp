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
	bitdisplay(gen.genRankState(E3));
	bitdisplay(GENERALIZED_ATTACK[4][22]);
	bitdisplay(RANK_ATTACK[E3][gen.genRankState(E3)]);
	return 0;
}
