#ifndef BOARD_H
#define BOARD_H


#include <bitset>
#include <cstddef>
#include <iostream>
#include "global.h"

class Board {
	// Using bitboard representation
	// a1 is the first bit, while h8 is the last bit (from right to left)
	std::bitset<64> whiteKing, whiteQueen, whiteRooks, whiteBishops, whiteKnights, whitePawns;
	std::bitset<64> blackKing, blackQueen, blackRooks, blackBishops, blackKnights, blackPawns;
	std::bitset<64> whitePieces, blackPieces, occupiedSquares;

	bool nextMove; // if nextMove is true, then it's white's turn
	bool castleWhite; // if white can still castle
	bool castleBlack; // if black can still castle

	int square[9][9];
	int epSquare; // En-passant square?
	int fiftyMove; // move since the last pawn move or capture
	int material; // total material in centipawn, in white's perspective

	public:

	Board() {
		// init new game
		for (int i = 0; i < 64; i++) {
			int col = i % 8 + 1;
			int row = 8 - i / 8;
			square[row][col] = NEWGAME[i];
			switch (NEWGAME[i]) {
				case WHITE_KING:
					whiteKing |= (1 << i);
				case WHITE_QUEEN:
					whiteQueen |= (1 << i);
				case WHITE_ROOK:
					whiteRooks |= (1 << i);
				case WHITE_BISHOP:
					whiteBishops |= (1 << i);
				case WHITE_KNIGHT:
					whiteKnights |= (1 << i);
				case WHITE_PAWN:
					whitePawns |= (1 << i);
				case BLACK_KING:
					blackKing |= (1 << i);
				case BLACK_QUEEN:
					blackQueen |= (1 << i);
				case BLACK_ROOK:
					blackRooks |= (1 << i);
				case BLACK_BISHOP:
					blackBishops |= (1 << i);
				case BLACK_KNIGHT:
					blackKnights |= (1 << i);
				case BLACK_PAWN:
					blackPawns |= (1 << i);
			}
		}
		nextMove = true;
		castleBlack = castleWhite = true;
		fiftyMove = 0;
		epSquare = 0; // ????
	}

	Board(int input[64], bool next, int fiftyM, bool castleW, bool castleB, int epSq) {
		for (int i = 0; i < 64; i++) {
			int col = i % 8 + 1;
			int row = 8 - i / 8;
			square[row][col] = input[i];
			switch (input[i]) {
				case WHITE_KING:
					whiteKing |= (1 << i);
				case WHITE_QUEEN:
					whiteQueen |= (1 << i);
				case WHITE_ROOK:
					whiteRooks |= (1 << i);
				case WHITE_BISHOP:
					whiteBishops |= (1 << i);
				case WHITE_KNIGHT:
					whiteKnights |= (1 << i);
				case WHITE_PAWN:
					whitePawns |= (1 << i);
				case BLACK_KING:
					blackKing |= (1 << i);
				case BLACK_QUEEN:
					blackQueen |= (1 << i);
				case BLACK_ROOK:
					blackRooks |= (1 << i);
				case BLACK_BISHOP:
					blackBishops |= (1 << i);
				case BLACK_KNIGHT:
					blackKnights |= (1 << i);
				case BLACK_PAWN:
					blackPawns |= (1 << i);
			}
			nextMove = next;
			fiftyMove = fiftyM;
			castleWhite = castleW;
			castleBlack = castleB;
			epSquare = epSq;
		}
	}

	void display() {
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				std::cout << PIECENAMES[square[i][j]];
			}
			std::cout << std::endl;
		}
	}
	
};

#endif
