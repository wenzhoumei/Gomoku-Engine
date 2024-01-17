#include "player.h"

class BotPlayer: public Player {
	void move(const GameState& game_state) override;
};
