#include "BuilderBF.h"
#include "Civil.h"
#include "Cell.h"
#include "gameSets.h"
#include "BuilderFactory.h"
#include <iostream>

BuilderBF::BuilderBF(Cell* c) : Civil(units::BuilderBF, c, units::BUILDER_SOUND, units::BUILDER_HEALTH, units::BUILDER_POWER)
{
    std::cout << "BuilderBF::BuilderBF() Civil(units::BuilderBF...)" << std::endl;
}

BuilderBF::~BuilderBF()
{
    std::cout << "BuilderBF::~BuilderBF()" << std::endl;
}

BuilderFactory* BuilderBF::createBuilderFactory() const
{
    return new BuilderFactory(getCell());
}

int BuilderBF::getPowerBonus() const
{
    return 0;
}
int BuilderBF::getDefenceBonus() const
{
    return 0;
}
int BuilderBF::getDigInBonus() const
{
    return 0;
}
