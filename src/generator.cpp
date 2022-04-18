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
	ull whitePieces = board.getWhitePieces();
	while (whiteKnights) {
		int x = highbit(whiteKnights);
		whiteKnights ^= ((ull) 1 << x);
		ull knightAttack = KNIGHT_ATTACK[x] & (~whitePieces);
		while (knightAttack) {
			Move move;
			int y = highbit(knightAttack);
			knightAttack ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
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
	ull blackPieces = board.getBlackPieces();
	while (blackKnights) {
		int x = highbit(blackKnights);
		blackKnights ^= ((ull) 1 << x);
		ull knightAttack = KNIGHT_ATTACK[x] & (~blackPieces);
		while (knightAttack) {
			Move move;
			int y = highbit(knightAttack);
			int att = board.getPiece(y);
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
	ull whitePieces = board.getWhitePieces();
	while (whiteKing) {
		int x = highbit(whiteKing);
		whiteKing ^= ((ull) 1 << x);
		ull kingAttack = KING_ATTACK[x] & (~whitePieces);
		while (kingAttack) {
			Move move;
			int y = highbit(kingAttack);
			kingAttack ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
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
	ull blackPieces = board.getBlackPieces();
	while (blackKing) {
		int x = highbit(blackKing);
		blackKing ^= ((ull) 1 << x);
		ull kingAttack = KING_ATTACK[x] & (~blackPieces);
		while (kingAttack) {
			Move move;
			int y = highbit(kingAttack);
			kingAttack ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
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
		ull pawnAttack = WHITE_PAWN_ATTACK[x];
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
		ull pawnAttack = BLACK_PAWN_ATTACK[x];
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

int Generator::genFileState(int x) {
	// from top to bottom
	ull target = board.getOccupiedSquares();
	return ((target & FILE_MASK[x]) * MAGIC_FILE[FILES[x] - 1]) >> 57;
}

int Generator::genRankState(int x) {
	// from left to right
	// LSB represents the smaller indices
	ull target = board.getOccupiedSquares();
	return (target & RANK_MASK[x]) >> (x - x % 8 + 1);
}

int Generator::genDiagA1H8State(int x) {
	// from bottom to top
	ull target = board.getOccupiedSquares();
	return ((target & DIAG_A1H8_MASK[x]) * MAGIC_DIAG_A1H8[FILES[x] - RANKS[x] + 7]) >> 57;
}

int Generator::genDiagA8H1State(int x) {
	// from top to bottom
	ull target = board.getOccupiedSquares();
	return ((target & DIAG_A8H1_MASK[x]) * MAGIC_DIAG_A8H1[RANKS[x] + FILES[x] - 2]) >> 57;
}

void Generator::generateWhiteBishopMoves() {
	ull whiteBishops = board.getWhiteBishops();
	ull whitePieces = board.getWhitePieces();
	while (whiteBishops) {
		int x = highbit(whiteBishops);
		whiteBishops ^= ((ull) 1 << x);
		ull bishopAttack = (DIAG_A1H8_ATTACK[x][genDiagA1H8State(x)] | DIAG_A8H1_ATTACK[x][genDiagA8H1State(x)]) & (~whitePieces);
		bitdisplay(bishopAttack);
		while (bishopAttack) {
			Move move;
			int y = highbit(bishopAttack);
			bishopAttack ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(WHITE_BISHOP);
			move.setCapture(board.getPiece(y));
			whiteBishopMoves.push_back(move);
		}
	}
}

void Generator::generateBlackBishopMoves() {
	ull blackBishops = board.getBlackBishops();
	ull blackPieces = board.getBlackPieces();
	while (blackBishops) {
		int x = highbit(blackBishops);
		blackBishops ^= ((ull) 1 << x);
		ull bishopAttack = (DIAG_A1H8_ATTACK[x][genDiagA1H8State(x)] | DIAG_A8H1_ATTACK[x][genDiagA8H1State(x)]) & (~blackPieces);
		while (bishopAttack) {
			Move move;
			int y = highbit(bishopAttack);
			bishopAttack ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(BLACK_BISHOP);
			move.setCapture(board.getPiece(y));
			blackBishopMoves.push_back(move);
		}
	}
}

void Generator::generateWhiteRookMoves() {
	ull whiteRooks = board.getWhiteRooks();
	ull whitePieces = board.getWhitePieces();
	while (whiteRooks) {
		int x = highbit(whiteRooks);
		whiteRooks ^= ((ull) 1 << x);
		ull rookAttacks = (RANK_ATTACK[x][genRankState(x)] | FILE_ATTACK[x][genFileState(x)]) & (~whitePieces);
		while (rookAttacks) {
			Move move;
			int y = highbit(rookAttacks);
			rookAttacks ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(WHITE_ROOK);
			move.setCapture(board.getPiece(y));
			whiteRookMoves.push_back(move);
		}
	}
}

void Generator::generateBlackRookMoves() {
	ull blackRooks = board.getBlackRooks();
	ull blackPieces = board.getBlackPieces();
	while (blackRooks) {
		int x = highbit(blackRooks);
		blackRooks ^= ((ull) 1 << x);
		ull rookAttacks = (RANK_ATTACK[x][genRankState(x)] | FILE_ATTACK[x][genFileState(x)]) & (~blackPieces);
		while (rookAttacks) {
			Move move;
			int y = highbit(rookAttacks);
			rookAttacks ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(BLACK_ROOK);
			move.setCapture(board.getPiece(y));
			blackRookMoves.push_back(move);
		}
	}
}

void Generator::generateWhiteQueenMoves() {
	ull whiteQuenns = board.getWhiteQueens();
	ull whitePieces = board.getWhitePieces();
	while (whiteQuenns) {
		int x = highbit(whiteQuenns);
		whiteQuenns ^= ((ull) 1 << x);
		ull queenAttacks = (RANK_ATTACK[x][genRankState(x)] | FILE_ATTACK[x][genFileState(x)] | DIAG_A1H8_ATTACK[x][genDiagA1H8State(x)] | DIAG_A8H1_ATTACK[x][genDiagA8H1State(x)]) & (~whitePieces);
		while (queenAttacks) {
			Move move;
			int y = highbit(queenAttacks);
			queenAttacks ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(WHITE_QUEEN);
			move.setCapture(board.getPiece(y));
			whiteQueenMoves.push_back(move);
		}
	}
}

void Generator::generateBlackQueenMoves() {
	ull blackQueens = board.getBlackQueens();
	ull blackPieces = board.getBlackPieces();
	while (blackQueens) {
		int x = highbit(blackQueens);
		blackQueens ^= ((ull) 1 << x);
		ull queenAttacks = (RANK_ATTACK[x][genRankState(x)] | FILE_ATTACK[x][genFileState(x)] | DIAG_A1H8_ATTACK[x][genDiagA1H8State(x)] | DIAG_A8H1_ATTACK[x][genDiagA8H1State(x)]) & (~blackPieces);
		while (queenAttacks) {
			Move move;
			int y = highbit(queenAttacks);
			queenAttacks ^= ((ull) 1 << (ull) y);
			int att = board.getPiece(y);
			move.setFrom(x);
			move.setTo(y);
			move.setPiece(BLACK_QUEEN);
			move.setCapture(board.getPiece(y));
			blackQueenMoves.push_back(move);
		}
	}
}


void Generator::displayWhiteBishopMoves() {
	for (auto m : whiteBishopMoves) {
		m.display();
		std::cout << std::endl;
	}

}

void Generator::displayBlackBishopMoves() {
	for (auto m : blackBishopMoves) {
		m.display();
		std::cout << std::endl;
	}
}

void Generator::displayWhiteRookMoves() {
	for (auto m : whiteRookMoves) {
		m.display();
		std::cout << std::endl;
	}
}

void Generator::displayBlackRookMoves() {
	for (auto m : blackRookMoves) {
		m.display();
		std::cout << std::endl;
	}
}

void Generator::displayWhiteQueenMoves() {
	for (auto m : whiteQueenMoves) {
		m.display();
		std::cout << std::endl;
	}
}

void Generator::displayBlackQueenMoves() {
	for (auto m : blackQueenMoves) {
		m.display();
		std::cout << std::endl;
	}
}

void Generator::generateAllWhiteMoves() {
	generateWhiteBishopMoves();
	generateWhiteKingMoves();
	generateWhitePawnMoves();
	generateWhiteKnightMoves();
	generateWhiteQueenMoves();
	generateWhiteRookMoves();
}

void Generator::generateAllBlackMoves() {
	generateBlackBishopMoves();
	generateBlackKingMoves();
	generateBlackKnightMoves();
	generateBlackRookMoves();
	generateBlackQueenMoves();
	generateBlackPawnMoves();
}
