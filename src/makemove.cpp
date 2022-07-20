#include "makemove.h"
#include <board.h>
#include <global.h>

// TODO: implement makes and unmakes move

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
	ull fromull = ((ull) 1 << from);
	ull fromToull = fromull | ((ull) 1 << to);

	// endofSearch starts from 0
	board.gameline[board.endofSearch].move = move;
	board.gameline[board.endofSearch].castleWhite = board.whiteOO() | board.whiteOOO();
	board.gameline[board.endofSearch].castleBlack = board.blackOO() | board.blackOOO();
	board.gameline[board.endofSearch].fiftyMove = board.getFifty();
	board.gameline[board.endofSearch].epSquare = board.getEnPassant();
	board.endofSearch++;

	switch (piece) {
		case 1: // white pawn:
			board.whitePawns           ^= fromToull;
			board.whitePieces          ^= fromToull;
		 	board.square[from]        = EMPTY;
			board.square[to]          = WHITE_PAWN;
			board.epSquare            = 0;
			board.fiftyMove           = 0;
			if (RANKS[from] == 2) {
				if (RANKS[to] == 4) { 
					board.epSquare = from + 8;
					// cout << board.epSquare << endl;
					// cout << "HELLO" << endl;
				}
			}
			if (capture)
			{
				if (move.isEnpassant())
				{
						board.blackPawns           ^= BITSET[to-8];
						board.blackPieces          ^= BITSET[to-8];
						board.occupiedSquares    ^= fromToull | BITSET[to-8];
						board.square[to-8]       = EMPTY;
						board.material           += PAWN_VALUE;
				}
				else
				{
						makeCapture(capture, to);
						board.occupiedSquares ^= fromull;
				}
			}
			else board.occupiedSquares ^= fromToull;
			if (move.isPromotion())
			{
				makeWhitePromotion(move.getProm(), to);
				board.square[to]         = move.getProm();
			}
			break;

		case 2: // white king:
			board.whiteKing             ^= fromToull;
			board.whitePieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_KING;
			board.epSquare            = 0;    
			board.fiftyMove++;
			board.castleWhite = 0;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
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
			board.whiteKnights         ^= fromToull;
			board.whitePieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_KNIGHT;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
			break;
		case 5: // white bishop:
			board.whiteBishops         ^= fromToull;
			board.whitePieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_BISHOP;
			board.epSquare            = 0;
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
			break;
		case 6: // white rook:
			board.whiteRooks         ^= fromToull;
			board.whitePieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_ROOK;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (from == A1) board.castleWhite &= 2;
			if (from == H1) board.castleWhite &= 1;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
			break;
		case 7: // white queen:
			board.whiteQueen          ^= fromToull;
			board.whitePieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = WHITE_QUEEN;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
			break;
		case 9: // black pawn:
			board.blackPawns           ^= fromToull;
			board.blackPieces          ^= fromToull;
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
						board.occupiedSquares    ^= fromToull | BITSET[to+8];
						board.square[to+8]       = EMPTY;
						board.material           -= PAWN_VALUE;
				}
				else
				{
						makeCapture(capture, to);
						board.occupiedSquares ^= fromull;
				}
			}
			else board.occupiedSquares ^= fromToull;
			if (move.isPromotion())
			{
				makeBlackPromotion(move.getProm(), to);
				board.square[to]         = move.getProm();
			}
			break;
		case 10: // black king:
			board.blackKing             ^= fromToull;
			board.blackPieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_KING;
			board.epSquare            = 0;    
			board.fiftyMove++;
			board.castleBlack = 0;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
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
			board.blackKnights         ^= fromToull;
			board.blackPieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_KNIGHT;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
			break;
		case 13: // black bishop:
			board.blackBishops         ^= fromToull;
			board.blackPieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_BISHOP;
			board.epSquare            = 0;
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
			break;
		case 14: // black rook:
			board.blackRooks         ^= fromToull;
			board.blackPieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_ROOK;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (from == A8) board.castleBlack &= 2;
			if (from == H8) board.castleBlack &= 1;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
			break;
		case 15: // black queen:
			board.blackQueen          ^= fromToull;
			board.blackPieces          ^= fromToull;
			board.square[from]        = EMPTY;
			board.square[to]          = BLACK_QUEEN;
			board.epSquare            = 0;    
			board.fiftyMove++;
			if (capture)
			{
				makeCapture(capture, to);
				board.occupiedSquares ^= fromull;
			}
			else board.occupiedSquares ^= fromToull;
			break;
	}
	board.nextMove = !board.nextMove;
}

