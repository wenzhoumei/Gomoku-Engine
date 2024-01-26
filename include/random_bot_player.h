#include "player.h"
class RandomBotPlayer: public Player {
public:
	void move(GameState& game_state) override;
	std::string identity() override { return "random bot"; };
};
