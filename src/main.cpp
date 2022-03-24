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
	Generator gen(board);
	gen.generateBlackPawnMoves();
	gen.displayBlackPawnMoves();
	return 0;
}
