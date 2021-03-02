#include "Random.h"
#include "Error.h"
#include <limits.h>

/**
 * @brief 使用sfmt random 和 %range 的方法生成 [0，range) 之间随机数
 * 
 * @param range 
 * @return int 
 */
int Random::get_random(int range)
{
    int ret = sfmt_genrand_uint32(&SfmtSeed) % range;
    return ret;
}

int Random::get_uniform_random(int range)
{
    dist.param(Range(0,range-1));
    return dist(rng);
}
