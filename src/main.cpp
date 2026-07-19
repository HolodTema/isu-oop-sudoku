#include <iostream>
#include "../include/ScreenHandler.hpp"

int main() {
	ScreenHandler screenHandler(std::cin, std::cout);
	screenHandler.run();
	return 0;
}
