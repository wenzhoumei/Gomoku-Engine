#include "../include/game_state.h"
#include <iostream>

void GameState::display() const {
	std::cout << "Turn: " << turnOf << std::endl;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << board[i][j] << ' ';
		}

		std::cout << std::endl;
	}
}
