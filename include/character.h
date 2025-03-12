#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <memory>
#include <vector>

#include "spells.h"

using namespace std;

class Character
{
  string type;
  string characterName;
  int health = 25;
  int energy = 10;
  int level = 0;
  vector<shared_ptr<Spell>> spellBook;

public:
  Character(string type, string characterName) {
    this->type = type;
    this->characterName = characterName;
    this->health = health;
    this->energy = energy;
    this->level = level;
  };
  ~Character();

  // Getter methods for character
  string getType() const;
  string getName() const;
  string getHealth() const;
  string getEnergy() const;
  string getLevel() const;

  // Setters for character
  void takeDamage(int amount);
  void heal(int amount);
  void spendEnergy(int amount);
  void levleUp();

  // Getter methods for spells
  int spellCount() const;
  void addSpell();
  Spell* getSepll();

  void displaySpellBood();

  virtual void ability() const;
};

class Mage : public Character {
  Mage(string type, string name) : Character("Mage", name) {};
};

#endif