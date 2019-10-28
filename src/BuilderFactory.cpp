#include "BuilderFactory.h"
#include <iostream>
#include <string>
#include "Builder.h"
#include "CivilFactory.h"
#include "gameSets.h"


std::vector <actions::Actions> BuilderFactory::actionsToDO = {actions::MakeUnit};

actions::Actions BuilderFactory::getAction() const
{
    actions::Actions res = actions::Move;
    for(int i = 0; i < BuilderFactory::actionsToDO.size(); i++)
    {
        std::cout << i << " - " << actions::getActionName(BuilderFactory::actionsToDO[i]) << std::endl;
    }
    while (true)
    {
        int i = 0;
        std::cin >> i;
        if (i>=0 && i <= BuilderFactory::actionsToDO.size())
            {
                res = BuilderFactory::actionsToDO[i];
                break;
            }
    }
    return res;
}


BuilderFactory::BuilderFactory(Cell* c) : Factory(factory::Builder, c, factory::BUILDER_SOUND, factory::BUILDER_HEALTH, factory::BUILDER_POWER), CivilFactory(factory::Civil)//, Builder(c)
{
    std::cout << "BuilderFactory::BuilderFactory(Cell* c)" << std::endl;
    c->setBusy();
//    getInfo();
}

BuilderFactory::BuilderFactory(Cell* c, int h, int p, bool isDigIn) : Factory(factory::Builder, c, factory::BUILDER_SOUND, h, p), CivilFactory(factory::Civil)
{
    std::cout << "BuilderFactory::BuilderFactory(Cell* c, int h, int p, bool isDigIn)" << std::endl;
    c->setBusy();
}


BuilderFactory::~BuilderFactory()
{
    getCell()->setEmpty();
}

Builder* BuilderFactory::getUnit() const
{
    return new Builder(getCell());
}

void BuilderFactory::printInfo() const
{
    std::cout << "factory::FactoryTypes factoryType = " << factory::getFactoryTypeName(getFactoryType()) << std::endl;
    Factory::printInfo();
}

std::string BuilderFactory::toStringWord() const
{
    return "Factory;" + factory::getFactoryTypeName(getFactoryType()) + ";" + this->Factory::toString();
}

std::string BuilderFactory::toString() const
{
    return "Factory;" + std::to_string(getFactoryType()) + ";" + this->Factory::toString();
}

std::string BuilderFactory::printInfoLine() const
{
    return "Factory Name " + factory::getFactoryTypeName(getFactoryType()) + "; " + this->Factory::toString();
}
