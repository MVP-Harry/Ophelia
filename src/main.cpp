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
	std::cout << fen << " " << fencolor << " " << fencastling << " " << fenenpessant << " " << fenhalfmoveclock << " " << fenfullmove << std::endl;
	init();
	board = Board(fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove);
	std::cout << isAttacked((ull) 1 << C8, 1) << std::endl;

	return 0;
}
