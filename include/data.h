#ifndef DATA_H
#define DATA_H

#include <global.h>

class Data {

	public:
	ull KNIGHT_ATTACK[64];
	ull KING_ATTACK[64];
	ull WHITE_PAWN_ATTACK[64];
	ull BLACK_PAWN_ATTACK[64];
	ull RANK_ATTACK[64][64];
	ull FILE_ATTACK[64][64];

	Data();

	void genKnight();

	void genKing();

	void genPawns();

	void genRank();

	void genFile();
};

#endif
