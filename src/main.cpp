#include "spell.h"
#include "character.h"
#include "game.h"
#include <iostream>

using namespace std;

int main()
{
  Game newGame;
  newGame.clearScrean();
  SpellStore newStore;
  newStore.initializeDefaultSpells();

  newGame.addPlayers();

  newGame.duel();

  return 0;
}
