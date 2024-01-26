#include "../include/game.h"
#include "../include/human_player.h"
#include "../include/simple_bot_player.h"

int main() {
	Game game;

	SimpleBotPlayer player1;
	SimpleBotPlayer player2;

	game.run(&player1, &player2);

	return 0;
}
