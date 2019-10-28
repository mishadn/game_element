#include "Unit.h"
#include "gameSets.h"
#include <iostream>
#include <string>
#include "Cell.h"

Unit::Unit(units::UnitTypes uT, units::Units uN, Cell* c, std::string s, int h, int p) : unitType(uT), unitName(uN), cell(c), sound(s), health(h), power(p)
{
    std::cout << "Unit::Unit(units::UnitTypes uT) : unitType(uT) = " << unitType <<
     " Cell = " << cell->getCellElementType()->getElementType() << " (" << cell->getX() << "," << cell->getY() << ", " << cell->getZ() << ")"
     " sound = " << sound << " health = " << health << " power = " << power << std::endl;
}

Unit::~Unit()
{
    std::cout << "Unit::~Unit()" << std::endl;
}
/*
std::string Unit::getUnitType() const
{
    std::string res = "";

    switch (unitType)
    {
    case units::Civil :
        {
            res = "Civil";
            break;
        }
    case units::Military :
        {
            res = "Military";
            break;
        }
    default :
        {
            res = "No Type of Unit";
            break;
        }
    }

    return res;
}
*/
Cell* Unit::getCell() const
{
    return cell;
}

void Unit::setCell(Cell* c)
{
    cell = c;
}

void Unit::setHealth(int h)
{
    health = h;
}

int Unit::getHealth() const
{
    return health;
}

void Unit::setPower(int p)
{
    power = p;
}

int Unit::getPower() const
{
    return power;
}
 std::string Unit::getSound() const
 {
     return sound;
 }
//-------------------------------------------
 bool Unit::damage(Unit* enemy)
{
    bool res = true;
    if(enemy->health >0)
    {
    if (health > 0)
    {
        //health -= 1+((double)enemy->power/(double)power)*(double)getCellBonus(cell);///(double)Cell::status;
        health -= enemy->power + power - getPowerBonus() - getDefenceBonus();
    }
    else
    {
        std::cout << "I am dead" << std::endl;
    }
    }
    else
    {
        std::cout << "Hm... You can not attack. You is dead. :(" << std::endl;
        res = false;
    }
    return res;
};


 void Unit::digIn()
 {
     if(!isDigIn)
     {
         health += getDigInBonus();
         isDigIn = true;
         std::cout << "You have dig in successfully. You health is " << health << std::endl;

     }
     else
     {
         std::cout << "You have already dig in" << std::endl;
     }

 }
 void Unit::digOut()
 {
     int h = health - getDigInBonus();
     if (h > 0)
     {
         health = h;
         isDigIn = false;
     }
     else
     {
         std::cout << "You can`t dig out. Health after dig out will be " << h << std::endl;
     }
 }
bool Unit::getIsDigIn() const
{
    return isDigIn;
}

void Unit::printInfo() const
{
    std::cout << "const units::UnitTypes unitType = " << units::getUnitTypeName(unitType) << std::endl;
    std::cout << "const units::Units unitName = " << units::getUnitName(unitName) << std::endl;
    std::cout << "Cell* cell->getCellElementType() = " << elements::getElementTypeName(cell->getCellElementType()->getElementType()) << std::endl;
    std::cout << "Cell* cell->getCellLandscape() = " << elements::getLandscapeName(cell->getCellLandscape()) << std::endl;
    std::cout << "int health = " << health << std::endl;
    std::cout << "int power = " << power << std::endl;
    std::cout << "bool isDigIn = " << std::boolalpha << isDigIn << std::endl;
    std::cout << "std::string sound = " << sound << std::endl;
}

std::string Unit::printInfoLine() const
{
    std::string res;
    res = "unitType = " + units::getUnitTypeName(unitType) + ";"
    + " unitName = " + units::getUnitName(unitName) + ";"
    + " Cell[" + std::to_string(cell->getX()) + "][" + std::to_string(cell->getY()) + "][" + std::to_string(cell->getZ()) + "]"  + " Element = " + elements::getElementTypeName(cell->getCellElementType()->getElementType()) + ","
    + " Landscape = " + elements::getLandscapeName(cell->getCellLandscape()) + ";"
    + " health = " + std::to_string(health) + ";"
    + " power = " + std::to_string(power) + ";"
    + " isDigIn = " + std::to_string(isDigIn) + ";"
    + " sound = " + sound;

    return res;
}


std::string Unit::toString() const
{
    std::string res = "Unit;" + std::to_string(unitType) + ";" + std::to_string(unitName) + ";"
//                    + std::to_string(cell->getCellElementType()->getElementType()) + ";"
//                    + std::to_string(cell->getCellLandscape()) + ";"
                    + std::to_string(cell->getX()) + ";" + std::to_string(cell->getY()) + ";"
                    + std::to_string(cell->getZ()) + ";"
                    + std::to_string(health) + ";" + std::to_string(power) + ";"
                    + std::to_string(isDigIn);
                    //+ ";" + sound;
    return res;

}

units::UnitTypes Unit::getUnitType() const
{
    return unitType;
}

units::Units Unit::getUnitName() const
{
    return unitName;
}
