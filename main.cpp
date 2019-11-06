#include "filter.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
intVectIP variadicContainer(T arg)
{
    partPoolVar.push_back(arg);
    return partPoolVar;
}

template<typename T, typename... Args>
intVectIP variadicContainer(T firstArg, Args... args)
{
    variadicContainer(firstArg);
    variadicContainer(args...);
    return partPoolVar;
}

int main()
{
    try
    {
        std::vector<strVectIP> ip_pool;
        readAllPool(ip_pool);
        poolInt = initializeIpPoolInt(ip_pool);
        reverseIpSort(poolInt);
        partIpPool = variadicContainer(1);
        filterModified(partIpPool, poolInt);
        partIpPool = variadicContainer(46, 70);
        filterModified(partIpPool, poolInt);
        filterAny(46, poolInt);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}



