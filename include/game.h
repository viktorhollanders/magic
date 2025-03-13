#ifndef GAME_H
#define GAME_H

#include "character.h"

#include <memory>
#include <vector>

using namespace std;

class Game {
  private:
  const int numPlayers = 2;
  const int numSpells = 3;

  protected:
    vector<shared_ptr<Character>> players;

  public:
    Game();
    ~Game();

    // Add players
    void createCharacter();
    void choseSpells(shared_ptr<Character> character);
    void addPlayers();

    void startGame();
    void duel();
    void updatePlayer();

    void saveGame();
    void loadGame();
};

#endif