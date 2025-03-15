#include "spell.h"
#include "character.h"
#include "game.h"
#include <iostream>

using namespace std;

bool gameLoop = true;

int main()
{
  Game newGame;
  newGame.clearScrean();
  SpellStore newStore;
  newStore.initializeDefaultSpells();

  newGame.addPlayers();

  while (gameLoop)
  {
    newGame.duel();
    newGame.gameOptions(gameLoop);
  }

  return 0;
}
