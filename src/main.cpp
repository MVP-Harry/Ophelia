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
	bitdisplay(gen.genRankState(E4));
	std::cout << gen.genRankState(E4) << std::endl;
	bitdisplay(GENERALIZED_ATTACK[4][gen.genRankState(E4)]);
	return 0;
}
