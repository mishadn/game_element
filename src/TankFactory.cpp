#include "TankFactory.h"
#include <iostream>
#include <string>
#include "Tank.h"
#include "CivilFactory.h"
#include "gameSets.h"

std::vector <actions::Actions> TankFactory::actionsToDO = {actions::MakeUnit};

actions::Actions TankFactory::getAction() const
{
    actions::Actions res = actions::Move;
    for(int i = 0; i < TankFactory::actionsToDO.size(); i++)
    {
        std::cout << i << " - " << actions::getActionName(TankFactory::actionsToDO[i]) << std::endl;
    }
    while (true)
    {
        int i = 0;
        std::cin >> i;
        if (i>=0 && i <= TankFactory::actionsToDO.size())
            {
                res = TankFactory::actionsToDO[i];
                break;
            }
    }
    return res;
}


TankFactory::TankFactory(Cell* c) : Factory(factory::Tank, c, factory::TANK_SOUND, factory::TANK_HEALTH, factory::TANK_POWER), CivilFactory(factory::Military)
{
    std::cout << "TankFactory::TankFactory(Cell* c)" << std::endl;
//    getInfo();
}

TankFactory::TankFactory(Cell* c, int h, int p, bool isDigIn) : Factory(factory::Tank, c, factory::TANK_SOUND, h, p), CivilFactory(factory::Military)
{
    std::cout << "TankFactory::TankFactory(Cell* c, int h, int p, bool isDigIn)" << std::endl;
    c->setBusy();
}

TankFactory::~TankFactory()
{
    //dtor
}

Tank* TankFactory::getUnit() const
{
    return new Tank(getCell());
}

void TankFactory::printInfo() const
{
    std::cout << "factory::FactoryTypes factoryType = " << factory::getFactoryTypeName(getFactoryType()) << std::endl;
    Factory::printInfo();
}

std::string TankFactory::toStringWord() const
{
    return "Factory;" + factory::getFactoryTypeName(getFactoryType()) + ";" + this->Factory::toString();
}

std::string TankFactory::toString() const
{
    return "Factory;" + std::to_string(getFactoryType()) + ";" + this->Factory::toString();
}

std::string TankFactory::printInfoLine() const
{
    return "Factory Name " + factory::getFactoryTypeName(getFactoryType()) + "; " + this->Factory::toString();
}
