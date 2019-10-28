#include "Water.h"
#include <string>
#include <iostream>

Water::Water() : Element(elements::Water)
{
    std::cout << "Water::Water() : Element(elements::Water)" << std::endl;
}

Water::~Water()
{
    std::cout << "Water::~Water()" << std::endl;
}
