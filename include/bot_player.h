#include "player.h"
#include <string>

class BotPlayer: public Player {
public:
	void move(GameState& game_state) override;
	std::string identity() override { return "random bot"; };
};
