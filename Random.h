#ifndef _RANDOM_
#define _RANDOM_

#include "Common.h"
#include "SFMT/SFMT.h"
#include <random>
using Range = std::uniform_int_distribution<>::param_type;
sfmt_t SfmtSeed;
uniform_int_distribution<> dist;
default_random_engine rng;
class Random {
  public:
    static int get_random(int range);
    static int get_uniform_random(int range);
};



#endif