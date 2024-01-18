#include "player.h"

class Game {
public:
	void run(Player* player1, Player* player2, char player1_marker, char player2_marker);
	void run(GameState game_state, Player* player1, Player* player2, char player1_marker, char player2_marker);

private:
	bool fullBoard(const GameState& game_state) const;

	void display(const GameState& game_state) const;

	GameState gameState;
};
