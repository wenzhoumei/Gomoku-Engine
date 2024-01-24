#include "player.h"

class Game {
public:
	void run(Player* player1, Player* player2);
	Player* run(GameState game_state, Player* player1, Player* player2);

private:
  // Runs all operations for a full turn, and returns {1: WIN, 2: DRAW, 0: CONTUNUE}
	int playTurn(GameState& game_state, Player* player, char marker);

  // Has the current player won (joined N pieces together)
  bool hasWon(const GameState& game_state) const;

  // Is the board full
	bool fullBoard(const GameState& game_state) const;
};
