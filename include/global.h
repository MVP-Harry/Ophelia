#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <globaldef.h>
#include <board.h>

extern Board board;


extern ull WHITE_PAWN_DIAGONAL_ATTACK[64];
extern ull BLACK_PAWN_DIAGONAL_ATTACK[64];
extern ull KNIGHT_ATTACK[64];
extern ull KING_ATTACK[64];
extern ull WHITE_PAWN_ATTACK[64];
extern ull BLACK_PAWN_ATTACK[64];
extern ull RANK_MASK[64];
extern ull FILE_MASK[64];
extern ull DIAG_A1H8_MASK[64];
extern ull DIAG_A8H1_MASK[64];
extern ull GENERALIZED_ATTACK[8][64];
extern ull RANK_ATTACK[64][64];
extern ull FILE_ATTACK[64][64];
extern ull DIAG_A1H8_ATTACK[64][64];
extern ull DIAG_A8H1_ATTACK[64][64];

void genKnight();

void genKing();

void genPawns();

void genRankMask();

void genFileMask();

void genDiagMask();

void genGeneralizedAttack();

void init();

std::pair<int, int> intToPair(int num);

int pairToInt(std::pair<int, int> p);

void bitdisplay(ull x);

bool isSameFile(int x, int y);

#endif
