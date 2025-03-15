#ifndef DUEL_H
#define DUEL_H

#include <memory>
#include "character.h"

class Duel
{
private:
  shared_ptr<Character> p1;
  shared_ptr<Character> p2;
  int p1CurrentHealht;
  int p2CurrentHealht;
  int p1CurrentMana;
  int p2CurrentMana;
  bool duelFinished;

  public:
  Duel(shared_ptr<Character> player1, shared_ptr<Character> player2);
  ~Duel();

  shared_ptr<Character> currentPlayer;
  shared_ptr<Character> currentTarget;

  void initializeDuel();
  void initialPlayer();
  void playRound();
  void applySpellEffect(shared_ptr<Character> caster, shared_ptr<Character> target, shared_ptr<Spell> spell);
  void switchPlayer(shared_ptr<Character> current);

  bool checkDuelOver() const;

  void applyDuelResults();
  shared_ptr<Character> getWinner();
};

#endif