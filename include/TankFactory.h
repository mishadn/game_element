#ifndef TANKFACTORY_H
#define TANKFACTORY_H
#include "Factory.h"
#include "CivilFactory.h"
#include "Tank.h"


class TankFactory: public CivilFactory, public Factory
{
    public:
        TankFactory(Cell*);
        TankFactory(Cell*, int, int, bool);
        virtual ~TankFactory();
        virtual Tank* getUnit() const;
        virtual void printInfo() const;
        std::string printInfoLine() const;
        virtual std::string toString() const;
        virtual std::string toStringWord() const;
        virtual actions::Actions getAction() const;
    private:
        static std::vector <actions::Actions> actionsToDO;
};

#endif // TANKFACTORY_H
