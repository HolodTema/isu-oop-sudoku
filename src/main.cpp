#include <iostream>
#include "../include/GameFieldGenerator.hpp"
#include "../include/GameHandler.hpp"

int main() {
	GameHandler handler(std::cin, std::cout);
	handler.run();
	return 0;
}
