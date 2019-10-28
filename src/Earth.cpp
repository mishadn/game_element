#include "Earth.h"
#include <string>
#include <iostream>
#include "gameSets.h"
//#include "Element.h"

Earth::Earth() : Element(elements::Earth)
{
    std::cout << "Earth::Earth() : Element(elements::Earth)" << std::endl;
}

Earth::~Earth()
{
    std::cout << "Earth::~Earth()" << std::endl;
}
