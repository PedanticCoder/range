#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <range/v3/all.hpp>

using strVector = std::vector<std::string>;

std::vector<std::string> split(const std::string &str, char d);

void readAllPool(std::vector<strVector> &pool);

void writeAllPool(std::vector<strVector> &pool);

void writeIpToConsole(strVector& tmp);

void filterAny(uint8_t anyByte, std::vector<strVector> &pool);

void reverseIpSort(std::vector<strVector> &pool);

