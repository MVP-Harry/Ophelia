#include "generator.h"
#include "makemove.h"
#include <perft.h>

ull perft(int ply, int depth) {
	// measure the perft value

	if (depth == 0) return 1;

	ull count = 0;
	board.moveBufLen[ply + 1] = generateMoves(board.moveBufLen[ply]);

	for (int i = board.moveBufLen[ply]; i < board.moveBufLen[ply + 1]; i++) {
		Move curMove = board.moveBuf[i];

		makeMove(curMove);

		if (!isKingAttacked(curMove)) {
			count += perft(ply + 1, depth - 1);
		}

		unmakeMove(curMove);
	}

	return count;
}
