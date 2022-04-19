#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <board.h>
#include <move.h>

void generateWhiteKnightMoves(int& index); 

void displayWhiteKnightMoves();

void generateBlackKnightMoves(int& index);

void displayBlackKnightMoves();

void generateWhiteKingMoves(int& index);

void displayWhiteKingMoves();

void generateBlackKingMoves(int& index);

void displayBlackKingMoves();

void generateWhitePawnMoves(int& index);

void generateBlackPawnMoves(int& index);

void displayWhitePawnMoves();

void displayBlackPawnMoves();

void generateWhiteBishopMoves(int& index);

void generateBlackBishopMoves(int& index);

void generateWhiteRookMoves(int& index);

void generateBlackRookMoves(int& index);

void generateWhiteQueenMoves(int& index);

void generateBlackQueenMoves(int& index);

void displayWhiteBishopMoves();

void displayBlackBishopMoves();

void displayWhiteRookMoves();

void displayBlackRookMoves();

void displayWhiteQueenMoves();

void displayBlackQueenMoves();

void generateAllWhiteMoves(int& index);

void displayAllWhiteMoves();

void generateAllBlackMoves(int& index);

void displayAllBlackMoves();

int genRankState(int x);

int genFileState(int x);

int genDiagA1H8State(int x);

int genDiagA8H1State(int x);

int generateMoves(int &index); 

bool isKingAttacked(Move curMove);

bool isAttacked(ull target, bool side); 

#endif
