#include "../include/game.h"
#include "../include/human_player.h"
#include "../include/bot_player.h"

int main() {
	Game game;

	HumanPlayer player1;
	SimpleBotPlayer player2;

	game.run(&player1, &player2);

	return 0;
}
