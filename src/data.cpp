#include <data.h>
#include <iostream>

Data::Data() {
	genKnight();
}

void Data::genKnight() {
	for (int i = 0; i < 64; i++) {
		ull val = 0;
		for (int j = 0; j < 8; j++) {
			int newSquare = i + KNIGHT_MOVE[j];
			if (0 <= newSquare && newSquare <= 63) {
				val |= ((ull) 1 << newSquare);
			}
		}
		KNIGHT_ATTACK[i] = val;
	}
}

// int main() {
// 	return 0;
// }
