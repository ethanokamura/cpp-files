#include <iostream>

class Player {
 public:
  Player() {  // Constructor
    _hp = 10;
    _spd = 5.5;
    _dmg = 3;
  };

  double CheckHealth() { return _hp; }
  double CheckSpeed() { return _spd; }
  int CheckDamage() { return _dmg; }

  void TakeDamage(int dmg) {
    _hp -= dmg;
  }

 private:
  double _hp, _spd, _dmg;
};

int main() {
  Player p;
  double hp = p.CheckHealth();
  double spd = p.CheckSpeed();
  int dmg =  p.CheckDamage();

  std::cout << "Player stats: \n" 
  << "Health: " << hp << '\n'
  << "Speed: " << spd << '\n'
  << "Damage: " << dmg << '\n';
  
  int damage = 5;
  p.TakeDamage(damage);
  hp = p.CheckHealth();
  std::cout << "Player got hit for: " << damage <<
  "damage! They now have: " << hp << " health\n";
}