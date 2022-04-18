#include <global.h>
#include <move.h>
#include <board.h>
#include <iostream>

void dummy(int& index) {
	index += 2;
}

int main() {
	int num = 1;
	dummy(num);
	std::cout << num << std::endl;
	return 0;
}
