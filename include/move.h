#ifndef MOVE_H
#define MOVE_H

#include <board.h>

class Move {
	int move;

	public:

	Move();

	Move(int m);

	void clear();

	void setFrom(int from);

	void setTo(int to);

	void setPiece(int piece);

	void setCapture(int capture);
	
	void setProm(int prom);

	int getFrom();

	int getTo();

	int getPiece();

	int getCapture();

	int getProm();

	bool isWhitemove();

	bool isBlackmove();

	bool isCapture();

	bool isKingcaptured();

	bool isRookmove();

	bool isRookcaptured();

	bool isKingmove();

	bool isPawnmove();

	bool isPawnDoublemove();

	bool isEnpassant();

	bool isPromotion();

	bool isCastle();
	
	bool isCastleOO();

	bool isCastleOOO();
};

#endif
