#include <iostream>
#include <fstream>
#include <board.h>
#include <global.h>
#include <generator.h>
#include <move.h>
#include <data.h>

int main() {
	// std::ifstream input("input.txt");
	// std::string fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove;
	// input >> fen >> fencolor >> fencastling >> fenenpessant >> fenhalfmoveclock >> fenfullmove;
	// Board board(fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove);
	// board.display();
	// Generator gen(board);
	// gen.generateWhiteKingMoves();
	// gen.displayWhiteKingMoves();
	Move move;
	move.setPiece(WHITE_KING);
	move.setProm(WHITE_KING);
	move.setFrom(63);
	move.setTo(60);

	std::cout << move.getCapture() << std::endl;
	return 0;
}
