#include <perft.h>
#include <generator.h>

void perft(int ply, int depth, int& count, int& capture, int& enPassant, int& promotion) {
	if (depth == 0) return;

	int temp = board.moveBufLen[ply];
	board.moveBufLen[ply + 1] = generateMoves(temp);

	for (int i = board.moveBufLen[ply]; i < board.moveBufLen[ply + 1]; i++) {
		Move curMove = board.moveBuf[i];

		makeMove(curMove);

		if (!isKingAttacked(curMove)) {
			count++;
			if (curMove.isCapture()) capture++;
			if (curMove.isEnpassant()) enPassant++;
			if (curMove.isPromotion()) promotion++;
			perft(ply + 1, depth - 1, count, capture, enPassant, promotion);
		}

		unmakeMove(curMove);
	}
}
