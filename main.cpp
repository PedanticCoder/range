#include "filter.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

intVectIP partIpVar;

template<typename T>
intVectIP variadicContainer(T arg)
{
    partIpVar.push_back(arg);
    return partIpVar;
}

template<typename T, typename... Args>
intVectIP variadicContainer(T firstArg, Args... args)
{
    variadicContainer(firstArg);
    variadicContainer(args...);
    return partIpVar;
}

int main()
{
    try
    {
        std::vector<intVectIP> poolInt;
        intVectIP partIp;
        std::vector<strVectIP> ip_pool;
        readAllPool(ip_pool);
        poolInt = initializeIpPoolInt(ip_pool);
        reverseIpSort(poolInt);
        partIp = variadicContainer(1);
        filterModified(partIp, poolInt);
        partIp = variadicContainer(46, 70);
        filterModified(partIp, poolInt);
        filterAny(46, poolInt);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}



