#include "game.h"
#include <iostream>

void Game::run(Player* player1, Player* player2, char player1_marker, char player2_marker) {
	GameState game_state;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			game_state.board[i][j] = EMPTY_CELL;
		}
	}

	run(game_state, player1, player2, player1_marker, player2_marker);
}

void Game::run(GameState game_state, Player* player1, Player* player2, char player1_marker, char player2_marker) {
	while (true) {
		game_state.turnOf = player1_marker;
		player1->move(game_state);

		/*
		if (hasWon(game_state)) {
			std::cout << game_state.turnOf << " has won!" << std::endl;
			display();
			break;
		}
		*/
		
		if (fullBoard(game_state)) {
			std::cout << "It is a draw" << std::endl;
			display(game_state);
			break;
		}

		game_state.turnOf = player2_marker;
		player2->move(game_state);

		/*
		if (hasWon(game_state)) {
			std::cout << game_state.turnOf << " has won!" << std::endl;
			display();
			break;
		}
		*/
		
		if (fullBoard(game_state)) {
			std::cout << "It is a draw" << std::endl;
			display(game_state);
			break;
		}
	}
}

/*
bool Game::hasWon() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (game_state.board[i][j] == EMPTY_CELL) {
				return false;
			}
		}
	}

	return true;
}
*/

void Game::display(const GameState& game_state) const {
	std::cout << "Turn: " << game_state.turnOf << std::endl;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << game_state.board[i][j] << ' ';
		}

		std::cout << std::endl;
	}
}

bool Game::fullBoard(const GameState& game_state) const {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (game_state.board[i][j] == EMPTY_CELL) {
				return false;
			}
		}
	}

	return true;
}