void unmakeCapture(unsigned int &captured, unsigned int &to)
{
       // deals with all captures, except en-passant
       ull toull = BITSET[to];
 
       switch (captured)
       {
              case 1: // white pawn:
                     board.whitePawns           ^= toull;
                     board.whitePieces          ^= toull;
                     board.square[to]             = WHITE_PAWN;
                     board.material           += PAWN_VALUE;
                     break;
 
              case 2: // white king:
                     board.whiteKing             ^= toull;
                     board.whitePieces          ^= toull;
                     board.square[to]             = WHITE_KING;
                     break;
 
              case 3: // white knight:
                     board.whiteKnights         ^= toull;
                     board.whitePieces          ^= toull;
                     board.square[to]             = WHITE_KNIGHT;
                     board.material           += KNIGHT_VALUE;
                     break;
 
              case 5: // white bishop:
                     board.whiteBishops         ^= toull;
                     board.whitePieces          ^= toull;
                     board.square[to]             = WHITE_BISHOP;
                     board.material           += BISHOP_VALUE;
                     break;
 
              case 6: // white rook:
                     board.whiteRooks         ^= toull;
                     board.whitePieces          ^= toull;
                     board.square[to]             = WHITE_ROOK;
                     board.material           += ROOK_VALUE;
                     break;
 
              case 7: // white queen:
                     board.whiteQueen          ^= toull;
                     board.whitePieces          ^= toull;
                     board.square[to]             = WHITE_QUEEN;
                     board.material           += QUEEN_VALUE;
                     break;
 
              case 9: // black pawn:
                     board.blackPawns           ^= toull;
                     board.blackPieces          ^= toull;
                     board.square[to]             = BLACK_PAWN;
                     board.material           -= PAWN_VALUE;
                     break;
 
              case 10: // black king:
                     board.blackKing             ^= toull;
                     board.blackPieces          ^= toull;
                     board.square[to]             = BLACK_KING;
                     break;
 
              case 11: // black knight:
                     board.blackKnights         ^= toull;
                     board.blackPieces          ^= toull;
                     board.square[to]             = BLACK_KNIGHT;
                     board.material           -= KNIGHT_VALUE;
                     break;
 
              case 13: // black bishop:
                     board.blackBishops         ^= toull;
                     board.blackPieces          ^= toull;
                     board.square[to]             = BLACK_BISHOP;
                     board.material           -= BISHOP_VALUE;
                     break;
 
              case 14: // black rook:
                     board.blackRooks         ^= toull;
                     board.blackPieces          ^= toull;
                     board.square[to]             = BLACK_ROOK;
                     board.material           -= ROOK_VALUE;
                     break;
 
              case 15: // black queen:
                     board.blackQueen          ^= toull;
                     board.blackPieces          ^= toull;
                     board.square[to]             = BLACK_QUEEN;
                     board.material           -= QUEEN_VALUE;
                     break;
       }
}

void unmakeBlackPromotion(unsigned int prom, unsigned int &to)
{
       ull toull = BITSET[to];
 
       board.blackPawns ^= toull;
       board.material -= PAWN_VALUE;
 
       if (prom == 15)
       {
              board.blackQueen          ^= toull;
              board.material           += QUEEN_VALUE;
       }
       else if (prom == 14)
       {
              board.blackRooks         ^= toull;
              board.material           += ROOK_VALUE;
       }
       else if (prom == 13)
       {
              board.blackBishops       ^= toull;
              board.material           += BISHOP_VALUE;
       }
       else if (prom == 11)
       {
              board.blackKnights       ^= toull;
              board.material           += KNIGHT_VALUE;
       }
}

void unmakeWhitePromotion(unsigned int prom, unsigned int &to)
{
       ull toBitMap;
       ull toull = BITSET[to];
 
       board.whitePawns ^= toull;
       board.material += PAWN_VALUE;
 
       if (prom == 7)
       {
              board.whiteQueen          ^= toull;
              board.material           -= QUEEN_VALUE;
       }
       else if (prom == 6)
       {
              board.whiteRooks         ^= toull;
              board.material           -= ROOK_VALUE;
       }
       else if (prom == 5)
       {
              board.whiteBishops       ^= toull;
              board.material           -= BISHOP_VALUE;
       }
       else if (prom == 3)
       {
              board.whiteKnights       ^= toull;
              board.material           -= KNIGHT_VALUE;
       }
}

