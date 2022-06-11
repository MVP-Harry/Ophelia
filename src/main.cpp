#include "globaldef.h"
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
	move.setFrom(H2);
	move.setTo(H4);
	move.setPiece(WHITE_PAWN);
	makeMove(move);
	board.display();
	cout << board.getTurn() << endl;
	cout << "isAttacked? " << isKingAttacked(move) << endl;
	//
	// int index = 0;
	// generateAllBlackMoves(index);
	
	// unmakeMove(move);
	// cout << endl << endl;
	// board.display();
	// cout << "isKing Attacked? " << isKingAttacked(move) << endl;
	
	int count = perft(0, 1);
	cout << "#of nodes: " << count << endl;
	return 0;
}
