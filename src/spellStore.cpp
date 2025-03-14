#include <vector>
#include <memory>
#include <string>

#include "spellStore.h"

SpellStore::SpellStore() {};
SpellStore::~SpellStore() {};

vector<std::shared_ptr<Spell>> SpellStore::starterSpells;
vector<std::shared_ptr<Spell>> SpellStore::beginnerSpells;
vector<std::shared_ptr<Spell>> SpellStore::intermediateSpells;
vector<std::shared_ptr<Spell>> SpellStore::advancedSpells;

void SpellStore::addSpell(shared_ptr<Spell> spell)
{
  if (spell->getSpellPower() == SpellPower::STARTER)
  {
    starterSpells.push_back(spell);
  }
  else if (spell->getSpellPower() == SpellPower::BEGINNER)
  {
    beginnerSpells.push_back(spell);
  }
  else if (spell->getSpellPower() == SpellPower::INTERMEDIATE)
  {
    intermediateSpells.push_back(spell);
  }
  else
  {
    advancedSpells.push_back(spell);
  }
};

void SpellStore::initializeDefaultSpells()
{
  addSpell(make_shared<Slash>());
  addSpell(make_shared<Mend>());
  addSpell(make_shared<RazorLeaves>());
  addSpell(make_shared<Bind>());
  addSpell(make_shared<Strangle>());
  addSpell(make_shared<StoneShower>());
  addSpell(make_shared<ThunderBolt>());
  addSpell(make_shared<WindBlast>());
  addSpell(make_shared<WaterBlast>());
  addSpell(make_shared<FireBlast>());
  addSpell(make_shared<ArrowShower>());
  addSpell(make_shared<Heal>());
  addSpell(make_shared<DragonFire>());
  addSpell(make_shared<LightningStike>());
  addSpell(make_shared<LifeSurge>());
  addSpell(make_shared<HealthTheft>());
};

const vector<shared_ptr<Spell>> &SpellStore::getStarterSpells()
{
  return starterSpells;
};

const vector<shared_ptr<Spell>> &SpellStore::getBeginnerSpells()
{
  return beginnerSpells;
};

const vector<shared_ptr<Spell>> &SpellStore::getIntermediateSpells()
{
  return intermediateSpells;
};

const vector<shared_ptr<Spell>> &SpellStore::getAdvancedSpells()
{
  return advancedSpells;
};
