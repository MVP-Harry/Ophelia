#include <perft.h>
#include <generator.h>

int perft(int ply, int depth) {
	if (depth == 0) return 1;

	int temp = board.moveBufLen[ply];
	int count = 0;
	board.moveBufLen[ply + 1] = generateMoves(temp);


	for (int i = board.moveBufLen[ply]; i < board.moveBufLen[ply + 1]; i++) {
		Move curMove = board.moveBuf[i];

		makeMove(curMove);

		if (!isKingAttacked(curMove)) {
			count += perft(ply + 1, depth - 1);

			if (depth == 1) {
				if (curMove.isEnpassant()) IEP++;
				if (curMove.isCapture()) ICAPT++;
				if (curMove.isCastle()) ICASTLE++;
				if (curMove.isPromotion()) IPROM++;
			}
		}

		unmakeMove(curMove);
	}

	return count;
}
