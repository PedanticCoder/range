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

void readAllPool(std::vector<strVector> &pool)
{
    for(std::string line; std::getline(std::cin, line);)
    {
        std::vector<std::string> v = split(line, '\t');
        pool.push_back(split(v.at(0), '.'));
    }
}

void writeAllPool(std::vector<strVector> &pool)
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

void writeAllPoolIP(std::vector<intVector> &pool)
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

std::vector<intVector> initializeIpPoolInt(std::vector<strVector> &pool)
{
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

void writeIpToConsole(intVector& tmp)
{
    std::cout << tmp.at(0) << "."
              << tmp.at(1) << "."
              << tmp.at(2) << "."
              << tmp.at(3) << std::endl;
}

void filterAny(uint8_t anyByte, std::vector<intVector> &pool)
{
    ranges::for_each(pool | ranges::view::filter([=](intVector tmp) { return tmp.at(0) == anyByte ||
                                                                             tmp.at(1) == anyByte ||
                                                                             tmp.at(2) == anyByte ||
                                                                             tmp.at(3) == anyByte; }),
                     [](intVector tmp) { writeIpToConsole(tmp); });
}

void reverseIpSort(std::vector<intVector> &pool)
{
    ranges::sort(pool,
                 [](intVector tmp, intVector tmp2)  {
                     if(tmp.at(0) > tmp2.at(0))
                        return true;
                    else if((tmp.at(0) == tmp2.at(0))
                            && (tmp.at(1) > tmp2.at(1)))
                    {
                        return true;
                    }
                    else if((tmp.at(1) == tmp2.at(1))
                            && (tmp.at(2) > tmp2.at(2)))
                    {
                        return true;
                    }
                    else if((tmp.at(2) == tmp2.at(2))
                            && (tmp.at(3) > tmp2.at(3)))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
		});
        writeAllPoolIP(pool);
}


