#include "board.h"
#include <bitset>
#include <iostream>

void Board::helpInit() {
	//this is a comment
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			int id = (7 - i) * 8 + j;
			ull val = ((ull) 1 << (ull) id);
			switch (square[i][j]) {
				case WHITE_KING:
					whiteKing |= val;
					break;
				case WHITE_QUEEN:
					whiteQueen |= val;
					break;
				case WHITE_ROOK:
					whiteRooks |= val;
					break;
				case WHITE_BISHOP:
					whiteBishops |= val;
					break; 
				case WHITE_KNIGHT: 
					whiteKnights |= val;
					break;
				case WHITE_PAWN:
					whitePawns |= val;
					break;
				case BLACK_KING:
					blackKing |= val;
					break;
				case BLACK_QUEEN:
					blackQueen |= val;
					break;
				case BLACK_ROOK:
					blackRooks |= val;
					break;
				case BLACK_BISHOP:
					blackBishops |= val;
					break;
				case BLACK_KNIGHT:
					blackKnights |= val;
					break;
				case BLACK_PAWN:
					blackPawns |= val;
					break;
			}
		}
	}
}

Board::Board() {
	// init new game
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			square[i][j] = 0;
	for (int i = 0; i < 64; i++) {
		int col = i % 8;
		int row = 7 - i / 8;
		square[row][col] = NEWGAME[i];
	}
	helpInit();
	nextMove = true;
	viewRotated = false;
	castleBlack = castleWhite = 3;
	fiftyMove = 0;
	epSquare = 0; // ????
	whitePieces = whiteKing | whiteQueen | whiteBishops | whiteKnights | whiteRooks | whitePawns;
	blackPieces = blackKing | blackQueen | blackBishops | blackKnights | blackRooks | blackPawns;
	occupiedSquares = whitePieces | blackPieces;
}

Board::Board(int input[64], bool next, int fiftyM, int castleW, int castleB, int epSq) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			square[i][j] = 0;
	for (int i = 0; i < 64; i++) {
		int col = i % 8;
		int row = 7 - i / 8;
		square[row][col] = input[i];
	}
	helpInit();
	nextMove = next;
	viewRotated = false;
	fiftyMove = fiftyM;
	castleWhite = castleW;
	castleBlack = castleB;
	epSquare = epSq;
	whitePieces = whiteKing | whiteQueen | whiteBishops | whiteKnights | whiteRooks | whitePawns;
	blackPieces = blackKing | blackQueen | blackBishops | blackKnights | blackRooks | blackPawns;
	occupiedSquares = whitePieces | blackPieces;
}

Board::Board(std::string fen, std::string fencolor, std::string fencastling, std::string fenenpessant, std::string fenhalfmoveclock, std::string fenfullmove) {
	// Init square and use helpInit to init bitset
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			square[i][j] = 0;
	int len = fen.length();
	int row = 0, col = 0;
	for (int i = 0; i < len; i++) {
		if (fen[i] == '/') {
			row++, col = 0;
		} else if (isdigit(fen[i])) {
			int num = fen[i] - '0';
			col += num;
		} else {
			switch (fen[i]) {
				case 'P': 
					square[row][col] = 1;
					break;
				case 'K': 
					square[row][col] = 2;
					break;
				case 'N': 
					square[row][col] = 3;
					break;
				case 'B': 
					square[row][col] = 5;
					break;
				case 'R': 
					square[row][col] = 6;
					break;
				case 'Q': 
					square[row][col] = 7;
					break;
				case 'p': 
					square[row][col] = 9;
					break;
				case 'k': 
					square[row][col] = 10;
					break;
				case 'n': 
					square[row][col] = 11;
					break;
				case 'b': 
					square[row][col] = 13;
					break;
				case 'r': 
					square[row][col] = 14;
					break;
				case 'q': 
					square[row][col] = 15;
					break;
			}
			col++;
		}
	}

	helpInit();
	whitePieces = whiteKing | whiteQueen | whiteBishops | whiteKnights | whiteRooks | whitePawns;
	blackPieces = blackKing | blackQueen | blackBishops | blackKnights | blackRooks | blackPawns;
	occupiedSquares = whitePieces | blackPieces;

	viewRotated = false;

	// Init nextMove
	if (fencolor[0] == 'w') nextMove = true;
	else nextMove = false;
	
	// Init castling
	if (fencastling[0] == 'K') castleWhite |= 2;
	if (fencastling[1] == 'Q') castleWhite |= 1;
	if (fencastling[2] == 'k') castleBlack |= 2;
	if (fencastling[3] == 'q') castleBlack |= 1;

	if (fenenpessant.length() == 1) epSquare = 0;
	else {
		epSquare = (fenenpessant[0] - 'a') * 8 + (fenenpessant[1] - '1');
	}

	fiftyMove = std::stoi(fenhalfmoveclock);
}

void Board::display() {
	if (viewRotated) {
		for (int i = 7; i >= 0; i--) {
			for (int j = 0; j <= 7; j++) {
				std::cout << PIECENAMES[square[i][j]];
			}
			std::cout << std::endl;
		}
		return;
	}
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			std::cout << PIECENAMES[square[i][j]];
		}
		std::cout << std::endl;
	}
}

bool Board::getRotation() {
	return viewRotated;
}

bool Board::getTurn() {
	return nextMove;
}

bool Board::whiteOO() {
	return (castleWhite >> 1) & 1;
}

bool Board::whiteOOO() {
	return castleWhite & 1;
}

bool Board::blackOO() {
	return (castleBlack >> 1) & 1;
}

bool Board::blackOOO() {
	return castleBlack & 1;
}

ull Board::getWhiteKnights() {
	return whiteKnights;
}

ull Board::getBlackKnights() {
	return blackKnights;
}

ull Board::getWhiteKing() {
	return whiteKing;
}

ull Board::getBlackKing() {
	return blackKing;
}

ull Board::getWhitePawns() {
	return whitePawns;
}

ull Board::getBlackPawns() {
	return blackPawns;
}

int Board::getPiece(int num) {
	int r = num / 8;
	int c = num % 8;
	return square[7 - r][c];
}

int Board::getEnPassant() {
	return epSquare;
}

ull Board::getOccupiedSquares() {
	return occupiedSquares;
}
