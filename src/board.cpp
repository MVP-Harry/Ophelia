#include "board.h"
#include "global.h"
#include <iostream>

void Board::helpInit() {
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			int id = (8 - i) * 8 + j - 1;
			switch (square[i][j]) {
				case WHITE_KING:
					whiteKing |= (1 << id);
					break;
				case WHITE_QUEEN:
					whiteQueen |= (1 << id);
					break;
				case WHITE_ROOK:
					whiteRooks |= (1 << id);
					break;
				case WHITE_BISHOP:
					whiteBishops |= (1 << id);
					break; case WHITE_KNIGHT: whiteKnights |= (1 << id);
					break;
				case WHITE_PAWN:
					whitePawns |= (1 << id);
					break;
				case BLACK_KING:
					blackKing |= (1 << id);
					break;
				case BLACK_QUEEN:
					blackQueen |= (1 << id);
					break;
				case BLACK_ROOK:
					blackRooks |= (1 << id);
					break;
				case BLACK_BISHOP:
					blackBishops |= (1 << id);
					break;
				case BLACK_KNIGHT:
					blackKnights |= (1 << id);
					break;
				case BLACK_PAWN:
					blackPawns |= (1 << id);
					break;
			}
		}
	}
}

Board::Board() {
	// init new game
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			square[i][j] = 0;
	for (int i = 0; i < 64; i++) {
		int col = i % 8 + 1;
		int row = 8 - i / 8;
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
}

Board::Board(int input[64], bool next, int fiftyM, int castleW, int castleB, int epSq) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			square[i][j] = 0;
	for (int i = 0; i < 64; i++) {
		int col = i % 8 + 1;
		int row = 8 - i / 8;
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
}

Board::Board(std::string fen, std::string fencolor, std::string fencastling, std::string fenenpessant, std::string fenhalfmoveclock, std::string fenfullmove) {
	// Init square and use helpInit to init bitset
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			square[i][j] = 0;
	int len = fen.length();
	int row = 1, col = 1;
	for (int i = 0; i < len; i++) {
		if (fen[i] == '/') {
			row++, col = 1;
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

	viewRotated = false;

	// Init nextMove
	if (fencolor[0] == 'w') nextMove = true;
	else nextMove = false;
	
	// Init castling
	if (fencastling[0] == 'K') castleWhite |= 2;
	if (fencastling[1] == 'Q') castleWhite |= 1;
	if (fencastling[2] == 'k') castleBlack |= 2;
	if (fencastling[3] == 'q') castleBlack |= 1;

	if (fenenpessant.length() == '1') epSquare = 0;
	else {
		epSquare = (fenenpessant[0] - 'a') * 8 + (fenenpessant[1] - '1');
	}

	fiftyMove = std::stoi(fenhalfmoveclock);
}

void Board::display() {
	if (viewRotated) {
		for (int i = 8; i >= 1; i--) {
			for (int j = 1; j <= 8; j++) {
				std::cout << PIECENAMES[square[i][j]];
			}
			std::cout << std::endl;
		}
		return;
	}
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
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

ull Board::getWhiteKnights() {
	return whiteKnights;
}

int Board::getPiece(int num) {
	int r = num / 8;
	int c = num % 8;
	return square[8 - r][c];
}

int main() {
	std::string fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove;
	std::cin >> fen >> fencolor >> fencastling >> fenenpessant >> fenhalfmoveclock >> fenfullmove;
	Board new_board(fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove);
	new_board.display();
	return 0;
}

