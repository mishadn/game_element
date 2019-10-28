#include "Civil.h"
#include "gameSets.h"
#include <iostream>

Civil::Civil(units::Units uN, Cell* c, std::string s, int h, int p) : Unit(units::Civil, uN, c, s, h, p)
{
    std::cout << "Civil::Civil() : Unit(units::Civil), unitName(uN) = " << uN << std::endl;
}

Civil::~Civil()
{
    std::cout << "Civil::~Civil()" << std::endl;
}

