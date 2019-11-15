#include "filter.h"

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void readAllPool(std::vector<strVectIP> &pool)
{
    for(std::string line; std::getline(std::cin, line);)
    {
        std::vector<std::string> v = split(line, '\t');
        pool.push_back(split(v.at(0), '.'));
    }
}

void writeAllPool(std::vector<strVectIP> &pool)
{
    for(std::vector<std::vector<std::string> >::const_iterator ip = pool.cbegin(); ip != pool.cend(); ++ip)
    {
        for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

void writeAllPoolIP(std::vector<intVectIP> &pool)
{
    for(std::vector<std::vector<int> >::const_iterator ip = pool.cbegin(); ip != pool.cend(); ++ip)
    {
        for(std::vector<int>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

std::vector<intVectIP> initializeIpPoolInt(std::vector<strVectIP> &pool)
{
   std::vector<intVectIP> poolInt;
   poolInt.reserve(pool.size());
   std::vector<int> num(4);
   for(ulong i = 0; i < pool.size(); ++i) {
       num[0] = atoi(pool.at(i).at(0).c_str());
       num[1] = atoi(pool.at(i).at(1).c_str());
       num[2] = atoi(pool.at(i).at(2).c_str());
       num[3] = atoi(pool.at(i).at(3).c_str());

       poolInt.push_back(num);
   }
   return poolInt;
}

void writeIpToConsole(intVectIP& tmp)
{
    std::cout << tmp.at(0) << "."
              << tmp.at(1) << "."
              << tmp.at(2) << "."
              << tmp.at(3) << std::endl;
}

void filterAny(uint8_t anyByte, std::vector<intVectIP> &pool)
{
    ranges::for_each(pool | ranges::view::filter([=](intVectIP tmp) {
                           return (std::any_of(tmp.begin(), tmp.end(), [=] (int tmp) {
                                return (tmp == anyByte);
                           })); }),
                                [](intVectIP tmp) { writeIpToConsole(tmp); });
}

void reverseIpSort(std::vector<intVectIP> &pool)
{
    ranges::sort(pool, std::greater<intVectIP>());
        writeAllPoolIP(pool);
}

void filterModified(intVectIP &partIp, std::vector<intVectIP> &pool)
{
    ranges::for_each(pool,
                     [=](intVectIP tmp)
                      {
                          if (partIp.size()==3 &&
                              std::equal(tmp.rbegin()+2, tmp.rend(), partIp.rbegin()))
                                   writeIpToConsole(tmp);
                          if (partIp.size()==1 &&
                              std::equal(tmp.rbegin()+3, tmp.rend(), partIp.rbegin()))
                                   writeIpToConsole(tmp);
                      });
}

