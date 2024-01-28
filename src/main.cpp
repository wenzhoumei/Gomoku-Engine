#include "../include/game.h"
#include "../include/human_player.h"
#include "../include/simple_bot_player.h"
#include "../include/minimax_bot_player.h"

int main() {
	Game game;

	MinimaxBotPlayer minimax_bot_player;
	SimpleBotPlayer simple_bot_player;
	HumanPlayer human_player;

	game.run(&minimax_bot_player, &human_player);

	return 0;
}
