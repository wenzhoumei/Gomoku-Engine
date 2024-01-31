#include "game_state.h"
#include "player.h"
#include <string>
#include <vector>

class MinimaxBotPlayer: public Player {
public:
	void move(GameState& game_state) override;
	std::string identity() override { return "minimax bot"; };

private:
  std::vector<GameState> nextTurnStates(const GameState& game_state) const;
  int evaluate(const GameState& game_state) const;
  int minimax(const GameState& game_state, int depth, int alpha, int beta, bool maximising_player) const;
  int getScore(int threat_length, int multiplier, int weight) const;
  int getThreatLength(const GameState& game_state, int directionX, int directionY, int x, int y, char marker) const;
  bool hasWon(const GameState& game_state) const;
  bool fullBoard(const GameState& game_state) const;
};
