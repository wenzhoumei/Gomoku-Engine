#include "player.h"

class Game {
public:
	void run(Player* player1, Player* player2, char player1_marker, char player2_marker);
	Player* run(GameState game_state, Player* player1, Player* player2, char player1_marker, char player2_marker);

private:
	int playTurn(GameState& game_state, Player* player, char marker);

  bool hasWon(const GameState& game_state) const;
	bool fullBoard(const GameState& game_state) const;

	GameState gameState;
};
