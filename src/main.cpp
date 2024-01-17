// REFACTOR SO PLAYER REFERS TO PLAYER CLASS
// HAVE GAME CLASS WHICH HAS A PLAYER1 AND A PLAYER2
#include <iostream>
#include <sstream>
#include <random>

const int BOARD_SIZE = 9;
const int N = 3;

enum Illegal { NONE, OUT_OF_BOUNDS, NON_EMPTY_CELL, INVALID_INPUT_FORMAT };

// Readable by bot to analyse position
struct GameState {
	int lastMove[2];

	Illegal illegal;

	char currentPlayer;
	int numMoves;
	char winner;

	char board[BOARD_SIZE][BOARD_SIZE];

	void turnReset() {
		illegal = NONE;
	}

	void gameStart() {
		lastMove[0] = -1;
		lastMove[1] = -1;

		illegal = NONE;
		currentPlayer = 'O';
		numMoves = 0;
		winner = '-';

		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				board[i][j] = '.';
			}
		}
	}

	void display() const {
		if (winner != '-') {
			std::cout << "Congratulations " << winner << " has won" << std::endl;
		} else {
			switch (illegal) {
				case OUT_OF_BOUNDS:
					std::cout << "out of bounds" << std::endl;
					break;
				case NON_EMPTY_CELL:
					std::cout << "empty cell" << std::endl;
				case INVALID_INPUT_FORMAT:
					std::cout << "invalid input format" << std::endl;
			}
		}

		std::cout << currentPlayer << std::endl;

		// Print column numbers
		std::cout << "  ";
		for (int j = 0; j < BOARD_SIZE; ++j) {
			std::cout << j << ' ';
		}
		std::cout << std::endl;

		for (int i = 0; i < BOARD_SIZE; ++i) {
			// Print row number
			std::cout << i << ' ';

			for (int j = 0; j < BOARD_SIZE; ++j) {
				std::cout << board[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
} gameState;

class Player {
public:
	Player(char stone)
		: stone(stone)
	{
	}

	char stone;
	virtual void move() = 0;

protected:
	void place(int x, int y) {
		if (inBounds(x, y) && emptyCell(x, y)) {
			gameState.numMoves++;

			gameState.board[x][y] = gameState.currentPlayer;
			
			if (isNInARow(x, y)) {
				gameState.winner = gameState.currentPlayer;
			}

			switchTurn();
		}
	}

private:
	bool isNInARow(int x, int y) {
		char player = gameState.currentPlayer;

		// Check horizontally
		int count = 0;
		for (int i = 0; i < BOARD_SIZE; ++i) {
			if (gameState.board[i][y] == player) {
				count++;
				if (count == N) return true;
			} else {
				count = 0;
			}
		}

		// Check vertically
		count = 0;
		for (int j = 0; j < BOARD_SIZE; ++j) {
			if (gameState.board[x][j] == player) {
				count++;
				if (count == N) return true;
			} else {
				count = 0;
			}
		}

		// Check diagonals
		count = 0;
		for (int i = std::max(0, x - N + 1), j = std::max(0, y - N + 1);
				i < BOARD_SIZE && j < BOARD_SIZE;
				++i, ++j) {
			if (gameState.board[i][j] == player) {
				count++;
				if (count == N) return true;
			} else {
				count = 0;
			}
		}

		count = 0;
		for (int i = std::min(x + N - 1, BOARD_SIZE - 1), j = std::max(0, y - N + 1);
				i >= 0 && j < BOARD_SIZE;
				--i, ++j) {
			if (gameState.board[i][j] == player) {
				count++;
				if (count == N) return true;
			} else {
				count = 0;
			}
		}

		return false;
	}

	void switchTurn() {
		if (gameState.currentPlayer == 'O') {
			gameState.currentPlayer = 'X';
		} else {
			gameState.currentPlayer = 'O';
		}
	}

	bool inBounds(int x, int y) {
		if (0 <= x && y < BOARD_SIZE && 0 <= y && y < BOARD_SIZE) {
			return true;
		}

		gameState.illegal = OUT_OF_BOUNDS;

		return false;
	}

	bool emptyCell(int x, int y) {
		if (gameState.board[x][y] == '.') {
			return true;
		}

		gameState.illegal = NON_EMPTY_CELL;

		return false;
	}
};

class HumanPlayer: public Player {
public:
	using Player::Player;

	void move() {
		std::string input;
		std::getline(std::cin, input);

		std::istringstream iss(input);
		int x, y;

		if (iss >> y >> x) {
			place(x, y);
		} else {
			gameState.illegal = INVALID_INPUT_FORMAT;
		}
	}
};

class BotPlayer: public Player {
public:
	using Player::Player;

	void move() {
		setWeights();

		int x, y;
		choseHighestWeightMove(x, y);

		place(x, y);
	}

private:
	void setWeights() {
		for (int i = 0; i < BOARD_SIZE; ++i) {
			for (int j = 0; j < BOARD_SIZE; ++j) {
				if (gameState.board[i][j] == '.') {
					potentialMovesWeights[i][j] = getRandomNumber(1, 1000);
				}
			}
		}
	}

	int getRandomNumber(int min, int max) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distribution(min, max);
		return distribution(gen);
	}

	void choseHighestWeightMove(int& x, int& y) {
		int maxWeight = -1;

		for (int i = 0; i < BOARD_SIZE; ++i) {
			for (int j = 0; j < BOARD_SIZE; ++j) {
				if (potentialMovesWeights[i][j] > maxWeight) {
					x = i;
					y = j;
				}
			}
		}
	}

	int potentialMovesWeights[BOARD_SIZE][BOARD_SIZE] = {0};
};

int main() {
	HumanPlayer player1('O');
	HumanPlayer player2('X');

	gameState.player1 = player1;
	gameState.player2 = player1;

	gameState.gameStart();

	gameState.display();

	while (true) {
		player1.move();
		gameState.display();

		if (gameState.winner != '-') {
			break;
		}

		gameState.turnReset();

		player2.move();
		gameState.display();

		if (gameState.winner != '-') {
			break;
		}

		gameState.turnReset();
	}

	return 0;
}
