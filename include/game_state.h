#pragma once

#include "game_constants.h"

struct GameState {
	char turnOf;
	char board[BOARD_SIZE][BOARD_SIZE];
};
