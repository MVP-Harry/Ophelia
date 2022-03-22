#include <iostream>
#include <generator.h>

Generator::Generator(Board b) {
	board = b;
}

void Generator::generateWhiteKnightMoves() {
	ull whiteKnights = board.getWhiteKnights();
	while (whiteKnights) {
		int x = lowbit(whiteKnights);
		whiteKnights ^= ((ull) 1 << x);
		ull knightAttack = data.KNIGHT_ATTACK[x];
		while (knightAttack) {
			Move move;
			int y = lowbit(knightAttack);
			knightAttack ^= ((ull) 1 << y);
			move.setFrom(y);
			move.setPiece(WHITE_KNIGHT);
			move.setCapture(board.getPiece(y));
			whiteKnighMoves.push_back(move);
		}
	}
}

void Generator::displayWhiteKnightMoves() {
	for (auto m : whiteKnighMoves) {
		m.display();
	}
}

int main() {
	std::cout << "wtf bro" << std::endl;
	return 0;
}