void unmakeMove(Move &move)
{
       unsigned int piece = move.getPiece();
       unsigned int captured = move.getCapture();
       unsigned int from = move.getFrom();
       unsigned int to = move.getTo();
 
       ull fromull  = BITSET[from];
       ull fromToull = fromull  | BITSET[to];
 
       switch (piece)
       {
              case 1: // white pawn:
                     board.whitePawns           ^= fromToull;
                     board.whitePieces          ^= fromToull;
                     board.square[from]        = WHITE_PAWN;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           if (move.isEnpassant())
                           {
                                  board.blackPawns           ^= BITSET[to-8];
                                  board.blackPieces          ^= BITSET[to-8];
                             board.occupiedSquares    ^= fromToull | BITSET[to-8];
                                  board.square[to-8]        = BLACK_PAWN;
                                  board.material           -= PAWN_VALUE;
                           }
                           else
                           {
                                  unmakeCapture(captured, to);
                                  board.occupiedSquares ^= fromull;
                           }
                     }
                     else board.occupiedSquares ^= fromToull;
 
                     if (move.isPromotion())
                     {
                           unmakeWhitePromotion(move.getProm(), to);
                     }
                     break;
 
              case 2: // white king:
                     board.whiteKing             ^= fromToull;
                     board.whitePieces          ^= fromToull;
                     board.square[from]        = WHITE_KING;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;
 
                     if (move.isCastle())
                     {
                           if (move.isCastleOO())
                           {
                                  board.whiteRooks         ^= BITSET[H1] | BITSET[F1];
                                  board.whitePieces          ^= BITSET[H1] | BITSET[F1];
                                  board.occupiedSquares    ^= BITSET[H1] | BITSET[F1];
                                  board.square[H1]          = WHITE_ROOK;
                                  board.square[F1]          = EMPTY;
                           }
                           else
                           {
                                  board.whiteRooks         ^= BITSET[A1] | BITSET[D1];
                                  board.whitePieces          ^= BITSET[A1] | BITSET[D1];
                                  board.occupiedSquares    ^= BITSET[A1] | BITSET[D1];
                                  board.square[A1]          = WHITE_ROOK;
                                  board.square[D1]          = EMPTY;
                           }
                     }
                     break;
 
              case 3: // white knight:
                     board.whiteKnights         ^= fromToull;
                     board.whitePieces          ^= fromToull;
                     board.square[from]        = WHITE_KNIGHT;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;
                     break;
 
              case 5: // white bishop:
                     board.whiteBishops         ^= fromToull;
                     board.whitePieces          ^= fromToull;
                     board.square[from]        = WHITE_BISHOP;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;
 
                     break;
 
              case 6: // white rook:
                     board.whiteRooks         ^= fromToull;
                     board.whitePieces          ^= fromToull;
                     board.square[from]        = WHITE_ROOK;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;
                     break;
 
              case 7: // white queen:
                     board.whiteQueen          ^= fromToull;
                     board.whitePieces          ^= fromToull;
                     board.square[from]        = WHITE_QUEEN;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;
                     break;
 
              case 9: // black pawn:
                     board.blackPawns           ^= fromToull;
                     board.blackPieces          ^= fromToull;
                     board.square[from]        = BLACK_PAWN;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           if (move.isEnpassant())
                           {
                                  board.whitePawns           ^= BITSET[to+8];
                                  board.whitePieces          ^= BITSET[to+8];
                                  board.occupiedSquares    ^= fromToull | BITSET[to+8];
                                  board.square[to+8]        = WHITE_PAWN;
                                  board.material           += PAWN_VALUE;
                           }
                           else
                           {
                                  unmakeCapture(captured, to);
                                  board.occupiedSquares ^= fromull;
                           }
                     }
                     else board.occupiedSquares ^= fromToull;
 
                     if (move.isPromotion())
                     {
                           unmakeBlackPromotion(move.getProm(), to);
                     }
                     break;
 
              case 10: // black king:
                     board.blackKing             ^= fromToull;
                     board.blackPieces          ^= fromToull;
                     board.square[from]        = BLACK_KING;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;
 
                     if (move.isCastle())
                     {
                           if (move.isCastleOO())
                           {
                                  board.blackRooks         ^= BITSET[H8] | BITSET[F8];
                                  board.blackPieces          ^= BITSET[H8] | BITSET[F8];
                                  board.occupiedSquares    ^= BITSET[H8] | BITSET[F8];
                                  board.square[H8]          = BLACK_ROOK;
                                  board.square[F8]          = EMPTY;
                           }
                           else
                           {
                                  board.blackRooks         ^= BITSET[A8] | BITSET[D8];
                                  board.blackPieces          ^= BITSET[A8] | BITSET[D8];
                                  board.occupiedSquares    ^= BITSET[A8] | BITSET[D8];
                                  board.square[A8]          = BLACK_ROOK;
                                  board.square[D8]          = EMPTY;
                           }
                     }
                     break;
 
              case 11: // black knight:
                     board.blackKnights         ^= fromToull;
                     board.blackPieces          ^= fromToull;
                     board.square[from]        = BLACK_KNIGHT;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;                  
                     break;
 
              case 13: // black bishop:
                     board.blackBishops         ^= fromToull;
                     board.blackPieces          ^= fromToull;
                     board.square[from]        = BLACK_BISHOP;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;                  
                     break;
 
              case 14: // black rook:
                     board.blackRooks         ^= fromToull;
                     board.blackPieces          ^= fromToull;
                     board.square[from]        = BLACK_ROOK;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;                  
                     break;
 
              case 15: // black queen:
                     board.blackQueen          ^= fromToull;
                     board.blackPieces          ^= fromToull;
                     board.square[from]        = BLACK_QUEEN;
                     board.square[to]          = EMPTY;
                     if (captured)
                     {
                           unmakeCapture(captured, to);
                           board.occupiedSquares ^= fromull;
                     }
                     else board.occupiedSquares ^= fromToull;                  
                     break;
       }
 
       board.endofSearch--;
       board.castleWhite         = board.gameline[board.endofSearch].castleWhite;
       board.castleBlack         = board.gameline[board.endofSearch].castleBlack;
       board.epSquare            = board.gameline[board.endofSearch].epSquare;
       board.fiftyMove           = board.gameline[board.endofSearch].fiftyMove;
 
       board.nextMove = !board.nextMove;
 
}

