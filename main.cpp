#include "filter.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void filter(int firstByte, std::vector<intVector> &pool)
{
      ranges::for_each(pool | ranges::view::filter([=](intVector tmp) { return tmp.at(0) == firstByte; }),
                     [](intVector tmp) { writeIpToConsole(tmp); });
}

void filter(int firstByte, int secondByte, std::vector<intVector> &pool)
{
    ranges::for_each(pool | ranges::view::filter([=](intVector tmp) { return tmp.at(0) == firstByte
                                                                          && tmp.at(1) == secondByte; }),
                      [](intVector tmp) { writeIpToConsole(tmp); });
}

template<typename... Args>
void filterWrapper(Args... args)
{
    filter(args...);
}

int main()
{
    try
    {
        std::vector<strVector> ip_pool;
        readAllPool(ip_pool);
        poolInt = initializeIpPoolInt(ip_pool);
        reverseIpSort(poolInt);
        filterWrapper(1, poolInt);
        filterWrapper(46, 70, poolInt);
        filterAny(46, poolInt);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}



