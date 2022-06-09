#include "makemove.h"
#include <board.h>
#include <global.h>

// TODO: implement makes and unmakes move
//

void makeCapture(int capture, int to) {
	if (capture <= 8) board.whitePieces ^= BITSET[to];
	else board.blackPieces ^= BITSET[to];

	switch(capture) {
		case 1: // white pawn:
			board.whitePawns ^= BITSET[to];
			board.material -= PAWN_VALUE;
			break;
		case 2: // white king:
			board.whiteKing ^= BITSET[to];
			break;
		case 3: // white knight:
			board.whiteKnights ^= BITSET[to];
			board.material -= KNIGHT_VALUE;
			break;
		case 5: // white bishop:
			board.whiteBishops ^= BITSET[to];
			board.material -= BISHOP_VALUE;
			break;
		case 6: // white rook:
			board.whiteRooks ^= BITSET[to];
			board.material -= ROOK_VALUE;
			if (to == A1) board.castleWhite &= 2;
			if (to == H1) board.castleWhite &= 1;
			break;
		case 7: // white queen:
			board.whiteQueen ^= BITSET[to];
			board.material -= QUEEN_VALUE;
			break;
		case 9: // black pawn:
			board.blackPawns ^= BITSET[to];
			board.material += PAWN_VALUE;
			break;
		case 10: // black king:
			board.blackKing ^= BITSET[to];
			break;
		case 11: // black knight:
			board.blackKnights ^= BITSET[to];
			board.material += KNIGHT_VALUE;
			break;
		case 13: // black bishop:
			board.blackBishops ^= BITSET[to];
			board.material += BISHOP_VALUE;
			break;
		case 14: // black rook:
			board.blackRooks ^= BITSET[to];
			board.material += ROOK_VALUE;
			if (to == A8) board.castleBlack &= 2;
			if (to == H8) board.castleBlack &= 1;
			break;
		case 15: // black queen:
			board.blackQueen ^= BITSET[to];
			board.material += QUEEN_VALUE;
			break;
	}
}

void makeWhitePromotion(int prom, int to) {
	board.whitePawns ^= BITSET[to];
	board.material -= PAWN_VALUE;
	switch(prom) {
		case 3: // white knight
			board.whiteKnights ^= BITSET[to];
			board.material += KNIGHT_VALUE;
			break;
		case 5: // white bishop
			board.whiteBishops ^= BITSET[to];
			board.material += BISHOP_VALUE;
			break;
		case 6: // white rook
			board.whiteRooks ^= BITSET[to];
			board.material += ROOK_VALUE;
			break;
		case 7: // white queen
			board.whiteQueen ^= BITSET[to];
			board.material += QUEEN_VALUE;
			break;
	}
}

void makeBlackPromotion(int prom, int to) {
	board.blackPawns ^= BITSET[to];
	board.material += PAWN_VALUE;
	switch(prom) {
		case 11: // black knight
			board.blackKnights ^= BITSET[to];
			board.material -= KNIGHT_VALUE;
			break;
		case 13: // black bishop
			board.blackBishops ^= BITSET[to];
			board.material -= BISHOP_VALUE;
			break;
		case 14: // black rook
			board.blackRooks ^= BITSET[to];
			board.material -= ROOK_VALUE;
			break;
		case 15: // black queen
			board.blackQueen ^= BITSET[to];
			board.material -= QUEEN_VALUE;
			break;
	}
}

