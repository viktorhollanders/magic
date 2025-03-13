#ifndef SPELLS_H
#define SPELLS_H
#include <string>
#include <map>

using namespace std;

enum class SpellPower {
  WEAK, MEDIUM, HIGH
};

struct Range {
  int min;
  int max;
};

class Spell {
  protected:
    string spellName;
    SpellPower spellPower;

    const map<SpellPower, Range> strenghtMap = {
      {SpellPower::WEAK, {0,5}},
      {SpellPower::MEDIUM, {6,12}},
      {SpellPower::HIGH, {13,20}}
    };


  public:
    Spell(string name, SpellPower spellPower) {
      this->spellName = name;
      this->spellPower = spellPower;
    };
    ~Spell();

    string getSpellName() const;
    SpellPower getSpellPower() const;

    virtual void spellEffect();
    virtual void calculatePower();
  };

// Spells

// Attack

class Slash : public Spell {
  Slash(string name, SpellPower spellPower);
};

class Strangle : public Spell {
  Strangle(string name, SpellPower spellPower);
};

class StoneShower : public Spell {
  StoneShower(string name, SpellPower spellPower);
};

class ThunderBolt : public Spell {
  ThunderBolt(string name, SpellPower spellPower);
};

class WindBlast : public Spell {
  WindBlast(string name, SpellPower spellPower);
};

class WaterBlast : public Spell {
  WaterBlast(string name, SpellPower spellPower);
};

class FireBlast : public Spell{
  FireBlast(string name, SpellPower spellPower);
};

class ArrowShower : public Spell {
  ArrowShower(string name, SpellPower spellPower);
};

class DragonFire : public Spell {
  DragonFire(string name, SpellPower spellPower);
};

class LightningStike : public Spell {
  LightningStike(string name , SpellPower spellPower);
};

// healing
class Mend : public Spell {
  Mend(string name, SpellPower spellPower);
};

class Heal : public Spell {
  Heal(string name, SpellPower spellPower);
};

class LifeSurge : public Spell {
  LifeSurge(string name, SpellPower spellPower);
};

class HealthTheft : public Spell{
  HealthTheft(string nema, SpellPower spellPower);
};

#endif