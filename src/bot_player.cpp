#include "../include/bot_player.h"

void BotPlayer::move(GameState& game_state) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (game_state.board[i][j] == '.') {
				game_state.board[i][j] = game_state.turnOf;
				return;
			}
		}
	}
}