void makeMove(Move& move) {
	int from = move.getFrom();
	int to = move.getTo();
	int piece = move.getPiece();
	int capture = move.getCapture();
	ull fromBitMap = ((ull) 1 << from);
	ull fromToBitMap = fromBitMap | ((ull) 1 << to);

	// endofSearch starts from 0
	board.gameline[board.endofSearch].move = move;
	board.gameline[board.endofSearch].castleWhite = board.whiteOO() | board.whiteOOO();
	board.gameline[board.endofSearch].castleBlack = board.blackOO() | board.blackOOO();
	board.gameline[board.endofSearch].fiftyMove = board.getFifty();
	board.gameline[board.endofSearch].epSquare = board.getEnPassant();
	board.endofSearch++;

	switch (piece) {
		case 1: // white pawn:
			board.whitePawns           ^= fromToBitMap;
			board.whitePieces          ^= fromToBitMap;
		 	board.square[from]        = EMPTY;
			board.square[to]          = WHITE_PAWN;
			board.epSquare            = 0;
			board.fiftyMove           = 0;
			if (RANKS[from] == 2)
				if (RANKS[to] == 4) board.epSquare = from + 8;
			if (capture)
			{
				if (move.isEnpassant())
				{
						board.blackPawns           ^= BITSET[to-8];
						board.blackPieces          ^= BITSET[to-8];
						board.occupiedSquares    ^= fromToBitMap | BITSET[to-8];
						board.square[to-8]       = EMPTY;
						board.material           += PAWN_VALUE;
				}
				else
				{
						makeCapture(capture, to);
						board.occupiedSquares ^= fromBitMap;
				}
			}
			else board.occupiedSquares ^= fromToBitMap;
			if (move.isPromotion())
			{
				makeWhitePromotion(move.getProm(), to);
				board.square[to]         = move.getProm();
			}
			break;

		case 2: // white king:
			board.whiteKing             ^= fromToBitMap;
			board.whitePieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_KING;
			board.epSquare            = 0;    
			board.fiftyMove++;
			board.castleWhite = 0;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			if (move.isCastle())
			{
				if (move.isCastleOO())
				{
						board.whiteRooks         ^= BITSET[H1] | BITSET[F1];
						board.whitePieces          ^= BITSET[H1] | BITSET[F1];
						board.occupiedSquares    ^= BITSET[H1] | BITSET[F1];
						board.square[H1]          = EMPTY;
						board.square[F1]          = WHITE_ROOK;
				}
				else
				{
						board.whiteRooks         ^= BITSET[A1] | BITSET[D1];
						board.whitePieces          ^= BITSET[A1] | BITSET[D1];
						board.occupiedSquares    ^= BITSET[A1] | BITSET[D1];
						board.square[A1]          = EMPTY;
						board.square[D1]          = WHITE_ROOK;
				}
			}
			break;
		case 3: // white knight:
			board.whiteKnights         ^= fromToBitMap;
			board.whitePieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_KNIGHT;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			break;
		case 5: // white bishop:
			board.whiteBishops         ^= fromToBitMap;
			board.whitePieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_BISHOP;
			board.epSquare            = 0;
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			break;
		case 6: // white rook:
			board.whiteRooks         ^= fromToBitMap;
			board.whitePieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_ROOK;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (from == A1) board.castleWhite &= 2;
			if (from == H1) board.castleWhite &= 1;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			break;
		case 7: // white queen:
			board.whiteQueen          ^= fromToBitMap;
			board.whitePieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_QUEEN;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			break;
		case 9: // black pawn:
			board.blackPawns           ^= fromToBitMap;
			board.blackPieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_PAWN;
			board.epSquare            = 0;
			board.fiftyMove = 0;
			if (RANKS[from] == 7)
				if (RANKS[to] == 5) board.epSquare = from - 8;
			if (capture)
			{
				if (move.isEnpassant())
				{
						board.whitePawns           ^= BITSET[to+8];
						board.whitePieces          ^= BITSET[to+8];
						board.occupiedSquares    ^= fromToBitMap | BITSET[to+8];
						board.square[to+8]       = EMPTY;
						board.material           -= PAWN_VALUE;
				}
				else
				{
						makeCapture(capture, to);
						board.occupiedSquares ^= fromBitMap;
				}
			}
			else board.occupiedSquares ^= fromToBitMap;
			if (move.isPromotion())
			{
				makeBlackPromotion(move.getProm(), to);
				board.square[to]         = move.getProm();
			}
			break;
		case 10: // black king:
			board.blackKing             ^= fromToBitMap;
			board.blackPieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_KING;
			board.epSquare            = 0;    
			board.fiftyMove++;
			board.castleBlack = 0;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			if (move.isCastle())
			{
				if (move.isCastleOO())
				{
						board.blackRooks         ^= BITSET[H8] | BITSET[F8];
						board.blackPieces          ^= BITSET[H8] | BITSET[F8];
						board.occupiedSquares    ^= BITSET[H8] | BITSET[F8];
						board.square[H8]          = EMPTY;
						board.square[F8]          = BLACK_ROOK;
				}
				else
				{
						board.blackRooks         ^= BITSET[A8] | BITSET[D8];
						board.blackPieces          ^= BITSET[A8] | BITSET[D8];
						board.occupiedSquares    ^= BITSET[A8] | BITSET[D8];
						board.square[A8]          = EMPTY;
						board.square[D8]          = BLACK_ROOK;
				}
			}
			break;
		case 11: // black knight:
			board.blackKnights         ^= fromToBitMap;
			board.blackPieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_KNIGHT;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			break;
		case 13: // black bishop:
			board.blackBishops         ^= fromToBitMap;
			board.blackPieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_BISHOP;
			board.epSquare            = 0;
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			break;
		case 14: // black rook:
			board.blackRooks         ^= fromToBitMap;
			board.blackPieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_ROOK;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (from == A8) board.castleBlack &= 2;
			if (from == H8) board.castleBlack &= 1;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			break;
		case 15: // black queen:
			board.blackQueen          ^= fromToBitMap;
			board.blackPieces          ^= fromToBitMap;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_QUEEN;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromBitMap;
			}
			else board.occupiedSquares ^= fromToBitMap;
			break;
	}
	board.nextMove = !board.nextMove;
}

void unmakeMove(Move& move) {

}
