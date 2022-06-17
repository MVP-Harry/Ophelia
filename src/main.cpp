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

	int count = perft(0, 4);

	cout << "#of nodes: " << count << endl;
	cout << "#of captures: " << ICAPT << endl;
	cout << "#of Holy Hells: " << IEP << endl;
	cout << "#of promotions: " << IPROM << endl;
	cout << "#of castles: " << ICASTLE << endl;
	return 0;
}
