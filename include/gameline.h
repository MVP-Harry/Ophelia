#ifndef GAME_LINE_H
#define GAME_LINE_H

#include <move.h>

class GameLine {
public:
	Move move;
	bool castleWhite; // white's castle status, same as board.h
	bool castleBlack; // black's castle status
	int epSquare;
	int fiftyMove;
};

#endif
