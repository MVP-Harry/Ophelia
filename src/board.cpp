#include "board.h"
#include <iostream>

void Board::helpInit() {
	//this is a comment
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			int id = i * 8 + j;
			ull val = ((ull) 1 << (ull) id);
			switch (square[8 * i + j]) {
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
	endofGame = 0;
	endofSearch = 0;
	for (int i = 0; i < MAX_PLY; i++) moveBufLen[i] = 0;
}

Board::Board() {
	// init new game
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			square[8 * i + j] = 0;
	for (int i = 0; i < 64; i++) {
		square[i] = NEWGAME[i];
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
	for (int i = 0; i < 64; i++) square[i] = 0;
	for (int i = 0; i < 64; i++) {
		square[i] = input[i];
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
	for (int i = 0; i < 64; i++) square[i] = 0;
	int len = fen.length();
	int row = 7, col = 0;
	for (int i = 0; i < len; i++) {
		if (fen[i] == '/') {
			row--, col = 0;
		} else if (isdigit(fen[i])) {
			int num = fen[i] - '0';
			col += num;
		} else {
			switch (fen[i]) {
				case 'P': 
					square[8 * row + col] = 1;
					break;
				case 'K': 
					square[8 * row + col] = 2;
					break;
				case 'N': 
					square[8 * row + col] = 3;
					break;
				case 'B': 
					square[8 * row + col] = 5;
					break;
				case 'R': 
					square[8 * row + col] = 6;
					break;
				case 'Q': 
					square[8 * row + col] = 7;
					break;
				case 'p': 
					square[8 * row + col] = 9;
					break;
				case 'k': 
					square[8 * row + col] = 10;
					break;
				case 'n': 
					square[8 * row + col] = 11;
					break;
				case 'b': 
					square[8 * row + col] = 13;
					break;
				case 'r': 
					square[8 * row + col] = 14;
					break;
				case 'q': 
					square[8 * row + col] = 15;
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
		for (int i = 0; i <= 7; i++) {
			for (int j = 0; j <= 7; j++) {
				std::cout << PIECENAMES[square[8 * i + j]];
			}
			std::cout << std::endl;
		}
		return;
	}
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j <= 7; j++) {
			std::cout << PIECENAMES[square[8 * i + j]];
		}
		std::cout << std::endl;
	}
}

int Board::getFifty() {
	return fiftyMove;
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

ull Board::getWhiteBishops() {
	return whiteBishops;
}

ull Board::getWhiteRooks() {
	return whiteRooks;
}

ull Board::getWhiteQueens() {
	return whiteQueen;
}

ull Board::getBlackBishops() {
	return blackBishops;
}

ull Board::getBlackRooks() {
	return blackRooks;
}

ull Board::getBlackQueens() {
	return blackQueen;
}

ull Board::getWhitePieces() {
	return whitePieces;
}

ull Board::getBlackPieces() {
	return blackPieces;
}

int Board::getPiece(int num) {
	return square[num];
}

int Board::getEnPassant() {
	return epSquare;
}

ull Board::getOccupiedSquares() {
	return occupiedSquares;
}
