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

void Generator::generateWhiteKingMoves() {
	ull whiteKing = board.getWhiteKing();
	while (whiteKing) {
		int x = highbit(whiteKing);
		whiteKing ^= ((ull) 1 << x);
		ull kingAttack = data.KING_ATTACK[x];
		while (kingAttack) {
			Move move;
			int y = highbit(kingAttack);
			kingAttack ^= ((ull) 1 << (ull) y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(WHITE_KING);
			move.setCapture(board.getPiece(y));
			whiteKingMoves.push_back(move);
		}
	}

	// CASTLING
	if (board.whiteOO() && board.getPiece(E1) == WHITE_KING && board.getPiece(H1) == WHITE_ROOK && board.getPiece(F1) == EMPTY && board.getPiece(G1) == EMPTY) {
		Move move;
		move.setFrom(E1);
		move.setTo(G1);
		move.setProm(WHITE_KING);
		move.setPiece(WHITE_KING);
		whiteKingMoves.push_back(move);
	}

	if (board.whiteOOO() && board.getPiece(E1) == WHITE_KING && board.getPiece(A1) == WHITE_ROOK && board.getPiece(B1) == EMPTY && board.getPiece(C1) == EMPTY && board.getPiece(D1) == EMPTY) {
		Move move;
		move.setFrom(E1);
		move.setTo(C1);
		move.setProm(WHITE_KING);
		move.setPiece(WHITE_KING);
		std::cout << move.getCapture() << std::endl;
		whiteKingMoves.push_back(move);
	}
}

void Generator::displayWhiteKingMoves() {
	for (auto m : whiteKingMoves) {
		m.display();
		std::cout << std::endl;
	}
}

