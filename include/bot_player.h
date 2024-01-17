#include "player.h"

class BotPlayer: public Player {
public:
	void move(const GameState& game_state) override;
};
