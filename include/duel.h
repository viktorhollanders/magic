#ifndef DUEL_H
#define DUEL_H

#include <memory>
#include "character.h"

class Duel
{
private:
  shared_ptr<Character> p1;
  shared_ptr<Character> p2;
  int p1CurrentHelaht;
  int p2CurrentHelaht;
  bool duelFinished;
  void initialPlayer();

public:
  Duel(shared_ptr<Character> player1, shared_ptr<Character> player2);
  ~Duel();

  shared_ptr<Character> currentPlayer;
  shared_ptr<Character> currentTarget;

  void initializeDuel();
  void playRound();

  void switchPlayer(shared_ptr<Character> current);
  void applySpellEffect(shared_ptr<Character> caster, shared_ptr<Character> target, shared_ptr<Spell> spell);
  bool checkDuelOver();
  void applyDuelResults();
  shared_ptr<Character> getWinner();
};

#endif