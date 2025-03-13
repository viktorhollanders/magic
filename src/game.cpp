#include <memory>
#include <memory>
#include <vector>
#include <string>
#include <iostream>

#include "character.h"
#include "game.h"
#include "spell.h"

using namespace std;

void Game::choseSpells(shared_ptr<Character> character) {
  // get starter spells

  // show optoins
  // needs to be a refference or new instance?
  // remove the one that has been chosen.

  shared_ptr<Spell> chosenSpell;
  
  for (int i = 0; i < Game::numSpells; i++) {
    character->addSpell(chosenSpell);
  }
}

void Game::createCharacter()
{
  string name;
  cin >> name;

  Mage mage(name);

  players.push_back(make_shared<Mage>(mage));

  cout << "Welcome " << mage.getName() << endl;
  cout << "You will be a grate " << mage.getType() << endl;
  cout << "Here are your current stats " << endl;
  cout << "Health: " << mage.getHealth() << endl;
  cout << "Mana: " << mage.getMana() << endl;
  cout << "Level: " << mage.getLevel() << endl;

  cout << "Now, behold the moment of destiny! Choose your arcane powers with great wisdom, for your selection shall determine your fate!" << endl;
  // chose spells
}

void Game::addPlayers()
{
  for (int i = 0; i < Game::numPlayers; i++)
  {
    Game::addPlayers();
  }
}

