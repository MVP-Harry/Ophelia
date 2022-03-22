#include <global.h>

std::pair<int, int> intToPair(int num) {
	int r = 7 - num / 8;
	int c = num % 8;
	return std::make_pair(r, c);
}

int pairToInt(std::pair<int, int> p) {
	return (7 - p.first) * 8 + p.second;
}
