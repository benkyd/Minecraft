#include <iostream>

#include "game.hpp"


int main(int argc, char** argv) {

	Game game;
	game.Setup(1080, 720);
	game.Run();

	return 0;

}
