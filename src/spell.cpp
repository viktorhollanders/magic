#include "spell.h"
#include "utils.h"

Spell::Spell() {};
Spell::Spell(string name, SpellPower spellPower, ManaCost manaCost, SpellType spellType)
{
  this->spellName = name;
  this->spellPower = spellPower;
  this->manaCost = manaCost;
  this->spellType = spellType;
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

SpellType Spell::getSpellType() const
{
  return spellType;
};

int Spell::calculatePower()
{
  SpellPower power = getSpellPower();

  auto it = strenghtMap.find(power);
  int minPower = it->second.min;
  int maxPower = it->second.max;

  return generateRandomNum(minPower, maxPower);
}

// SPELLS
// Starter spells
Slash::Slash() : Spell("Slash", SpellPower::STARTER, ManaCost::ONE, SpellType::ATTACK) {};

Mend::Mend() : Spell("Heal", SpellPower::STARTER, ManaCost::ONE, SpellType::HEAL) {};

RazorLeaves::RazorLeaves() : Spell("Razor leaves", SpellPower::STARTER, ManaCost::ONE, SpellType::ATTACK) {};

Bind::Bind() : Spell("Bind", SpellPower::STARTER, ManaCost::ONE, SpellType::DEFENSE) {};

// Beginner
Strangle::Strangle() : Spell("Stranlge", SpellPower::BEGINNER, ManaCost::ONE, SpellType::ATTACK) {};

StoneShower::StoneShower() : Spell("Stone shower", SpellPower::BEGINNER, ManaCost::ONE, SpellType::ATTACK) {};

ThunderBolt::ThunderBolt() : Spell("Thunder bolt", SpellPower::BEGINNER, ManaCost::ONE, SpellType::ATTACK) {};

// Intermediate
WindBlast::WindBlast() : Spell("Wind blast", SpellPower::INTERMEDIATE, ManaCost::TWO, SpellType::ATTACK) {};

WaterBlast::WaterBlast() : Spell("Water blast", SpellPower::INTERMEDIATE, ManaCost::TWO, SpellType::ATTACK) {};

FireBlast::FireBlast() : Spell("Fire blast", SpellPower::INTERMEDIATE, ManaCost::TWO, SpellType::ATTACK) {};

ArrowShower::ArrowShower() : Spell("Arrow shower", SpellPower::INTERMEDIATE, ManaCost::TWO, SpellType::ATTACK) {};

Heal::Heal() : Spell("Heal", SpellPower::INTERMEDIATE, ManaCost::TWO, SpellType::HEAL) {};

// Advanced
DragonFire::DragonFire() : Spell("Dragon Fire", SpellPower::ADVANCED, ManaCost::THREE, SpellType::ATTACK) {};

LightningStike::LightningStike() : Spell("Dragon firle", SpellPower::ADVANCED, ManaCost::THREE, SpellType::ATTACK) {};

LifeSurge::LifeSurge() : Spell("Life surge", SpellPower::ADVANCED, ManaCost::THREE, SpellType::HEAL) {};

HealthTheft::HealthTheft() : Spell("Helath theaft", SpellPower::ADVANCED, ManaCost::THREE, SpellType::HEAL) {};
