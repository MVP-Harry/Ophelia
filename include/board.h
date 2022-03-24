#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "global.h"
#include <string>

class Board {
	// Using bitboard representation
	// a1 is the first bit, while h8 is the last bit (from right to left)
	ull whiteKing = 0, whiteQueen = 0, whiteRooks = 0, whiteBishops = 0, whiteKnights = 0, whitePawns = 0;
	ull blackKing = 0, blackQueen = 0, blackRooks = 0, blackBishops = 0, blackKnights = 0, blackPawns = 0;
	ull whitePieces = 0, blackPieces = 0, occupiedSquares = 0;

	bool nextMove = true; // if nextMove is true, then it's white's turn
	bool viewRotated = false;
	int castleWhite = 3; // if white can still castle; left bit represents king side, right bit represents queen side
	int castleBlack = 3; // if black can still castle

	int square[8][8];
	int epSquare = 0; // En-passant square?
	int fiftyMove = 0; // move since the last pawn move or capture
	int material = 0; // total material in centipawn, in white's perspective

	void helpInit();

	public:
	Board();

	Board(int input[64], bool next, int fiftyM, int castleW, int castleB, int epSq);

	Board(std::string fen, std::string fencolor, std::string fencastling, std::string fenenpessant, std::string fenhalfmoveclock, std::string fenfullmove);

	void display();

	void draw();

	bool getRotation();

	bool getTurn();

	bool whiteOO();

	bool whiteOOO();

	bool blackOOO();

	bool blackOO();

	ull getWhiteKnights();

	ull getBlackKnights();

	ull getWhiteKing();

	ull getBlackKing();

	ull getWhitePawns();

	ull getBlackPawns();

	int getEnPassant();

	int getPiece(int num);

};

#endif
