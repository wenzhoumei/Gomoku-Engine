#include "game_state.h"
#include "player.h"
#include <string>
#include <vector>

class SimpleBotPlayer: public Player {
public:
	void move(GameState& game_state) override;
	std::string identity() override { return "simple bot"; };

private:
  std::vector<GameState> nextTurnStates(const GameState& game_state) const;
  int evaluate(const GameState& game_state) const;
  int getScore(int counter, bool player) const;
};

class RandomBotPlayer: public Player {
public:
	void move(GameState& game_state) override;
	std::string identity() override { return "random bot"; };
};
