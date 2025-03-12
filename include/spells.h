#ifndef SPELLS_H
#define SPELLS_H
#include <string>

using namespace std;

class Spell {
  protected:
    string spellName;
    int spellStrength;

  public:
    Spell(string name, int strength) {
      this->spellName = name;
      this->spellStrength = strength;
    };

    ~Spell();

    string getSpellName() const;
    string getSpellStrenght() const;

    virtual void spellEffect();
    void castSpell();
  };

// Spells

// Attack

class Slach : public Spell {
  Slach(string name, int strenght);
};

class Strangle : public Spell {
  Strangle(string name, int strenght);
};

class StoneShower : public Spell {
  StoneShower(string name, int strenght);
};

class WindBlast : public Spell {
  WindBlast(string name, int strenght);
};

class WaterBlast : public Spell {
  WaterBlast(string name, int strenght);
};

class ArrowShower : public Spell {
  ArrowShower(string name, int strenght);
};

class ThunderBolt : public Spell {
  ThunderBolt(string name, int strenght);
};

// healing
class Mend : public Spell {
  Mend(string name, int strenght);
};

class Heal : public Spell {
  Heal(string name, int strenght);
};

class LifeSurge : public Spell {
  LifeSurge(string name, int strenght);
};







#endif