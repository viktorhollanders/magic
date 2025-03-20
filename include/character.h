#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <memory>
#include <vector>

#include "spell.h"

using namespace std;

class Character
{
private:
  string characterName;
  int health;
  int mana;
  int level;
  int levelUpCounter;
  int defense;
  vector<shared_ptr<Spell>> spellBook;

protected:
  const string type;

public:
  Character(string name, string type);
  virtual ~Character();

  // Getter methods for character
  string getType() const;
  string getName() const;
  int getHealth() const;
  int getMana() const;
  int getLevel() const;
  shared_ptr<Spell> getSpell(string spell);
  int spellCount() const;
  vector<shared_ptr<Spell>> &getSpellBook();
  int getLevelUpCointer();
  int getDefense();

  // Setters for character
  int takeDamage(int currentHealth, int damage);
  int heal(int currentHealth, int heal);
  void addMana(int amount);
  int spendMana(int currentMana, int mana);
  void levleUp(string stat);
  void addSpell(shared_ptr<Spell> spell);
  void setLevelUpCounter();
  void setDefense(int amount);

  // Getter methods for spells

  string displaySpellBook();
  string displayPlayerInfo();
};

class Mage : public Character
{
private:
  const string type;

public:
  Mage(string name);
  ~Mage();
};

#endif
