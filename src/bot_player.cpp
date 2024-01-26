
#include "../include/bot_player.h"

#include <ctime>
#include <iostream>

void RandomBotPlayer::move(GameState& game_state) {
    // Seed the random number generator
    std::srand(std::time(0));

    // Find the first empty position in a circular manner starting from a random point
    int start_index = std::rand() % (BOARD_SIZE * BOARD_SIZE);
    for (int k = 0; k < BOARD_SIZE * BOARD_SIZE; k++) {
        int index = (start_index + k) % (BOARD_SIZE * BOARD_SIZE);
        int i = index / BOARD_SIZE;
        int j = index % BOARD_SIZE;

        if (game_state.board[i][j] == '.') {
            game_state.board[i][j] = game_state.turnOf;
            return;
        }
    }
}

void SimpleBotPlayer::move(GameState& game_state) {
  GameState best_game_state;
  int max_score = -1;

  for (const GameState& gs: nextTurnStates(game_state)) {
    int score = evaluate(gs);

    if (score > max_score) {
      best_game_state = gs;
      max_score = score;
      //std::cout << score << std::endl;
    }
  }

  best_game_state.turnOf = game_state.turnOf;
  game_state = best_game_state;
}

std::vector<GameState> SimpleBotPlayer::nextTurnStates(const GameState& game_state) const {
  std::vector<GameState> ret;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
      if (game_state.board[i][j] == '.') {
        GameState new_state = game_state;
        new_state.board[i][j] = game_state.turnOf;
        new_state.turnOf = new_state.turnOf == PLAYER1_MARKER ? PLAYER2_MARKER : PLAYER1_MARKER;
        ret.push_back(new_state);
      }
		}
	}

  return ret;
}

int SimpleBotPlayer::getScore(int counter, bool player) const {
  if (counter == 0)
    return 0;

  int ret = 1;

  while (counter--) {
    ret *= 9;
  }

  return ret;
}

int SimpleBotPlayer::evaluate(const GameState& game_state) const {
  int centreScore = 0;

  if (game_state.board[BOARD_SIZE/2][BOARD_SIZE/2] != '.') {
    centreScore += 1;
  }

  int safeScore = 0;
  int threatScore = 0;

  int directions[][2] = {
    {1, 0},
    {0, 1},
    {1, 1},
    {-1, 1},
  };

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (game_state.board[i][j] == EMPTY_CELL) {
        for (int k = 0; k < 4; k++) {
          int playerCounter = 0;

          int i_exp = i;
          int j_exp = j;

          while (true) {
            i_exp += directions[k][0];
            j_exp += directions[k][1];

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE
               || game_state.board[i_exp][j_exp] != game_state.turnOf)
              break;

            playerCounter++;

            std::cout << "I: " << i << std::endl;
            std::cout << "J: " << j << std::endl;
          }

          i_exp = i;
          j_exp = j;

          while (true) {
            i_exp -= directions[k][0];
            j_exp -= directions[k][1];

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE
               || game_state.board[i_exp][j_exp] != game_state.turnOf)
              break;

            std::cout << "I: " << i_exp << std::endl;
            std::cout << "J: " << j << std::endl;
            playerCounter++;
          }

          safeScore += getScore(playerCounter, true);

          int opponentCounter = 0;
          char opponentMarker = game_state.turnOf == PLAYER1_MARKER ? PLAYER2_MARKER : PLAYER1_MARKER;

          i_exp = i;
          j_exp = j;

          while (true) {
            i_exp += directions[k][0];
            j_exp += directions[k][1];

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE)
              break;

            if (game_state.board[i_exp][j_exp] != opponentMarker)
              break;

            opponentCounter++;
          }

          i_exp = i;
          j_exp = j;

          while (true) {
            i_exp -= directions[k][0];
            j_exp -= directions[k][1];

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE)
              break;

            if (game_state.board[i_exp][j_exp] != opponentMarker)
              break;

            opponentCounter++;
          }

          threatScore += getScore(opponentCounter, true);
        }
      }
    }
  }


  game_state.display();
  std::cout << "SCORE: " << threatScore << std::endl;
  return 1000 -safeScore + threatScore + centreScore;
}
