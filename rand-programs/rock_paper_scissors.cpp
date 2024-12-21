#include <time.h>

#include <cstdlib>
#include <iostream>

// 0 == tie; 1 == player; -1 == cpu;
int check_conditions(std::string player, std::string cpu) {
  if (player == cpu) return 0;
  if ((player == "rock" && cpu == "scissors") ||
      (player == "paper" && cpu == "rock") ||
      (player == "scissors" && cpu == "paper"))
    return 1;
  return -1;
}

int main() {
  srand(time(0));

  int num_games;

  std::cout << "best of?\n";
  std::cin >> num_games;

  bool is_playing = true;
  std::string options[] = {"rock", "paper", "scissors"};

  int player_score = 0;
  int cpu_score = 0;

  while (is_playing) {
    std::string cpu_choice = options[rand() % 3];
    std::string player_choice;
    std::cout << "rock, paper, or scissors?\n";
    std::cin >> player_choice;
    int winner = check_conditions(player_choice, cpu_choice);
    if (winner == 1) {
      player_score++;
      std::cout << "player wins round!\n";
    } else if (winner == -1) {
      cpu_score++;
      std::cout << "cpu wins round!\n";
    } else {
      std::cout << "tied round\n";
    }
    std::cout << "player's score: " << player_score
              << ", computer's score: " << cpu_score << '\n';
    if (player_score == num_games / 2 + 1) {
      std::cout << "player wins! GG\n";
      is_playing = false;
    } else if (cpu_score == num_games / 2 + 1) {
      std::cout << "cpu wins! GG\n";
      is_playing = false;
    }
  }
  std::cout << "thanks for playing!\n";
  return 0;
}
