#ifndef BOARD_H
#define BOARD_H



#include <bitset>
#include <cstddef>
#include <istream>

class Board {
	// Using bitboard representation
	// a1 is the first bit, while h8 is the last bit (from right to left)
	std::bitset<64> whiteKing, whiteQueen, whiteRooks, whiteBishops, whiteKnights, whitePawns;
	std::bitset<64> blackKing, blackQueen, blackRooks, blackBishops, blackKnights, blackPawns;
	std::bitset<64> whitePieces, blackPieces, occupiedSquares;

	bool nextMove; // if nextMove is true, then it's white's turn
	bool castleWhite; // if white can still castle
	bool castleBlack; // if black can still castle

	int square[8][8];
	int epSquare; // En-passant square?
	int fiftyMove; // move since the last pawn move or capture
	int material; // total material in centipawn, in white's perspective

	public:

	Board() {
		// init without any variable
	}

	Board()
	
};



#endif
