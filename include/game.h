#ifndef GAME_H
#define GAME_H

#include "spell.h"
#include "character.h"
#include "spellStore.h"

#include <memory>
#include <vector>
#include <string>

using namespace std;

class Game
{
private:
  const int numPlayers = 2;
  const int numStarterSpells = 3;
  string clearCommand;

  SpellStore newSpellStore;

protected:
  void choseSpells(shared_ptr<Character> character);
  void createCharacter();

public:
  vector<shared_ptr<Character>> players;
  Game();
  ~Game();

  // Clear screan
  void clearScrean();

  // Add players
  void addPlayers();
  int getNumStarterSpells();
  SpellStore getSpellStore();
  void gameOptions(bool &gameLoop);

  void startGame();
  void duel();
  void updatePlayer();
  void canPlayerUpdate();

  void saveGame();
  void loadGame();
};

#endif