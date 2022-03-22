#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <data.h>
#include <move.h>

class Generator {
	Board board;
	Data data;
	std::vector<Move> whiteKnighMoves;
	std::vector<Move> blackKnightMoves;

	public: 

	Generator(Board b);

	static ull highbit(ull number) {
		return 63 - __builtin_clzll(number);
	}

	void generateWhiteKnightMoves(); 

	void displayWhiteKnightMoves();

	void generateBlackKnightMoves();

};

#endif
