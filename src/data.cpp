#include "global.h"
#include <data.h>
#include <board.h>
#include <iostream>
#include <utility>

Data::Data() {
	genKnight();
	genKing();
	genPawns();
}

void Data::genKnight() {
	for (int i = 0; i < 64; i++) {
		ull val = 0;
		std::pair<int, int> coordinates = intToPair(i);
		for (int j = 0; j < 8; j++) {
			int x = coordinates.first + KNIGHT_MOVE_X[j];
			int y = coordinates.second + KNIGHT_MOVE_Y[j];
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				int xxx = pairToInt(std::make_pair(x, y));
				val |= ((ull) 1 << (ull) xxx);
			}
		}
		KNIGHT_ATTACK[i] = val;
	}
}

void Data::genKing() {
	for (int i = 0; i < 64; i++) {
		ull val = 0;
		std::pair<int, int> coordinates = intToPair(i);
		for (int j = 0; j < 8; j++) {
			int x = coordinates.first + KING_MOVE_X[j];
			int y = coordinates.second + KING_MOVE_Y[j];
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				int xxx = pairToInt(std::make_pair(x, y));
				val |= ((ull) 1 << (ull) xxx);
			}
		}
		KING_ATTACK[i] = val;
	}
}

void Data::genPawns() {
	for (int i = 0; i < 64; i++) {
		ull val = 0;
		ull val2 = 0;
		std::pair<int, int> coordinates = intToPair(i);
		int dx[3] = {-1, -1, -1};
		int dx2[3] = {1, 1, 1};
		int dy[3] = {-1, 0, 1};
		for (int j = 0; j < 3; j++) {
			int nx = coordinates.first + dx[j];
			int nx2 = coordinates.first + dx2[j];
			int ny = coordinates.second + dy[j];
			if (nx >= 0 && nx <= 7 && ny >= 0 && ny <= 7) {
				int xxx = pairToInt(std::make_pair(nx, ny));
				val |= ((ull) 1 << (ull) xxx);
			}
			if (nx2 >= 0 && nx2 <= 7 && ny >= 0 && ny <= 7) {
				int xxx = pairToInt(std::make_pair(nx2, ny));
				val2 |= ((ull) 1 << (ull) xxx);
			}
		}

		if (i >= 8 && i <= 15) {
			val |= ((ull) 1 << (ull) (i + 16));
		}
		if (i >= 48 && i <= 55) {
			val2 |= ((ull) 1 << (ull) (i - 16));
		}

		WHITE_PAWN_ATTACK[i] = val;
		BLACK_PAWN_ATTACK[i] = val2;
	}
}
