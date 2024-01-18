#include <iostream>
#include "game.h"
#include "human_player.h"

int main() {
	Game game;

	HumanPlayer player1;
	HumanPlayer player2;

	game.run(&player1, &player2, 'O', 'X');

	return 0;
}
