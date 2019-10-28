#include "CivilFactory.h"
#include <iostream>
#include "gameSets.h"

CivilFactory::CivilFactory(factory::FactoryTypes fT) : factoryType(fT)
{
    std::cout << "CivilFactory::CivilFactory() = " << fT << std::endl;
}

CivilFactory::~CivilFactory()
{
    std::cout << "CivilFactory::~CivilFactory()" << std::endl;
}

factory::FactoryTypes CivilFactory::getFactoryType() const
{
    return factoryType;
}
