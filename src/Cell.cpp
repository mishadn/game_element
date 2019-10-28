#include "Cell.h"
#include <iostream>
#include "gameSets.h"


Cell::~Cell()
{
    std::cout << "Cell::~Cell()" << std::endl;

}
/*
Cell::Cell(elements::Elements cT, int x, int y, int z) : cellType(cT), x(x), y(y), z(z)
{
   std::cout << "Cell::Cell(std::string cellType, int x, int y)" << " cellType = " << getCellType() << " x = " << getX() << " y = " << getY() << " z = " << getZ() << std::endl;
}
*/
Cell::Cell(Element* cET, elements::Landscape l, int x, int y, int z, int h) : cellElementType(cET), landscape(l), x(x), y(y), z(z), hight(h)
{
   std::cout << "Cell::Cell(Element* cET, elements::Landscape l int x, int y, int z, int h)" << " cellElementType = " << elements::getElementTypeName(getCellElementType()->getElementType())
   << " x = " << getX() << " y = " << getY() << " z = " << getZ() << " hight = " << getHight() << std::endl;
}

Element* Cell::getCellElementType() const
{
    return cellElementType;
}

elements::Landscape Cell::getCellLandscape() const
{
    return landscape;
}

void Cell::setBusy()
{
    busy = true;
}

void Cell::setEmpty()
{
    busy = false;
}

bool Cell::getBusy()
{
    return busy;
}

/*
std::string Cell::getCellType()
{
    std::string res = "";
    switch(cellType)
    {
        case elements::Air :
        {
            res = "Air";
            break;
        }
        case elements::Water :
        {
            res = "Water";
            break;
        }
        case elements::Earth :
        {
            res = "Earth";
            break;
        }
        case elements::Fire :
        {
            res = "Fire";
            break;
        }
        default :
        {
            res = "No Type of Element";
            break;
        }
    }
    return res;
}
*/
int Cell::getX()
{
    return x;
}

int Cell::getY()
{
    return y;
}

int Cell::getZ()
{
    return z;
}

int Cell::getHight() const
{
    return hight;
}
void Cell::printInfo() const
{
    std::cout << "Cell info:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "hight = " << hight << std::endl;
    std::cout << "busy = " << std::boolalpha << busy << std::endl;
    std::cout << "Element = " << cellElementType->getElementType() << std::endl;
    std::cout << "Landscape = " << elements::getLandscapeName(landscape) << std::endl;
}
