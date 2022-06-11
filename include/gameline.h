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

	GameLine() {
		castleBlack = 3;
		castleWhite = 3;
		epSquare = 0;
		fiftyMove = 0;
	}
};

#endif
