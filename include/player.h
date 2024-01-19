#pragma once

#include "game_state.h"
#include <string>

class Player {
public:
	// Updates board of game state
	virtual void move(GameState& game_state) = 0;
	virtual std::string identity() = 0;
};
