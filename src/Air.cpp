#include "Air.h"
#include <string>
#include <iostream>
#include "gameSets.h"

Air::Air() : Element(elements::Air)
{
    std::cout << "Air::Air() : Element(elements::Air)" << std::endl;
}

Air::~Air()
{
    std::cout << "Air::~Air()" << std::endl;
}

