#include <memory>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

#include "character.h"
#include "game.h"
#include "spell.h"
#include "spellStore.h"
#include "duel.h"

using namespace std;

Game::Game()
{
#ifdef _WIN32
  clearCommand = "cls";
#else
  clearCommand = "clear";
#endif
};

Game::~Game() {};

void Game::clearScrean()
{
  system(clearCommand.c_str());
}

void Game::choseSpells(shared_ptr<Character> character)
{
  // get starter spells
  auto starterSpells = SpellStore::getStarterSpells();

  // show optoins
  for (int i = 0; i < numStarterSpells; i++)
  {

    cout << "You can chose one of these " << starterSpells.size() << " spells" << endl;
    for (int j = 0; j < starterSpells.size(); j++)
    {
      cout << j + 1 << "." << starterSpells[j]->getSpellName() << endl;
    }
    cout << "Pick a spell: ";
    int userChoice;
    cin >> userChoice;

    while (userChoice < 1 || userChoice > starterSpells.size() || cin.fail())
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
      cout << "Invalid option. Pleas enter a number between 1 and " << (starterSpells.size()) << endl;
      cout << "You can chose one of these " << starterSpells.size() << " spells" << endl;
      for (int j = 0; j < starterSpells.size(); j++)
      {
        cout << j + 1 << "." << starterSpells[j]->getSpellName() << endl;
      }
      cin >> userChoice;
    }

    // Add the spell to the mages spell book
    character->addSpell(starterSpells[userChoice - 1]);
    // Removes the spell that has been chosen
    starterSpells.erase(starterSpells.begin() + (userChoice - 1));
  }
}

void Game::createCharacter()
{
  string name;
  cout << "Reveal the arcane title that shall echo through the halls of wizardry: ";
  cin >> name;

  shared_ptr<Character> character = make_shared<Mage>(name);

  players.push_back(character);

  cout << "Welcome " << character->getName() << endl;

  cout << "Now, behold the moment of destiny! Choose your arcane powers with great wisdom, for your selection shall determine your fate!" << endl;
  choseSpells(character);

  cout << "MAGNIFICENT CHOICES, " << character->getName() << "!" << endl;
  cout << "These mighty incantations now reside in your arcane tome: ";

  cout << character->displaySpellBook() << endl;
  this_thread::sleep_for(std::chrono::seconds(3));
}

void Game::addPlayers()
{
  for (int i = 0; i < numPlayers; i++)
  {
    clearScrean();
    createCharacter();
  }
}

void Game::duel()
{
  clearScrean();
  cout << players.size() << endl;
  if (players.size() >= 2)
  {
    Duel duel(players[0], players[1]);

    duel.initializeDuel();

    while (!duel.checkDuelOver())
    {
      duel.playRound();
    }
    duel.displayWinner();
  }
}

void Game::gameOptions(bool gameLoop)
{

  vector<string> options = {"Play another tornument", "Quit"};

  cout << "Options: " << endl;
  for (int i = 0; i < 2; i++)
  {
    cout << i + 1 << ". " << options[i] << endl;
  }

  cout << "Chose: ";
  int userChoice;
  cin >> userChoice;

  while (userChoice < 1 || userChoice > options.size() || cin.fail())
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
    cout << "Invalid option. Pleas enter a number between 1 and " << (options.size()) << endl;
    cout << "Options: " << endl;
    for (int i = 0; i < 2; i++)
    {
      cout << i + 1 << ". " << options[i] << endl;
    }

    cout << "Chose: ";
    cin >> userChoice;
  }

  if (options[userChoice] == " quit")
  {
    gameLoop = false;
  }
  else
  {
    return;
  }
}