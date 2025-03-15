#include <vector>
#include <memory>
#include <string>
#include <iostream>

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

void SpellStore::displaySpellBookByLevels(int numTiers)
{
  vector<string> options = {"Beginner spells", "Intermediate spells", "Advanced spells"};

  cout << "Chose the spell tier you want to view: " << endl;

  for (int i = 0; i < numTiers; i++)
  {
    cout << i + 1 << ". " << options[i] << endl;
  }
}

vector<shared_ptr<Spell>> SpellStore::selectSpellTeir(int numTiers)
{
  vector<string> options = {"Beginner spells", "Intermediate spells", "Advanced spells"};
  cout << "Pick a tier: ";
  int userChoice;
  cin >> userChoice;

  while (userChoice < 1 || userChoice > numTiers || cin.fail())
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
      cin.ignore();
    }
    cout << "Invalid option." << endl;
    cout << "You can chose one of these " << numTiers << " spells" << endl;
    displaySpellBookByLevels(numTiers);
    cin >> userChoice;
  }

  if (options[userChoice - 1] == "Advanced spells")
  {
    return getAdvancedSpells();
  }
  if (options[userChoice - 1] == "Intermediate spells")
  {
    return getIntermediateSpells();
  }
  if (options[userChoice - 1] == "Beginner spells")
  {
    return getBeginnerSpells();
  }
  return getBeginnerSpells();
};

void SpellStore::choseSpells(shared_ptr<Character> character, const vector<shared_ptr<Spell>> &selectedSpellTier, int numChoises)
{

  vector<shared_ptr<Spell>> spellTier = selectedSpellTier;

  // show optoins
  for (int i = 0; i < numChoises; i++)
  {

    cout << "You can chose one of these " << starterSpells.size() << " spells" << endl;
    for (int j = 0; j < spellTier.size(); j++)
    {
      cout << j + 1 << ". " << spellTier[j]->getSpellName() << endl;
    }
    cout << "Pick a spell: ";
    int userChoice;
    cin >> userChoice;

    while (userChoice < 1 || userChoice > spellTier.size() || cin.fail())
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      else
      {
        cin.ignore();
      }
      cout << "Invalid option. Pleas enter a number between 1 and " << (spellTier.size()) << endl;
      cout << "You can chose one of these " << spellTier.size() << " spells" << endl;
      for (int j = 0; j < spellTier.size(); j++)
      {
        cout << j + 1 << "." << spellTier[j]->getSpellName() << endl;
      }
      cin >> userChoice;
    }

    // Add the spell to the mages spell book
    character->addSpell(spellTier[userChoice - 1]);
    // Removes the spell that has been chosen
    spellTier.erase(spellTier.begin() + (userChoice - 1));
  }
}

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
