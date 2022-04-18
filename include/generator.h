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
	std::vector<Move> allwhiteMoves;
	std::vector<Move> allBlackMoves;

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

	void displayWhiteBishopMoves();

	void displayBlackBishopMoves();

	void displayWhiteRookMoves();

	void displayBlackRookMoves();

	void displayWhiteQueenMoves();

	void displayBlackQueenMoves();

	void generateAllWhiteMoves();

	void displayAllWhiteMoves();

	void generateAllBlackMoves();

	void displayAllBlackMoves();

	int genRankState(int x);

	int genFileState(int x);

	int genDiagA1H8State(int x);

	int genDiagA8H1State(int x);

	bool isAttacked(ull target, int side);
	
	Board getBoard();
};

#endif
