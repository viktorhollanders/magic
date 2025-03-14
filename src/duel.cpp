#include <iostream>
#include <random>

#include "duel.h"
#include "character.h"
#include "spell.h"

Duel::Duel(shared_ptr<Character> player1, shared_ptr<Character> player2) : p1(player1), p2(player2) {};
Duel::~Duel() {};

shared_ptr<Character> Duel::initialPlayer()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(1, 2);
  int num = distrib(gen);
  currentPlayer = (num == 1) ? p1 : p2;
  return currentPlayer;
};

void Duel::initializeDuel()
{
  p1CurrentHelaht = p1->getHealth();
  p2CurrentHelaht = p2->getHealth();

  duelFinished = false;

  cout << "A duel starts between these wizards!" << endl;
  cout << endl;
  cout << p1->displayPlayerInfo() << endl;
  cout << endl;
  cout << "==VS==" << endl;
  cout << endl;
  cout << p2->displayPlayerInfo() << endl;
  initialPlayer();
}

shared_ptr<Character> Duel::swithcPlayer(shared_ptr<Character> current)
{
  return (current == p1) ? p2 : p1;
};

void applySpellEffect(shared_ptr<Character> caster, shared_ptr<Character> target, Spell *spell) {

};

void Duel::playRound()
{

  auto playerSpellBook = currentPlayer->getSpellBook();
  string chosenSpellName;
  Spell choseSpell;

  cout << "== " << currentPlayer->getName() << "turn ==" << endl;
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
    for (int j = 0; j < playerSpellBook.size(); j++)
      for (int i = 0; i < playerSpellBook.size(); i++)
      {
        cout << i + 1 << ". " << playerSpellBook[i]->getSpellName() << endl;
      }
    cin >> userChoice;
  }

  chosenSpellName = playerSpellBook[userChoice]->getSpellName();

  currentPlayer->getSpell(chosenSpellName);

  swithcPlayer(currentPlayer);
}