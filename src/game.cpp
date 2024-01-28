#include "../include/game.h"
#include <iostream>
#include <iomanip>

void Game::run(Player* player1, Player* player2) {
  GameState game_state;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      game_state.board[i][j] = EMPTY_CELL;
    }
  }

  run(game_state, player1, player2);
}

Player* Game::run(GameState game_state, Player* player1, Player* player2) {
  while (true) {
    int turnRes = playTurn(game_state, player1, PLAYER1_MARKER);
    if (turnRes == 1) {
      return player1;
    } else if (turnRes == 2) {
      return nullptr;
    }

    turnRes = playTurn(game_state, player2, PLAYER2_MARKER);
    if (turnRes == 1) {
      return player2;
    } else if (turnRes == 2) {
      return nullptr;
    }
  }
}

// return
// 	0 -> continue
// 	1 -> player has won
// 	2 -> draw
int Game::playTurn(GameState& game_state, Player* player, char marker) {
  game_state.turnOf = marker;

  //std::cout << "------" << player->identity() << "-------" << std::endl;
  std::cout << "--------" << std::setw(20) << std::setfill('-') << std::left << player->identity() << std::endl;

  game_state.display();
  player->move(game_state);

  if (hasWon(game_state)) {
    std::cout << "----------------------------" << std::endl;
    std::cout << game_state.turnOf << " (" << player->identity() << ")" << " has won!" << std::endl;
    game_state.turnOf = '-';
    game_state.display();
    return 1;
  }

  if (fullBoard(game_state)) {
    std::cout << "----------------------------" << std::endl;
    std::cout << "It is a draw" << std::endl;
    game_state.turnOf = '-';
    game_state.display();
    return 2;
  }

  return 0;
}

bool Game::hasWon(const GameState& game_state) const {
  int directions[][2] = {
    {1, 0},
    {0, 1},
    {1, 1},
    {-1, 1},
  };

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      // Assumes only turnOf can win
      if (game_state.board[i][j] == game_state.turnOf) {
        for (int k = 0; k < 4; k++) {
          int counter = 1;

          int i_exp = i;
          int j_exp = j;

          while (true) {
            i_exp += directions[k][0];
            j_exp += directions[k][1];

            if (i_exp < 0 || i_exp >= BOARD_SIZE || j_exp < 0 || j_exp >= BOARD_SIZE)
              break;

            if (game_state.board[i_exp][j_exp] != game_state.turnOf)
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

            if (game_state.board[i_exp][j_exp] != game_state.turnOf)
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

bool Game::fullBoard(const GameState& game_state) const {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (game_state.board[i][j] == EMPTY_CELL) {
        return false;
      }
    }
  }

  return true;
}
