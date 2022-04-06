#include <stdio.h>
#include <string.h>
#include <global.h>
#include <iostream>
#include <bitset>

ull KNIGHT_ATTACK[64];
ull KING_ATTACK[64];
ull WHITE_PAWN_ATTACK[64];
ull BLACK_PAWN_ATTACK[64];
ull RANK_MASK[64];
ull FILE_MASK[64];
ull DIAG_A1H8_MASK[64];
ull DIAG_A8H1_MASK[64];
ull GENERALIZED_ATTACK[8][64];
ull RANK_ATTACK[64][64];
ull FILE_ATTACK[64][64];

std::pair<int, int> intToPair(int num) {
	int r = 7 - num / 8;
	int c = num % 8;
	return std::make_pair(r, c);
}

int pairToInt(std::pair<int, int> p) {
	return (7 - p.first) * 8 + p.second;
}

void bitdisplay(ull x) {
	std::cout << std::bitset<64>(x) << std::endl;
}

bool isSameFile(int x, int y) {
	return (x % 8) == (y % 8);
}

void genKnight() {
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

void genKing() {
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

void genPawns() {
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

void genRankMask() {
	ull tempRank[8];
	memset(tempRank, 0, sizeof tempRank);
	for (int i = 0; i < 64; i++) {
		if (FILES[i] != 1 && FILES[i] != 8) {
			tempRank[RANKS[i] - 1] |= ((ull) 1 << i);
		}
	}
	for (int i = 0; i < 64; i++) {
		RANK_MASK[i] = tempRank[RANKS[i] - 1];
	}
}

void genFileMask() {
	ull tempFile[8];
	memset(tempFile, 0, sizeof tempFile);
	for (int i = 0; i < 64; i++) {
		if (RANKS[i] != 1 && RANKS[i] != 8) {
			tempFile[FILES[i] - 1] |= ((ull) 1 << i);
		}
	}
	for (int i = 0; i < 64; i++) {
		FILE_MASK[i] = tempFile[FILES[i] - 1];
	}
}

void genDiagMask() {
	ull tempDiag[15];
	memset(tempDiag, 0, sizeof tempDiag);
	for (int i = 0; i < 64; i++) {
		if (RANKS[i] != 1 && RANKS[i] != 8 && FILES[i] != 1 && FILES[i] != 8) {
			tempDiag[RANKS[i] + FILES[i] - 2] |= ((ull) 1 << i);
		}
	}
	for (int i = 0; i < 64; i++) {
		DIAG_A8H1_MASK[i] = tempDiag[RANKS[i] + FILES[i] - 2];
	}

	memset(tempDiag, 0, sizeof tempDiag);
	for (int i = 0; i < 64; i++) {
		if (RANKS[i] != 1 && RANKS[i] != 8 && FILES[i] != 1 && FILES[i] != 8) {
			tempDiag[FILES[i] - RANKS[i] + 7] |= ((ull) 1 << i);
		}
	}
	for (int i = 0; i < 64; i++) {
		DIAG_A1H8_MASK[i] = tempDiag[FILES[i] - RANKS[i] + 7];
	}
}

void genGeneralizedAttack() {
	for (int pos = 0; pos < 8; pos++) {
		for (int mask = 0; mask < 64; mask++) {
			int eightBitOccupancy = mask << 1;
			eightBitOccupancy |= 1;
			eightBitOccupancy |= (1 << 7);
			if (pos == 0 && mask == 9) {
				bitdisplay(eightBitOccupancy);
			}
			ull attack = 0;
			int l = pos - 1, r = pos + 1;
			while (l >= 0) {
				attack |= (1 << (7 - l));
				if ((eightBitOccupancy >> (7 - l)) & 1) break;
				l--;
			}
			while (r <= 7) {
				attack |= (1 << (7 - r));
				if ((eightBitOccupancy >> (7 - r)) & 1) break;
				r++;
			}
			GENERALIZED_ATTACK[pos][mask] = attack;
		}
	}
}

void genRankAttack() {
	for (int square = 0; square < 64; square++) {
		for (int occ = 0; occ < 64; occ++) {

		}
	}
}

void init() {
	genKnight();
	genPawns();
	genKing();
	genDiagMask();
	genRankMask();
	genFileMask();
	genGeneralizedAttack();
}
