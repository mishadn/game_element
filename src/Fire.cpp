#include "Fire.h"
#include <string>
#include <iostream>
#include "gameSets.h"

Fire::Fire() : Element(elements::Fire)
{
    std::cout << "Fire::Fire() : public Element(elements::Fire)" << std::endl;
}

Fire::~Fire()
{
    std::cout << "Fire::~Fire()" << std::endl;
}
