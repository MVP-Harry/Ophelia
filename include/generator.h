#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <move.h>

class Generator {
	Board board;

	std::vector<Move> whiteKnighMoves;
	std::vector<Move> blackKnightMoves;
	std::vector<Move> whiteKingMoves;
	std::vector<Move> blackKingMoves;
	std::vector<Move> whitePawnMoves;
	std::vector<Move> blackPawnMoves;
	std::vector<Move> whiteBishopMoves;
	std::vector<Move> whiteRookMoves;
	std::vector<Move> whiteQueenMoves;
	std::vector<Move> blackBishopMoves;
	std::vector<Move> blackRookMoves;
	std::vector<Move> blackQueenMoves;

	public: 

	Generator(Board b);

	static ull highbit(ull number) {
		return 63 - __builtin_clzll(number);
	}

	void generateWhiteKnightMoves(); 

	void displayWhiteKnightMoves();

	void generateBlackKnightMoves();

	void displayBlackKnightMoves();

	void generateWhiteKingMoves();

	void displayWhiteKingMoves();

	void generateBlackKingMoves();

	void displayBlackKingMoves();

	void generateWhitePawnMoves();

	void generateBlackPawnMoves();

	void displayWhitePawnMoves();

	void displayBlackPawnMoves();

	void generateWhiteBishopMoves();

	void generateBlackBishopMoves();

	void generateWhiteRookMoves();

	void generateBlackRookMoves();

	void generateWhiteQueenMoves();

	void generateBlackQueenMoves();

	int genRankState(int x);

	int genFileState(int x);

	int genDiagA1H8State(int x);

	int genDiagA8H1State(int x);

	Board getBoard();
};

#endif
