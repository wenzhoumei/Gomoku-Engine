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
  int getScore(int threat_length, int multiplier, int weight) const;
  int getThreatLength(const GameState& game_state, int directionX, int directionY, int x, int y, char marker) const;
  bool hasWon(const GameState& game_state) const;
};
