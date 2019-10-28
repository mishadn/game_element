#include "Factory.h"
#include <string>
#include "Cell.h"
#include <iostream>
#include "gameSets.h"

Factory::Factory(factory::Factorys fN, Cell* c, std::string s, int h, int p) : factoryName(fN), cell(c), sound(s), health(h), power(p)
{
    std::cout << "Factory::Factory(factory::Factorys fN, Cell* c, std::string s, int h, int p" << std::endl;
}

Factory::~Factory()
{
    std::cout << "Factory::~Factory()" << std::endl;
}

Cell* Factory::getCell() const
{
    return cell;
}

int Factory::getHealth() const
{
    return health;
}

int Factory::getPower() const
{
    return power;
}

std::string Factory::getSound() const
{
    return sound;
}

void Factory::setHealth(int h)
{
    health = h;
}

void Factory::setPower(int p)
{
    power = p;
}
void Factory::printInfo() const
{
   std::cout << "factory::Factorys factoryName = " << factory::getFactoryName(factoryName) << std::endl;
        std::cout << "Cell* cell = " << elements::getElementTypeName(cell->getCellElementType()->getElementType()) << std::endl;
        std::cout << "x = " << cell->getX() << std::endl;
        std::cout << "y = " << cell->getY() << std::endl;
        std::cout << "z = " << cell->getZ() << std::endl;
        std::cout << "int health = " << health << std::endl;
        std::cout << "int power = " << power << std::endl;
        std::cout << "bool isDigIn = " << std::boolalpha << isDigIn << std::endl;
        std::cout << "std::string sound = " << sound << std::endl;


}

factory::Factorys Factory::getFactoryName() const
{
    return factoryName;
}

std::string Factory::toStringWord() const
{
/*    std::string res = "Factory;" + std::to_string(unitType) + ";" + std::to_string(unitName) + ";"
//                    + std::to_string(cell->getCellElementType()->getElementType()) + ";"
//                    + std::to_string(cell->getCellLandscape()) + ";"
                    + std::to_string(cell->getX()) + ";" + std::to_string(cell->getY()) + ";"
                    + std::to_string(cell->getZ()) + ";"
                    + std::to_string(health) + ";" + std::to_string(power) + ";"
                    + std::to_string(isDigIn);*/
        std::string res = factory::getFactoryName(factoryName) + ";"
        + "Cell* cell = " + elements::getElementTypeName(cell->getCellElementType()->getElementType()) + ";"
        + "x = " + std::to_string(cell->getX()) + ";"
        + "y = " + std::to_string(cell->getY()) + ";"
        + "z = " + std::to_string(cell->getZ()) + ";"
        + "int health = " + std::to_string(health) + ";"
        + "int power = " + std::to_string(power) + ";"
        + "bool isDigIn = " + std::to_string(isDigIn) + ";"
        + "std::string sound = " + sound;

        return res;
}

std::string Factory::toString() const
{
        std::string res = std::to_string(factoryName) + ";"
        + std::to_string(cell->getX()) + ";"
        + std::to_string(cell->getY()) + ";"
        + std::to_string(cell->getZ()) + ";"
        + std::to_string(health) + ";"
        + std::to_string(power) + ";"
        + std::to_string(isDigIn) + ";";
        return res;
}

std::string Factory::printInfoLine() const
{
    return "factoryName =" + factory::getFactoryName(factoryName) + ";"
            + " Cell's Element = " + elements::getElementTypeName(cell->getCellElementType()->getElementType()) + ";"
            + " x = " + std::to_string(cell->getX()) + ";"
            + " y = " + std::to_string(cell->getY()) + ";"
            + " z = " + std::to_string(cell->getZ()) + ";"
            + " health = " + std::to_string(health) + ";"
            + " power = " + std::to_string(power) + ";"
            + " isDigIn = " + std::to_string(isDigIn) + ";"
            + " sound = " + sound;
}
