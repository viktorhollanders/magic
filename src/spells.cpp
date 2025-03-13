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
Slash::Slash(string name, SpellPower power) : Spell("Slash", SpellPower::WEAK) {};

Strangle::Strangle(string name, SpellPower power) : Spell("Stranlge", SpellPower::WEAK) {};

StoneShower::StoneShower(string name, SpellPower power) : Spell("Stone shower", SpellPower::WEAK) {};

Mend::Mend(string name, SpellPower power) : Spell("Heal", SpellPower::WEAK) {};

ThunderBolt::ThunderBolt(string name, SpellPower power) : Spell("Thunder bolt", SpellPower::WEAK) {};

// Medium
WindBlast::WindBlast(string name, SpellPower power) : Spell("Wind blast", SpellPower::MEDIUM) {};

WaterBlast::WaterBlast(string name, SpellPower power) : Spell("Water blast", SpellPower::MEDIUM) {};

FireBlast::FireBlast(string name, SpellPower power) : Spell("Fire blast", SpellPower::MEDIUM) {};

// High
ArrowShower::ArrowShower(string name, SpellPower power) : Spell("Arrow shower", SpellPower::MEDIUM) {};


DragonFire::DragonFire(string name, SpellPower power) : Spell("Dragon Fire", SpellPower::HIGH) {};

LightningStike::LightningStike(string name, SpellPower power) : Spell("Dragon firle", SpellPower::HIGH) {} ;

Heal::Heal(string name, SpellPower power) : Spell("Heal", SpellPower::HIGH) {};







