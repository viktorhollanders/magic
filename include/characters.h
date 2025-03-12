#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

using namespace std;

class Character
{
  string type;
  string characterName;
  int health = 25;
  int level = 0;
public:
  Character(string type, string characterName) {
    this->type = type;
    this->characterName = characterName;
    this->level = level;
    this->health = health;
  };
  ~Character();

  // Getter methods
  string getType() const;
  string getName() const;
  string getLevel() const;
  string getHealth() const;

  // Setters
  void takeDamage(int amount);
  void heal(int amount);
  void levleUp();

  virtual void ability();
};

class Mage : public Character {
  Mage(string type, string name) : Character("Mage", name) {};
};

#endif