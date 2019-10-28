#ifndef FACTORY_H
#define FACTORY_H
#include "Unit.h"
#include "gameSets.h"
#include <string>


class Factory// : private Unit
{
    public:

        virtual ~Factory();
        Cell* getCell() const;
        virtual void printInfo() const;
        std::string printInfoLine() const;
        int getHealth() const;
        int getPower() const;
        std::string getSound() const;
        void setHealth(int);
        void setPower(int);
        factory::Factorys getFactoryName() const;
        virtual std::string toString() const;
        virtual std::string toStringWord() const;
        virtual Unit* getUnit() const = 0;
        virtual actions::Actions getAction() const = 0;
    protected:
        Factory(factory::Factorys, Cell* , std::string, int, int);

    private:
        factory::Factorys factoryName;
        Cell* cell;
        int health;
        int power;
        bool isDigIn = false;
        const std::string sound;

};

#endif // FACTORY_H
