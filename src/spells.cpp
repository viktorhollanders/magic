#include "spells.h"
#include <random>

using namespace std;

random_device rd;

Spell::Spell(string spellName, SpellPower spellPower) {};

string Spell::getSpellName() const {
  return spellName;
}

SpellPower Spell::getSpellPower() const {
  return spellPower;
}

void Spell::calculatePower () {
  SpellPower power = getSpellPower();
  mt19937 gen(rd);
  int minDamage = strenghtMap.at(power).min;
  int maxDamage = strenghtMap.at(power).max;
  uniform_int_distribution<> distrib(minDamage, maxDamage);
  int damage = distrib(gen);
}

// Spells
// Weak

