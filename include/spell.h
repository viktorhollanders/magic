#ifndef SPELLS_H
#define SPELLS_H
#include <string>
#include <map>

using namespace std;

enum class SpellPower
{
  BEGINNER,
  INTERMEDIATE,
  ADVANCED
};

enum class ManaCost
{
  ONE,
  TWO,
  THREE
};

struct Range
{
  int min;
  int max;
};

class Spell
{
protected:
  string spellName;
  SpellPower spellPower;
  ManaCost manaCost;

  const map<SpellPower, Range> strenghtMap = {
      {SpellPower::BEGINNER, {0, 5}},
      {SpellPower::INTERMEDIATE, {6, 12}},
      {SpellPower::ADVANCED, {13, 20}}};

  const map<ManaCost, int> manaMap = {
      {ManaCost::ONE, 1},
      {ManaCost::TWO, 2},
      {ManaCost::THREE, 3}};

public:
  Spell(string name, SpellPower spellPower, ManaCost mana)
  {
    this->spellName = name;
    this->spellPower = spellPower;
    this->manaCost = mana;
  };
  ~Spell();

  string getSpellName() const;
  SpellPower getSpellPower() const;

  virtual void spellEffect(); // NEED TO IMPLEMENT
  virtual void calculatePower();
};

// SPELLS

// Starter spells
class Slash : public Spell
{
  Slash(string name, SpellPower power, ManaCost mana);
};

class Mend : public Spell
{
  Mend(string name, SpellPower power, ManaCost mana);
};

class RazorLeaves : public Spell
{
  RazorLeaves(string name, SpellPower power, ManaCost mana);
};

class Bind : public Spell
{
  Bind(string name, SpellPower power, ManaCost mana);
};

// Beginner
class Strangle : public Spell
{
  Strangle(string name, SpellPower power, ManaCost mana);
};

class StoneShower : public Spell
{
  StoneShower(string name, SpellPower power, ManaCost mana);
};

class ThunderBolt : public Spell
{
  ThunderBolt(string name, SpellPower power, ManaCost mana);
};

// Intermediate

class WindBlast : public Spell
{
  WindBlast(string name, SpellPower power, ManaCost mana);
};

class WaterBlast : public Spell
{
  WaterBlast(string name, SpellPower power, ManaCost mana);
};

class FireBlast : public Spell
{
  FireBlast(string name, SpellPower power, ManaCost mana);
};

class ArrowShower : public Spell
{
  ArrowShower(string name, SpellPower power, ManaCost mana);
};

class Heal : public Spell
{
  Heal(string name, SpellPower power, ManaCost mana);
};

// Advanced
class DragonFire : public Spell
{
  DragonFire(string name, SpellPower power, ManaCost mana);
};

class LightningStike : public Spell
{
  LightningStike(string name, SpellPower power, ManaCost mana);
};

class LifeSurge : public Spell
{
  LifeSurge(string name, SpellPower power, ManaCost mana);
};

class HealthTheft : public Spell
{
  HealthTheft(string name, SpellPower power, ManaCost mana);
};

#endif