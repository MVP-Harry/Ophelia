#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <board.h>
#include <move.h>

void generateWhiteKnightMoves(); 

void displayWhiteKnightMoves();

void generateBlackKnightMoves();

void displayBlackKnightMoves();

void generateWhiteKingMoves();

void displayWhiteKingMoves();

void generateBlackKingMoves();

void displayBlackKingMoves();

void generateWhitePawnMoves();

void generateBlackPawnMoves();

void displayWhitePawnMoves();

void displayBlackPawnMoves();

void generateWhiteBishopMoves();

void generateBlackBishopMoves();

void generateWhiteRookMoves();

void generateBlackRookMoves();

void generateWhiteQueenMoves();

void generateBlackQueenMoves();

void displayWhiteBishopMoves();

void displayBlackBishopMoves();

void displayWhiteRookMoves();

void displayBlackRookMoves();

void displayWhiteQueenMoves();

void displayBlackQueenMoves();

void generateAllWhiteMoves();

void displayAllWhiteMoves();

void generateAllBlackMoves();

void displayAllBlackMoves();

int genRankState(int x);

int genFileState(int x);

int genDiagA1H8State(int x);

int genDiagA8H1State(int x);

#endif
