#include "../include/random_bot_player.h"
#include <ctime>

void RandomBotPlayer::move(GameState& game_state) {
    // Seed the random number generator
    std::srand(std::time(0));

    // Find the first empty position in a circular manner starting from a random point
    int start_index = std::rand() % (BOARD_SIZE * BOARD_SIZE);
    for (int k = 0; k < BOARD_SIZE * BOARD_SIZE; k++) {
        int index = (start_index + k) % (BOARD_SIZE * BOARD_SIZE);
        int i = index / BOARD_SIZE;
        int j = index % BOARD_SIZE;

        if (game_state.board[i][j] == '.') {
            game_state.board[i][j] = game_state.turnOf;
            return;
        }
    }
}
