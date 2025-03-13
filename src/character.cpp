#include "character.h"
#include <string>

using namespace std;

Character::Character(string characterName, string type) : type(type), characterName(characterName), health(35), mana(10), level(0) {};

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

void Character::takeDamage(int amount)
{
  health -= amount;
}

void Character::heal(int amount)
{
  health += amount;
}

void Character::spendMana(int amount)
{
  mana -= amount;
}

void Character::addMana(int amount)
{
  mana += amount;
}

int Character::spellCount() const
{
  return spellBook.size();
}

void Character::addSpell(shared_ptr<Spell> spell)
{
  spellBook.push_back(spell);
}

Spell* Character::getSpell(string castSpell)
{
  for (const auto &spellPtr : spellBook)
  {
    if (spellPtr->getSpellName() == castSpell)
    {
      return spellPtr.get();
    }
  }
  return nullptr;
}

// Creatures
Mage::Mage(string name) : Character(name, "Mage") {}

void Mage::ability()
{
  addMana(5);
}
