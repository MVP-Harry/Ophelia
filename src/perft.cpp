#include "generator.h"
#include "makemove.h"
#include <perft.h>

ull perft(int ply, int depth) {
	// testing
	if (depth == 0) return 1;

	ull count = 0;
	board.moveBufLen[ply + 1] = generateMoves(board.moveBufLen[ply]);

	for (int i = board.moveBufLen[ply]; i < board.moveBufLen[ply + 1]; i++) {
		makeMove(board.moveBuf[i]);

		if (!isKingAttacked()) {
			// implement isKingAttacked to check legality!
			count += perft(ply + 1, depth - 1);
		}

		unmakeMove(board.moveBuf[i]);
	}

	return count;
}
