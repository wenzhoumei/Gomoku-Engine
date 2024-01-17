#include "player.h"
#include <string>

class HumanPlayer: public Player {
public:
	void move(const GameState& game_state) override;

private:
	void prompt(const GameState& game_state) const;

	bool getCoords(int& x, int& y) const;
	bool inBounds(int x, int y) const;
	bool emptyCell(int x, int y, const GameState& game_state) const;

	std::string invalidReason;
};
