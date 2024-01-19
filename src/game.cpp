#include "../include/game.h"
#include <iostream>
#include <iomanip>

void Game::run(Player* player1, Player* player2, char player1_marker, char player2_marker) {
  GameState game_state;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      game_state.board[i][j] = EMPTY_CELL;
    }
  }

  run(game_state, player1, player2, player1_marker, player2_marker);
}

Player* Game::run(GameState game_state, Player* player1, Player* player2, char player1_marker, char player2_marker) {
  while (true) {
    int turnRes = playTurn(game_state, player1, player1_marker);
    if (turnRes == 1) {
      return player1;
    } else if (turnRes == 2) {
      return nullptr;
    }

    turnRes = playTurn(game_state, player2, player2_marker);
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

  /*
     if (hasWon(game_state)) {
     std::cout << game_state.turnOf << " has won!" << std::endl;
     display();
     return 1;
     }
     */

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
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (game_state.board[i][j] == EMPTY_CELL) {
        return false;
      }
    }
  }

  return true;
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
