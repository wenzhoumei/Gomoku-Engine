#pragma once

#include "game_state.h"

class Player {
	virtual void move(const GameState& game_state) = 0;
};
