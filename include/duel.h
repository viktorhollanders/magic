#ifndef DUEL_H
#define DUEL_H

#include <memory>
#include "character.h"
#include "spellStore.h"

class Duel
{
private:
  shared_ptr<Character> p1;
  shared_ptr<Character> p2;
  SpellStore &spellStore;
  int p1CurrentHealht;
  int p2CurrentHealht;
  int p1CurrentMana;
  int p2CurrentMana;
  bool duelFinished;

public:
  Duel(shared_ptr<Character> player1, shared_ptr<Character> player2, SpellStore &store);
  ~Duel();

  shared_ptr<Character> currentPlayer;
  shared_ptr<Character> currentTarget;

  void initializeDuel();
  void initialPlayer();
  void playRound();
  shared_ptr<Spell> choseSpell();
  void applySpellEffect(shared_ptr<Character> caster, shared_ptr<Character> target, shared_ptr<Spell> spell);
  bool checkDuelOver() const;
  void updateWinner(shared_ptr<Character> winner);
  void displayWinner();
  void switchPlayer(shared_ptr<Character> current);
};

#endif