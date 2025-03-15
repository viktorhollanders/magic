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


  newGame.addPlayers();
  newGame.gameOptions(gameLoop);

  while (gameLoop)
  {
    newGame.duel();
    newGame.gameOptions(gameLoop);
  }

  return 0;
}
