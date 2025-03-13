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
  int health;
  int mana;
  int level;
  vector<shared_ptr<Spell>> spellBook;

public:
  Character(string type, string characterName) {
    this->type = type;
    this->characterName = characterName;
    this->health = health;
    this->mana = mana;
    this->level = level;
    this->spellBook = spellBook;
  };
  ~Character();

  // Getter methods for character
  string getType() const;
  string getName() const;
  int getHealth() const;
  int getMana() const;
  int getLevel() const;

  // Setters for character
  void takeDamage(int amount);
  void heal(int amount);
  void addMana(int amount);
  void spendMana(int amount);
  void levleUp();

  // Getter methods for spells
  int spellCount() const;
  void addSpell(shared_ptr<Spell> spell);
  Spell* getSpell(string spell);


  void displaySpellBood() const;

  virtual void ability();
};

class Mage : public Character {
  public:
    Mage(string type, string name);
    void ability() override;
};

#endif