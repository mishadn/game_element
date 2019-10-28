#include "Military.h"
#include "gameSets.h"
#include <iostream>
#include "Cell.h"

Military::Military(units::Units uN, Cell* c, std::string s, int h, int p) : Unit(units::Military, uN, c, s, h, p)
{
    std::cout << "Military::Military(units::Units uN) : Unit(units::Military), unitName(uN) = " << uN << std::endl;
}

Military::~Military()
{
    std::cout << "Military::~Military()" << std::endl;
}

bool Military::attack(Unit* enemy)
{
    bool res = true;
    if(getHealth() > 0)
    {
    if (enemy->getHealth() > 0)
    {
        std::cout << "enemy->health = " << enemy->getHealth() << " - " << getPower() << " + " << enemy->getPower() << " - " << getPowerBonus() << " - " << getDefenceBonus() << std::endl;
        //enemy->health -= 1+(double)((double)power/(double)enemy->power)*(double)getCellBonus(cell);//*(double)Cell::status);
        enemy->setHealth(enemy->getHealth() - getPower() + enemy->getPower() - getPowerBonus() + getDefenceBonus());//*(double)Cell::status);
    }
    else
    {
        std::cout << "Unit is dead" << std::endl;
    }
    }
    else
    {
        std::cout << "I can not attack. I am dead" << std::endl;
        res = false;
    }
    return res;
};
