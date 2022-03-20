#ifndef BOARD_H
#define BOARD_H


#include <bitset>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <new>
#include <stdio.h>
#include <string.h>
#include "global.h"

class Board {
	// Using bitboard representation
	// a1 is the first bit, while h8 is the last bit (from right to left)
	std::bitset<64> whiteKing, whiteQueen, whiteRooks, whiteBishops, whiteKnights, whitePawns;
	std::bitset<64> blackKing, blackQueen, blackRooks, blackBishops, blackKnights, blackPawns;
	std::bitset<64> whitePieces, blackPieces, occupiedSquares;

	bool nextMove; // if nextMove is true, then it's white's turn
	bool viewRotated;
	int castleWhite; // if white can still castle; left bit represents king side, right bit represents queen side
	int castleBlack; // if black can still castle

	int square[9][9];
	int epSquare; // En-passant square?
	int fiftyMove; // move since the last pawn move or capture
	int material; // total material in centipawn, in white's perspective

	void helpInit();

	public:
	Board();

	Board(int input[64], bool next, int fiftyM, int castleW, int castleB, int epSq);

	Board(std::string fen, std::string fencolor, std::string fencastling, std::string fenenpessant, std::string fenhalfmoveclock, std::string fenfullmove);

	void display();

	void draw();

	bool getRotation();

	bool getTurn();
};

#endif
