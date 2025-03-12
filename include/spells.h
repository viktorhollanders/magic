#ifndef SPELLS_H
#define SPELLS_H
#include <string>

using namespace std;

class Ingredient {
  protected:
    string ingredientName;
    int ingredientPoint;

  public:
    Ingredient(string name, int point );
    virtual void synergy();
};

#endif