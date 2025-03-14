#ifndef SPELL_STORE_H
#define SPELL_STORE_H

#include <vector>
#include <memory>
#include <string>

#include "spell.h"

using namespace std;

class SpellStore
{
private:
  static vector<shared_ptr<Spell>> starterSpells;
  static vector<shared_ptr<Spell>> beginnerSpells;
  static vector<shared_ptr<Spell>> intermediateSpells;
  static vector<shared_ptr<Spell>> advancedSpells;

public:
  SpellStore();
  ~SpellStore();

  void initializeDefaultSpells();
  void addSpell(shared_ptr<Spell> spell);
  shared_ptr<Spell> getSpellByName(const string &name);

  static const vector<shared_ptr<Spell>> &getStarterSpells();
  static const vector<shared_ptr<Spell>> &getBeginnerSpells();
  static const vector<shared_ptr<Spell>> &getIntermediateSpells();
  static const vector<shared_ptr<Spell>> &getAdvancedSpells();
};

#endif