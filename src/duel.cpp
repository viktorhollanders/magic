#include <iostream>
#include <random>

#include "duel.h"
#include "character.h"
#include "spell.h"
#include "utils.h"

Duel::Duel(shared_ptr<Character> player1, shared_ptr<Character> player2) : p1(player1), p2(player2) {};
Duel::~Duel() {};

void Duel::initialPlayer()
{

  int num = generateRandomNum(1, 2);
  currentPlayer = (num == 1) ? p1 : p2;
  currentTarget = (currentPlayer == p1) ? p2 : p1;
};

void Duel::initializeDuel()
{
  p1CurrentHealht = p1->getHealth();
  p2CurrentHealht = p2->getHealth();

  p1CurrentMana = p1->getMana();
  p2CurrentMana = p2->getMana();

  duelFinished = false;

  cout << "A duel starts between these wizards!" << endl;
  cout << p1->displayPlayerInfo() << endl;
  cout << "==VS==" << endl;
  cout << p2->displayPlayerInfo() << endl;

  initialPlayer();
}

shared_ptr<Spell> Duel::choseSpell()
{
  auto playerSpellBook = currentPlayer->getSpellBook();
  string chosenSpellName;
  shared_ptr<Spell> chosenSpell;

  cout << "== " << currentPlayer->getName() << " turn ==" << endl;
  cout << "Available spells: " << endl;
  for (int i = 0; i < playerSpellBook.size(); i++)
  {
    cout << i + 1 << ". " << playerSpellBook[i]->getSpellName() << endl;
  }

  cout << "Chose your spell: " << endl;
  int userChoice;
  cin >> userChoice;

  while (userChoice < 1 || userChoice > playerSpellBook.size() || cin.fail())
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
    cout << "Invalid option. Pleas enter a number between 1 and " << (playerSpellBook.size()) << endl;
    cout << "You can chose one of these " << playerSpellBook.size() << " spells" << endl;

    for (int i = 0; i < playerSpellBook.size(); i++)
    {
      cout << i + 1 << ". " << playerSpellBook[i]->getSpellName() << endl;
    }
    cin >> userChoice;
  }

  chosenSpellName = playerSpellBook[userChoice - 1]->getSpellName();

  return chosenSpell = currentPlayer->getSpell(chosenSpellName);
}

void Duel::applySpellEffect(shared_ptr<Character> caster, shared_ptr<Character> target, shared_ptr<Spell> spell)
{
  int &targetHealth = (target == p1) ? p1CurrentHealht : p2CurrentHealht;

  int spellPower = spell->calculatePower();

  targetHealth = target->takeDamage(targetHealth, spellPower);

  cout << caster->getName() << " casts " << spell->getSpellName()
       << "with power: " << spellPower << " on " << target->getName() << "!" << endl;
};

void Duel::playRound()
{
  shared_ptr<Spell> spell = choseSpell();

  applySpellEffect(currentPlayer, currentTarget, spell);

  cout << p1CurrentHealht << endl;
  cout << p2CurrentHealht << endl;

  if (p1CurrentHealht == 0 || p2CurrentHealht == 0)
  {
    duelFinished = true;
  }

  if (!checkDuelOver())
  {
    switchPlayer(currentPlayer);
  }
}

bool Duel::checkDuelOver() const
{
  return duelFinished;
};

void Duel::switchPlayer(shared_ptr<Character> current)
{
  currentPlayer = (current == p1) ? p2 : p1;
  currentTarget = (currentPlayer == p1) ? p2 : p1;
};

void Duel::displayWinner()
{
  shared_ptr<Character> winner = (p1CurrentHealht != 0) ? p2 : p1;
  shared_ptr<Character> loser = (p1CurrentHealht == 0) ? p2 : p1;

  cout << winner->getName() << " has won the tournument " << " against " << loser->getName() << endl;
};