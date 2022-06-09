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

	cout << board.nextMove << endl;
	cout << board.endofSearch << endl;

	Move move;
	move.setFrom(D2);
	move.setTo(D4);
	move.setPiece(WHITE_PAWN);

	makeMove(move);

	cout << board.nextMove << endl;
	cout << board.endofSearch << endl;
	return 0;
}
