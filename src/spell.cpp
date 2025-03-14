#include "spell.h"
#include <random>

using namespace std;

Spell::Spell() {};
Spell::Spell(string name, SpellPower spellPower, ManaCost manaCost)
{
  this->spellName = name;
  this->spellPower = spellPower;
  this->manaCost = manaCost;
};

Spell::~Spell() {};

string Spell::getSpellName() const
{
  return spellName;
}

SpellPower Spell::getSpellPower() const
{
  return spellPower;
}

ManaCost Spell::getSpellMana() const {
  return manaCost;
}

int Spell::calculatePower()
{
  SpellPower power = getSpellPower();
  random_device rd;
  mt19937 gen(rd());
  int minDamage = strenghtMap.at(power).min;
  int maxDamage = strenghtMap.at(power).max;
  uniform_int_distribution<> distrib(minDamage, maxDamage);
  int damage = distrib(gen);
  return damage;
}

// SPELLS
// Starter spells
Slash::Slash() : Spell("Slash", SpellPower::STARTER, ManaCost::ONE) {};

Mend::Mend() : Spell("Heal", SpellPower::STARTER, ManaCost::ONE) {};

RazorLeaves::RazorLeaves() : Spell("Razor leaves", SpellPower::STARTER, ManaCost::ONE) {};

Bind::Bind() : Spell("Bind", SpellPower::STARTER, ManaCost::ONE) {};

// Beginner
Strangle::Strangle() : Spell("Stranlge", SpellPower::BEGINNER, ManaCost::ONE) {};

StoneShower::StoneShower() : Spell("Stone shower", SpellPower::BEGINNER, ManaCost::ONE) {};

ThunderBolt::ThunderBolt() : Spell("Thunder bolt", SpellPower::BEGINNER, ManaCost::ONE) {};

// Intermediate
WindBlast::WindBlast() : Spell("Wind blast", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

WaterBlast::WaterBlast() : Spell("Water blast", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

FireBlast::FireBlast() : Spell("Fire blast", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

ArrowShower::ArrowShower() : Spell("Arrow shower", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

Heal::Heal() : Spell("Heal", SpellPower::INTERMEDIATE, ManaCost::TWO) {};

// Advanced
DragonFire::DragonFire() : Spell("Dragon Fire", SpellPower::ADVANCED, ManaCost::THREE) {};

LightningStike::LightningStike() : Spell("Dragon firle", SpellPower::ADVANCED, ManaCost::THREE) {};

LifeSurge::LifeSurge() : Spell("Life surge", SpellPower::ADVANCED, ManaCost::THREE) {};

HealthTheft::HealthTheft() : Spell("Helath theaft", SpellPower::ADVANCED, ManaCost::THREE) {};
