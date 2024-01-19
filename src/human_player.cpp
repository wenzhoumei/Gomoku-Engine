#include "../include/human_player.h"
#include <iostream>
#include <sstream>

void HumanPlayer::move(GameState& game_state) {
	int x, y;

	while (true) {
		prompt(game_state);

		if (!getCoords(x, y)) {
			std::cout << "Invalid format" << std::endl;
			continue;
		}

		if (!inBounds(x, y)) {
			std::cout << "Out of bounds" << std::endl;
			continue;
		}

		if (!emptyCell(x, y, game_state)) {
			std::cout << "Not an empty cell" << std::endl;
			continue;
		}

		break;
	}

	game_state.board[x][y] = game_state.turnOf;
}

void HumanPlayer::prompt(const GameState& game_state) const {
	std::cout << "Input move: " << std::flush;
}

bool HumanPlayer::getCoords(int& x, int& y) const {
	std::string input;
	std::getline(std::cin, input);

	std::istringstream iss(input);

	if (!(iss >> y >> x)) {
		return false;
	}

	return true;
}

bool HumanPlayer::inBounds(int x, int y) const {
	return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

bool HumanPlayer::emptyCell(int x, int y, const GameState& game_state) const {
	return game_state.board[x][y] == '.';
}
