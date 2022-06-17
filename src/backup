#include "generator.h"
#include "makemove.h"
#include <perft.h>

void perft(int ply, int depth, int& count, int& promotion, int& capture) {
	// measure the perft value

	if (depth == 0) return;

	int temp = board.moveBufLen[ply];
	// so that board.moveBufLen[ply] wouldn't increase
	board.moveBufLen[ply + 1] = generateMoves(temp);

	for (int i = board.moveBufLen[ply]; i < board.moveBufLen[ply + 1]; i++) {
		Move curMove = board.moveBuf[i];

		makeMove(curMove);

		if (!isKingAttacked(curMove)) {
			count++;
			if (curMove.isPromotion()) promotion++;
			if (curMove.isCapture()) capture++;
			perft(ply + 1, depth - 1, count, promotion, capture);
		} 

		unmakeMove(curMove);
	}

	// if (depth == 1) {
	// 	cout << "There are " << count << "moves!";
	// 	cout << endl << endl;
	// }
}
