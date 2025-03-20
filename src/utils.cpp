#include "utils.h"
#include <random>

using namespace std;

int generateRandomNum(int min, int max)
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(min, max);
  return distrib(gen);
};
