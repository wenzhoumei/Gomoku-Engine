#include <iostream>
#include "game.h"
#include "human_player.h"

int main() {
	Game game;

	game.initialize(new HumanPlayer(), new HumanPlayer());
	game.run();

	return 0;
}
