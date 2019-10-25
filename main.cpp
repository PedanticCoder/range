#include "filter.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void filter(int firstByte, std::vector<strVector> &pool)
{
      std::string str = std::to_string(firstByte);
      ranges::for_each(pool | ranges::view::filter([=](strVector tmp) { return tmp.at(0) == str; }),
                     [](strVector tmp) { writeIpToConsole(tmp); });
}

void filter(int firstByte, int secondByte, std::vector<strVector> &pool)
{
    std::string str = std::to_string(firstByte);
    std::string str2 = std::to_string(secondByte);
    ranges::for_each(pool | ranges::view::filter([=](strVector tmp) { return tmp.at(0) == str
                                                                          && tmp.at(1) == str2; }),
                      [](strVector tmp) { writeIpToConsole(tmp); });
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
        reverseIpSort(ip_pool);
        filterWrapper(1, ip_pool);
        filterWrapper(46, 70, ip_pool);
        filterAny(46, ip_pool);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}



