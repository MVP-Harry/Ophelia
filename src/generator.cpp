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
			int att = board.getPiece(y);
			if (att != EMPTY && att <= 8) continue;
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
			int att = board.getPiece(y);
			if (att != EMPTY && att >= 8) continue;
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
			int att = board.getPiece(y);
			if (att != EMPTY && att <= 8) continue;
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
		whiteKingMoves.push_back(move);
	}
}

void Generator::displayWhiteKingMoves() {
	for (auto m : whiteKingMoves) {
		m.display();
		std::cout << std::endl;
	}
}

void Generator::generateBlackKingMoves() {
	ull blackKing = board.getBlackKing();
	while (blackKing) {
		int x = highbit(blackKing);
		blackKing ^= ((ull) 1 << x);
		ull kingAttack = data.KING_ATTACK[x];
		while (kingAttack) {
			Move move;
			int y = highbit(kingAttack);
			kingAttack ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
			if (att != EMPTY && att >= 8) continue;
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(BLACK_KING);
			move.setCapture(board.getPiece(y));
			blackKingMoves.push_back(move);
		}
	}

	// CASTLING
	if (board.blackOO() && board.getPiece(E8) == BLACK_KING && board.getPiece(H8) == BLACK_ROOK && board.getPiece(F8) == EMPTY && board.getPiece(G8) == EMPTY) {
		Move move;
		move.setFrom(E8);
		move.setTo(G8);
		move.setProm(BLACK_KING);
		move.setPiece(BLACK_KING);
		blackKingMoves.push_back(move);
	}

	if (board.blackOOO() && board.getPiece(E8) == BLACK_KING && board.getPiece(A8) == BLACK_ROOK && board.getPiece(B8) == EMPTY && board.getPiece(C8) == EMPTY && board.getPiece(D8) == EMPTY) {
		Move move;
		move.setFrom(E8);
		move.setTo(C8);
		move.setProm(BLACK_KING);
		move.setPiece(BLACK_KING);
		blackKingMoves.push_back(move);
	}
}

void Generator::displayBlackKingMoves() {
	for (auto m : blackKingMoves) {
		m.display();
		std::cout << std::endl;
	}
}

void Generator::generateWhitePawnMoves() {
	ull whitePawns = board.getWhitePawns();
	while (whitePawns) {
		int x = highbit(whitePawns);
		whitePawns ^= ((ull) 1 << (ull) x);
		ull pawnAttack = data.WHITE_PAWN_ATTACK[x];
		while (pawnAttack) {
			int y = highbit(pawnAttack);
			pawnAttack ^= ((ull) 1 << (ull) y);
			if (!isSameFile(x, y) && board.getPiece(y) == EMPTY && y == board.getEnPassant() == y) {
				Move move;
				move.setFrom(x);
				move.setTo(y);
				move.setProm(WHITE_PAWN);
				move.setPiece(WHITE_PAWN);
				whitePawnMoves.push_back(move);
			}
			if (isSameFile(x, y) && board.getPiece(y) != EMPTY) continue;
			if (isSameFile(x, y) && y == x + 16 && board.getPiece(x + 8) != EMPTY) continue;
			if (!isSameFile(x, y) && board.getPiece(y) <= 8) continue;
			Move move;
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(WHITE_PAWN);
			move.setCapture(board.getPiece(y));
			if (x <= 55 && x >= 48) {
				move.setProm(WHITE_KNIGHT);
				whitePawnMoves.push_back(move);
				move.setProm(WHITE_BISHOP);
				whitePawnMoves.push_back(move);
				move.setProm(WHITE_ROOK);
				whitePawnMoves.push_back(move);
				move.setProm(WHITE_QUEEN);
			}
			whitePawnMoves.push_back(move);
		}
	}
}

void Generator::displayWhitePawnMoves() {
	for (auto m : whitePawnMoves) {
		m.display();
	}
}

void Generator::generateBlackPawnMoves() {
	ull blackPawns = board.getBlackPawns();
	while (blackPawns) {
		int x = highbit(blackPawns);
		blackPawns ^= ((ull) 1 << (ull) x);
		ull pawnAttack = data.BLACK_PAWN_ATTACK[x];
		while (pawnAttack) {
			int y = highbit(pawnAttack);
			pawnAttack ^= ((ull) 1 << (ull) y);
			if (!isSameFile(x, y) && board.getPiece(y) == EMPTY && y == board.getEnPassant() == y) {
				Move move;
				move.setFrom(x);
				move.setTo(y);
				move.setProm(BLACK_PAWN);
				move.setPiece(BLACK_PAWN);
				blackPawnMoves.push_back(move);
			}
			if (isSameFile(x, y) && board.getPiece(y) != EMPTY) continue;
			if (isSameFile(x, y) && y == x - 16 && board.getPiece(x - 8) != EMPTY) continue;
			if (!isSameFile(x, y) && (board.getPiece(y) >= 8 || board.getPiece(y) == EMPTY)) continue;
			Move move;
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(BLACK_PAWN);
			move.setCapture(board.getPiece(y));
			if (x <= 15 && x >= 8) {
				move.setProm(BLACK_KNIGHT);
				blackPawnMoves.push_back(move);
				move.setProm(BLACK_BISHOP);
				blackPawnMoves.push_back(move);
				move.setProm(BLACK_ROOK);
				blackPawnMoves.push_back(move);
				move.setProm(BLACK_QUEEN);
			}
			blackPawnMoves.push_back(move);
		}
	}
}

void Generator::displayBlackPawnMoves() {
	for (auto m : blackPawnMoves) {
		m.display();
	}
}
