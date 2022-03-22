#include <iostream>
#include <fstream>
#include <board.h>
#include <global.h>
#include <generator.h>
#include <move.h>
#include <data.h>

int main() {
	std::ifstream input("input.txt");
	std::string fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove;
	input >> fen >> fencolor >> fencastling >> fenenpessant >> fenhalfmoveclock >> fenfullmove;
	Board board(fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove);
	board.display();
	Generator gen(board);
	gen.generateWhiteKnightMoves();
	gen.displayWhiteKnightMoves();
	return 0;
}
