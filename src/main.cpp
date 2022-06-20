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
	move.setFrom(E2);
	move.setTo(C4);
	move.setPiece(WHITE_BISHOP);
	// move.setCapture(BLACK_BISHOP);
	// makeMove(move);

	board.display();

	int count = perft(0, 2);

	cout << "#of nodes: " << count << endl;
	cout << "#of captures: " << ICAPT << endl;
	cout << "#of Holy Hells: " << IEP << endl;
	cout << "#of promotions: " << IPROM << endl;
	cout << "#of castles: " << ICASTLE << endl;
	return 0;
}
