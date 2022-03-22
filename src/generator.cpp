#include <global.h>
#include <fstream>
#include <iostream>
#include <generator.h>
#include <bitset>

Generator::Generator(Board b) {
	board = b;
}

void Generator::generateWhiteKnightMoves() {
	ull whiteKnights = board.getWhiteKnights();
	while (whiteKnights) {
		int x = highbit(whiteKnights);
		whiteKnights ^= ((ull) 1 << x);
		ull knightAttack = data.KNIGHT_ATTACK[x];
		while (knightAttack) {
			Move move;
			int y = highbit(knightAttack);
			knightAttack ^= ((ull) 1 << (ull) y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(WHITE_KNIGHT);
			move.setCapture(board.getPiece(y));
			whiteKnighMoves.push_back(move);
		}
	}
}

void Generator::displayWhiteKnightMoves() {
	for (auto m : whiteKnighMoves) {
		m.display();
		std::cout << std::endl;
	}
}

void Generator::generateBlackKnightMoves() {
	ull blackKnights = board.getBlackKnights();
	while (blackKnights) {
		int x = highbit(blackKnights);
		blackKnights ^= ((ull) 1 << x);
		ull knightAttack = data.KNIGHT_ATTACK[x];
		while (knightAttack) {
			Move move;
			int y = highbit(knightAttack);
			knightAttack ^= ((ull) 1 << (ull) y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(BLACK_KNIGHT);
			move.setCapture(board.getPiece(y));
			blackKnightMoves.push_back(move);
		}
	}
}

void Generator::displayBlackKnightMoves() {
	for (auto m : blackKnightMoves) {
		m.display();
		std::cout << std::endl;
	}
}

Board Generator::getBoard() {
	return board;
}

int main() {
	std::ifstream input("input.txt");
	std::string fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove;
	input >> fen >> fencolor >> fencastling >> fenenpessant >> fenhalfmoveclock >> fenfullmove;
	Board board(fen, fencolor, fencastling, fenenpessant, fenhalfmoveclock, fenfullmove);
	Generator gen(board);
	gen.generateWhiteKnightMoves();
	gen.displayWhiteKnightMoves();
	gen.generateBlackKnightMoves();
	gen.displayBlackKnightMoves();
	return 0;
}
