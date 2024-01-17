#include "player.h"

class HumanPlayer: public Player {
	void move(const GameState& game_state) override;
};
