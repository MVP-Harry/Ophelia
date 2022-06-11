#include "generator.h"
#include "makemove.h"
#include <perft.h>

ull perft(int ply, int depth) {
	// measure the perft value

	// cout << ply << " " << depth << endl;
	if (depth == 0) return 1;

	ull count = 0;
	int temp = board.moveBufLen[ply];
	// so that board.moveBufLen[ply] wouldn't increase
	board.moveBufLen[ply + 1] = generateMoves(temp);

	// cout << "moveBufLen[0] is equal to " << board.moveBufLen[ply] << endl;
	// cout << "moveBufLen[1] is equal to " << board.moveBufLen[ply + 1] << endl;

	for (int i = board.moveBufLen[ply]; i < board.moveBufLen[ply + 1]; i++) {
		Move curMove = board.moveBuf[i];

		makeMove(curMove);

		if (!isKingAttacked(curMove)) {
			// curMove.display();
			count += perft(ply + 1, depth - 1);
		} 

		unmakeMove(curMove);
	}

	return count;
}
