#pragma once

#include "game_state.h"

class Player {
public:
	// Updates board of game state
	virtual void move(GameState& game_state) = 0;
};
