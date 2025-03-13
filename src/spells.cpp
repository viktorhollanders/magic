#include "spells.h"
#include <random>

using namespace std;

random_device rd;

Spell::Spell(string spellName, SpellPower spellPower, ManaCost mana) {};

string Spell::getSpellName() const
{
  return spellName;
}

SpellPower Spell::getSpellPower() const
{
  return spellPower;
}

void Spell::calculatePower()
{
  SpellPower power = getSpellPower();
  mt19937 gen(rd);
  int minDamage = strenghtMap.at(power).min;
  int maxDamage = strenghtMap.at(power).max;
  uniform_int_distribution<> distrib(minDamage, maxDamage);
  int damage = distrib(gen);
}

// SPELLS
// Starter spells
Slash::Slash(string name, SpellPower power, ManaCost mana) : Spell("Slash", SpellPower::BEGINNER, ManaCost::ONE) {};

Mend::Mend(string name, SpellPower power, ManaCost mana) : Spell("Heal", SpellPower::BEGINNER, ManaCost::ONE) {};

RazorLeaves::RazorLeaves(string name, SpellPower power, ManaCost mana) : Spell("Razor leaves", SpellPower::BEGINNER, ManaCost::ONE) {};

Bind::Bind(string name, SpellPower power, ManaCost mana) : Spell("Bind", SpellPower::BEGINNER, ManaCost::ONE) {};

// Beginner
Strangle::Strangle(string name, SpellPower power, ManaCost mana) : Spell("Stranlge", SpellPower::BEGINNER, ManaCost::ONE) {};

StoneShower::StoneShower(string name, SpellPower power, ManaCost mana) : Spell("Stone shower", SpellPower::BEGINNER, ManaCost::ONE) {};

ThunderBolt::ThunderBolt(string name, SpellPower power, ManaCost mana) : Spell("Thunder bolt", SpellPower::BEGINNER, ManaCost::ONE) {};

// Intermediate
WindBlast::WindBlast(string name, SpellPower power, ManaCost mana) : Spell("Wind blast", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

WaterBlast::WaterBlast(string name, SpellPower power, ManaCost mana) : Spell("Water blast", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

FireBlast::FireBlast(string name, SpellPower power, ManaCost mana) : Spell("Fire blast", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

ArrowShower::ArrowShower(string name, SpellPower power, ManaCost mana) : Spell("Arrow shower", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

Heal::Heal(string name, SpellPower power, ManaCost mana) : Spell("Heal", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

// Advanced
DragonFire::DragonFire(string name, SpellPower power, ManaCost mana) : Spell("Dragon Fire", SpellPower::ADVANCED, ManaCost::THREE) {};

LightningStike::LightningStike(string name, SpellPower power, ManaCost mana) : Spell("Dragon firle", SpellPower::ADVANCED, ManaCost::THREE) {};

LifeSurge::LifeSurge(string name, SpellPower power, ManaCost mana) : Spell("Life surge", SpellPower::ADVANCED, ManaCost::THREE) {};

HealthTheft::HealthTheft(string name, SpellPower power, ManaCost mana) : Spell("Helath theaft", SpellPower::ADVANCED, ManaCost::THREE) {};
