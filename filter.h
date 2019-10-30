#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <range/v3/all.hpp>

using strVector = std::vector<std::string>;
using intVector = std::vector<int>;

static std::vector<intVector> poolInt;

std::vector<std::string> split(const std::string &str, char d);

std::vector<intVector> initializeIpPoolInt(std::vector<strVector> &pool);

void readAllPool(std::vector<strVector> &pool);

void writeAllPool(std::vector<strVector> &pool);

void writeAllPoolIP(std::vector<intVector> &pool);

void writeIpToConsole(intVector& tmp);

void filterAny(uint8_t anyByte, std::vector<intVector> &pool);

void reverseIpSort(std::vector<intVector> &pool);


