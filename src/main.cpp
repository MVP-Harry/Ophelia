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

	// Move move;
	// move.setFrom(G2);
	// move.setTo(G4);
	// move.setPiece(WHITE_PAWN);
	// makeMove(move);
	//
	// move.setFrom(F4);
	// move.setTo(G3);
	// move.setPiece(BLACK_PAWN)
	// move.setCapture(WHITE_PAWN);
	// move.setProm(WHITE_PAWN);
	// if (move.isEnpassant()) cout << "YES" << endl;
	// else cout << "No" << endl;
	// makeMove(move);
	// board.display();
	// cout << isKingAttacked(move) << endl;
	// cout << "#of captures: " << capture << endl;
	int count = 0, promotion = 0, capture = 0, enPassant = 0;
	
	perft(0, 2, count, capture, enPassant, promotion);
	cout << "#of nodes: " << count << endl;
	cout << "#of captures: " << capture << endl;
	cout << "#of Holy Hells: " << enPassant << endl;
	cout << "#of promotions: " << promotion << endl;
	return 0;
}
