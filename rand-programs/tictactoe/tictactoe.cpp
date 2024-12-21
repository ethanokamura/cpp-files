/*
  Ethan Okamura
  ethanokamura3@gmail.com
  CS19: Assignment 5
  Due 12/08/2022
  Classic TicTacToe game!

  A program that creates a 2 player console game of the iconic tictactoe.
  Players must play within the bounds of the box and cannot overlap sigils.
  First to get 3 in a row wins!
  If the box fills up with no win condition met then the game is over!
*/

#include <iostream>

class TicTacToe {
 public:
  TicTacToe();  // constructor
  void Play();

 private:
  char sigil[3];
  int board[9];
  int winner();
  void DrawBoard();
  bool isGameOver();
  bool isMoveLegal(int row, int column);
};

TicTacToe::TicTacToe() {
  for (int i = 0; i < 9; i++) board[i] = 0;
  sigil[0] = '.';
  sigil[1] = 'X';
  sigil[2] = 'O';
}

void TicTacToe::DrawBoard() {
  std::cout << "* 0 1 2\n";
  std::cout << "0 " << sigil[board[0]] << " " << sigil[board[1]] << " "
            << sigil[board[2]] << '\n';
  std::cout << "1 " << sigil[board[3]] << " " << sigil[board[4]] << " "
            << sigil[board[5]] << '\n';
  std::cout << "2 " << sigil[board[6]] << " " << sigil[board[7]] << " "
            << sigil[board[8]] << '\n';
}

bool TicTacToe::isMoveLegal(int row, int col) {
  if (row == 0) {
    if (col == 0 && board[0] == 0)
      return true;
    else if (col == 1 && board[1] == 0)
      return true;
    else if (col == 2 && board[2] == 0)
      return true;
    else
      return false;
  } else if (row == 1) {
    if (col == 0 && board[3] == 0)
      return true;
    else if (col == 1 && board[4] == 0)
      return true;
    else if (col == 2 && board[5] == 0)
      return true;
    else
      return false;
  } else if (row == 2) {
    if (col == 0 && board[6] == 0)
      return true;
    else if (col == 1 && board[7] == 0)
      return true;
    else if (col == 2 && board[8] == 0)
      return true;
    else
      return false;
  } else {
    return false;
  }
}

int TicTacToe::winner() {
  if (board[0] == board[4] && board[4] == board[8])
    return board[0];
  else if (board[2] == board[4] && board[4] == board[6])
    return board[2];
  else if (board[0] == board[1] && board[1] == board[2])
    return board[0];
  else if (board[3] == board[4] && board[4] == board[5])
    return board[3];
  else if (board[6] == board[7] && board[7] == board[8])
    return board[6];
  else if (board[0] == board[3] && board[3] == board[6])
    return board[0];
  else if (board[1] == board[4] && board[4] == board[7])
    return board[1];
  else if (board[2] == board[5] && board[5] == board[8])
    return board[2];
  else
    return 0;
}

bool TicTacToe::isGameOver() {
  if (winner() > 0) return true;
  for (int i = 0; i < 9; i++)
    if (board[i] == 0) return false;
  return true;
}

void TicTacToe::Play() {
  int row, col;
  int player = 2;
  bool legalMove = true;
  DrawBoard();
  while (!isGameOver()) {
    player == 1 ? player = 2 : player = 1;
    std::cout << sigil[player] << "'s turn:\n";
    std::cin >> row >> col;
    legalMove = isMoveLegal(row, col);
    while (!legalMove) {
      std::cout << sigil[player] << "'s turn:\n";
      std::cin >> row >> col;
      legalMove = isMoveLegal(row, col);
    }
    board[row * 3 + col] = player;
    DrawBoard();
  }
  winner() != 0 ? std::cout << sigil[player] << " wins! 🎉\n"
                : std::cout << "it's a draw 💀\n";
}

int main() {
  TicTacToe game;
  game.Play();
  return 0;
}
