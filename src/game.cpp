#include "game.h"

void Game::initialize(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			gameState.board[i][j] = EMPTY_CELL;
		}
	}
}

void Game::run() {
	while (true) {
		gameState.turnOf = player1Marker;
		player1->move(gameState);

		gameState.turnOf = player2Marker;
		player2->move(gameState);
	}
}
