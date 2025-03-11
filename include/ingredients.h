#ifndef INGREDIENTS_H
#define INGREDIENTS_H
#include <string>

using namespace std;

// Base classes

class PotionModifier {
  int modifier;
  virtual void modify_potion() = 0;
};

class Ingredient {
  protected:
    string ingredientName;
    int ingredientPoint;

  public:
    Ingredient(string name, int point );
    virtual void synergy();
};

// Ingredients

class Mandrake : public Ingredient {
  public:
    Mandrake(int points) : Ingredient("Mandrake", points) {};
    void synergy() override;
};

class BlueMoss : public Ingredient {
  public:
    BlueMoss(int points) : Ingredient("BlueMoss", points) {};
    void synergy() override;
};

class DragonScales : public Ingredient {
  DragonScales(int points) : Ingredient("DragonScales", points) {};
  void synergy() override;
};

class EyeOfNewt : public Ingredient {
  EyeOfNewt(int points) : Ingredient("Eye of newt", points) {};
  void synergy() override;
};

class ExplodingCherry : public Ingredient {
  ExplodingCherry(int points) : Ingredient("Exploding cherry", points) {};
  void synergy() override;
};

class RavenFeet :public Ingredient {
  RavenFeet(int point) : Ingredient("Raven feet", point) {};
  void synergy() override;
};

#endif