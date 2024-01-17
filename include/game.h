#include "player.h"

class Game {
public:
	void initialize(Player* player1, Player* player2);
	void run();

private:
	GameState gameState;

	Player* player1;
	Player* player2;

	const char player1Marker = 'O';
	const char player2Marker = 'X';
};
