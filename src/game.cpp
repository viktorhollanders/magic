#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <limits>

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

  newSpellStore = getSpellStore();
  newSpellStore.initializeDefaultSpells();
};

Game::~Game() {};

void Game::clearScrean()
{
  system(clearCommand.c_str());
}

int Game::getNumStarterSpells()
{
  return numStarterSpells;
}

SpellStore Game::getSpellStore()
{
  return newSpellStore;
}

void Game::createCharacter()
{
  string name;
  cout << "Enter your arcane title: ";
  cin >> name;

  shared_ptr<Character> character = make_shared<Mage>(name);

  players.push_back(character);

  cout << "Welcome " << character->getName() << endl;

  cout << "Now, behold the moment of destiny! Choose your spells with great wisdom, for your selection shall determine your fate!" << endl;
  auto beginnerSpellStore = newSpellStore.getStarterSpells();
  newSpellStore.choseSpells(character, beginnerSpellStore, numStarterSpells);

  cout << "MAGNIFICENT CHOICES, " << character->getName() << "!" << endl;
  cout << "These mighty incantations now reside in your arcane tome: ";

  cout << character->displaySpellBook() << endl;
  cout << endl;
}

void Game::addPlayers()
{
  for (int i = 0; i < numPlayers; i++)
  {
    createCharacter();
  }
}

void Game::duel()
{
  clearScrean();
  if (players.size() >= 2)
  {
    Duel duel(players[0], players[1], newSpellStore);

    duel.initializeDuel();

    while (!duel.checkDuelOver())
    {
      duel.playRound();
    }
    duel.displayWinner();
  }
}

void Game::gameOptions(bool &gameLoop)
{
  clearScrean();
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

  if (options[userChoice - 1] == "Quit")
  {
    gameLoop = false;
  }
  else
  {
    return;
  }
}