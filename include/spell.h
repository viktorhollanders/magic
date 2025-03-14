#ifndef SPELLS_H
#define SPELLS_H
#include <string>
#include <map>

using namespace std;

enum class SpellPower
{
  STARTER,
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
  Spell();
  Spell(string name, SpellPower spellPower, ManaCost mana);
  ~Spell();

  string getSpellName() const;
  SpellPower getSpellPower() const;
  ManaCost getSpellMana() const;

  virtual int calculatePower();
};

// SPELLS

// Starter spells
class Slash : public Spell
{
public:
  Slash();
  virtual ~Slash() {};
};

class Mend : public Spell
{
public:
  Mend();
  virtual ~Mend() {};
};

class RazorLeaves : public Spell
{
public:
  RazorLeaves();
  virtual ~RazorLeaves() {};
};

class Bind : public Spell
{
public:
  Bind();
  virtual ~Bind() {};
};

// Beginner
class Strangle : public Spell
{
public:
  Strangle();
  virtual ~Strangle() {};
};

class StoneShower : public Spell
{
public:
  StoneShower();
  virtual ~StoneShower() {};
};

class ThunderBolt : public Spell
{
public:
  ThunderBolt();
  virtual ~ThunderBolt() {};
};

// Intermediate

class WindBlast : public Spell
{
public:
  WindBlast();
  virtual ~WindBlast() {};
};

class WaterBlast : public Spell
{
public:
  WaterBlast();
  virtual ~WaterBlast() {};
};

class FireBlast : public Spell
{
public:
  FireBlast();
  virtual ~FireBlast() {};
};

class ArrowShower : public Spell
{
public:
  ArrowShower();
  virtual ~ArrowShower() {};
};

class Heal : public Spell
{
public:
  Heal();
  virtual ~Heal() {};
};

// Advanced
class DragonFire : public Spell
{
public:
  DragonFire();
  virtual ~DragonFire() {};
};

class LightningStike : public Spell
{
public:
  LightningStike();
  virtual ~LightningStike() {};
};

class LifeSurge : public Spell
{
public:
  LifeSurge();
  virtual ~LifeSurge() {};
};

class HealthTheft : public Spell
{
public:
  HealthTheft();
  virtual ~HealthTheft() {};
};

#endif