#pragma once

#include "constants.h"

class GameState {
	char turnOf;
	char board[BOARD_SIZE][BOARD_SIZE];

	void display();
};
