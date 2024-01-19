#include <iostream>
#include "../include/game.h"
#include "../include/human_player.h"
#include "../include/bot_player.h"

int main() {
	Game game;

	HumanPlayer player1;
	BotPlayer player2;

	game.run(&player1, &player2, 'O', 'X');

	return 0;
}
