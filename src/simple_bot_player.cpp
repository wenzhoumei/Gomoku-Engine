#include "../include/simple_bot_player.h"

#include <limits>
#include <iostream>

void SimpleBotPlayer::move(GameState& game_state) {
  GameState best_game_state;
  int max_score = std::numeric_limits<int>::min();

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

// Gets how many pieces are threatening to connect
int SimpleBotPlayer::getThreatLength(const GameState& game_state, int directionX, int directionY, int x, int y, char marker) const {
          int playerCounter = 0;

          int i_exp = x;
          int j_exp = y;

          while (true) {
            i_exp += directionX;
            j_exp += directionY;

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE
               || game_state.board[i_exp][j_exp] != marker)
              break;

            playerCounter++;

            //std::cout << "I: " << i << std::endl;
            //std::cout << "J: " << j << std::endl;
          }

          i_exp = x;
          j_exp = y;

          while (true) {
            i_exp -= directionX;
            j_exp -= directionY;

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE
               || game_state.board[i_exp][j_exp] != marker)
              break;

            //std::cout << "I: " << i_exp << std::endl;
            //std::cout << "J: " << j << std::endl;
            playerCounter++;
          }

          return playerCounter;
}

bool SimpleBotPlayer::hasWon(const GameState& game_state) const {
  int directions[][2] = {
    {1, 0},
    {0, 1},
    {1, 1},
    {-1, 1},
  };

  char opp_marker = game_state.turnOf == PLAYER1_MARKER ? PLAYER2_MARKER : PLAYER1_MARKER;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      // Assumes only opponent can win
      if (game_state.board[i][j] == opp_marker) {
        for (int k = 0; k < 4; k++) {
          int counter = 1;

          int i_exp = i;
          int j_exp = j;

          while (true) {
            i_exp += directions[k][0];
            j_exp += directions[k][1];

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE)
              break;

            if (game_state.board[i_exp][j_exp] != opp_marker)
              break;

            counter++;
          }

          i_exp = i;
          j_exp = j;

          while (true) {
            i_exp -= directions[k][0];
            j_exp -= directions[k][1];

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE)
              break;

            if (game_state.board[i_exp][j_exp] != opp_marker)
              break;

            counter++;
          }

          if (counter >= N) {
            return true;
          }
        }
      }
    }
  }

  return false;
}

int SimpleBotPlayer::getScore(int threat_length, int multiplier, int weight) const {
  if (threat_length == 0)
    return 0;

  int ret = weight;

  while (threat_length--) {
    ret *= multiplier;
  }

  return ret;
}

int SimpleBotPlayer::evaluate(const GameState& game_state) const {
  if (hasWon(game_state))
    return std::numeric_limits<int>::max();

  int centre_score = 0;

  if (game_state.board[BOARD_SIZE/2][BOARD_SIZE/2] != '.') {
    centre_score += 1;
  }

  int their_threat_score = 0;
  int my_threat_score = 0;

  int directions[][2] = {
    {1, 0},
    {0, 1},
    {1, 1},
    {-1, 1},
  };

  int my_threats[N] = {0};
  int their_threats[N] = {0};

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (game_state.board[i][j] == EMPTY_CELL) {
        int max_their_threat_length = -1;
        int max_my_threat_length = -1;
        for (int k = 0; k < 4; k++) {
          int their_threat_length = getThreatLength(game_state, directions[k][0], directions[k][1], i, j, game_state.turnOf);
          if (their_threat_length > max_their_threat_length) {
            max_their_threat_length = their_threat_length;
          }

          int my_threat_length = getThreatLength(game_state, directions[k][0], directions[k][1], i, j, game_state.turnOf == PLAYER1_MARKER ? PLAYER2_MARKER : PLAYER1_MARKER);
          if (my_threat_length > max_my_threat_length) {
            max_my_threat_length = my_threat_length;
          }
        }

        my_threats[max_my_threat_length]++;
        their_threats[max_their_threat_length]++;

        their_threat_score += getScore(max_their_threat_length, 9, 2);
        my_threat_score += getScore(max_my_threat_length, 9, 1);
      }
    }
  }

  /*
  game_state.display();
    // Printing elements of my_threats
    std::cout << "my_threats: ";
    for (int i = 0; i < N; ++i) {
        std::cout << i << ": " << my_threats[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    // Printing elements of their_threats
    std::cout << "their_threats: ";
    for (int i = 0; i < N; ++i) {
        std::cout << i << ": " << their_threats[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    */

  //game_state.display();
  //std::cout << "SCORE: " << threatScore << std::endl;
  return -their_threat_score + my_threat_score + centre_score;
}
