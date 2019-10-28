#ifndef CIVILFACTORY_H
#define CIVILFACTORY_H

#include "Factory.h"
#include "gameSets.h"
//#include <string>


class CivilFactory
{
    public:

        virtual ~CivilFactory();
        factory::FactoryTypes getFactoryType() const;
    protected:
        CivilFactory(factory::FactoryTypes);
    private:
    //    factory::Factorys factoryName;
        factory::FactoryTypes factoryType;
};

#endif // CIVILFACTORY_H
