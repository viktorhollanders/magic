#include <string>
#include "character.h"

using namespace std;

Character::Character(string characterName, string type) : characterName(characterName), health(35), mana(10), level(0), levelUpCounter(0), defense(0), type(type) {};

Character::~Character() {}

// Character getters
string Character::getType() const
{
  return type;
}

string Character::getName() const
{
  return characterName;
}

int Character::getHealth() const
{
  return health;
}

int Character::getMana() const
{
  return mana;
}

int Character::getLevel() const
{
  return level;
}

shared_ptr<Spell> Character::getSpell(string spell)
{
  for (const auto &spellPtr : spellBook)
  {
    if (spellPtr->getSpellName() == spell)
    {
      return spellPtr;
    }
  }
  return nullptr;
}

int Character::spellCount() const
{
  return spellBook.size();
}

vector<shared_ptr<Spell>> &Character::getSpellBook()
{
  return spellBook;
};

int Character::getLevelUpCointer()
{
  return levelUpCounter;
}

int Character::getDefense()
{
  return defense;
}

// Character setters
int Character::takeDamage(int currentHealth, int damage)
{
  int newHealth = currentHealth - damage;
  if (newHealth < 0)
    newHealth = 0;
  return newHealth;
}

int Character::heal(int currentHealth, int heal)
{
  return currentHealth + heal;
}

void Character::addMana(int amount)
{
  mana += amount;
}

int Character::spendMana(int currentMana, int mana)
{
  int newMana = currentMana - mana;
  if (newMana < 0)
    newMana = 0;
  return newMana;
}

void Character::levleUp(string stat)
{
  if (stat == "health")
  {
    health += 1;
  }
  if (stat == "mana")
  {
    mana += 1;
  }
  if (stat == "level")
  {
    level += 1;
  }
}

void Character::addSpell(shared_ptr<Spell> spell)
{
  spellBook.push_back(spell);
}

void Character::setLevelUpCounter()
{
  levelUpCounter += 1;
}

void Character::setDefense(int amount)
{
  defense = amount;
}

// Display methods

string Character::displaySpellBook()
{
  string spells;

  for (int i = 0; i < spellBook.size(); i++)
  {
    if (i == spellBook.size() - 1)
    {
      spells += spellBook[i]->getSpellName();
    }
    else
    {
      spells += spellBook[i]->getSpellName();
      spells += ", ";
    }
  }

  return spells;
}

string Character::displayPlayerInfo()
{
  string playerStats;
  playerStats += characterName + "\n";
  playerStats += "Spell count: " + to_string(spellCount()) + "\n";
  playerStats += "Spells: " + displaySpellBook() + "\n";
  playerStats += "Health: " + to_string(getHealth()) + "\n";
  playerStats += "Level: " + to_string(getLevel()) + "\n";
  playerStats += "Mana: " + to_string(getMana()) + "\n";
  playerStats += "------------------------";

  return playerStats;
}

// Mage
Mage::Mage(string name) : Character(name, "Mage") {};
Mage::~Mage() {};
