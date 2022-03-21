#ifndef GENERATOR_H
#define GENERATOR_H

#include "global.h"
#include <board.h>
#include <data.h>
#include <move.h>
#include <stdexcept>
#include <vector>

class Generator {
	Board board;
	Data data;
	std::vector<Move> whiteKnighMoves;
	std::vector<Move> blackKnightMoves;

	public: 

	Generator(Board b);

	static ull lowbit(ull number) {
		if (number == 0) throw std::invalid_argument("doesn't work bro!!");
		return __builtin_ctz(number) + 1;
	}

	void generateWhiteKnightMoves(); 

	void displayWhiteKnightMoves();

	void generateBlackKnightMoves();

};

#endif
