// TODO: Implement makeMove/unmakeMove & isKingAttacked

#include <fstream>
#include <global.h>
#include <move.h>
#include <board.h>
#include <iostream>
#include <generator.h>
#include <perft.h>

int main() {
	std::string fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove;
	std::fstream input("input.txt");
	input >> fen >> fencolor >> fencastling >> fenenpessant >> fenhalfmoveclock >> fenfullmove;
	init();
	board = Board(fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove);

	Move move;
	move.setFrom(C7);
	move.setTo(C6);
	move.setCapture(WHITE_KNIGHT);
	move.setPiece(BLACK_KING);

	std::cout << isKingAttacked(move) << std::endl;
	return 0;
}
