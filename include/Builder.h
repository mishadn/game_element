#ifndef BUILDER_H
#define BUILDER_H

#include <vector>
#include "Civil.h"
#include "TankFactory.h"
#include "gameSets.h"
#include "CellsMap.h"


class BuilderFactory;
class Gamer;
class Builder : public Civil
{
public:
   // Builder(Gamer*, Cell*);
   // Builder (Gamer*, Cell* cell, int health, int power, bool isDigIn);
    Builder(Cell*);
    Builder (Cell* cell, int health, int power, bool isDigIn);
    virtual ~Builder();
    int getPowerBonus() const;
    int getDefenceBonus() const;
    int getDigInBonus() const;
    actions::Actions getAction() const;
    virtual void doAction(actions::Actions, CellsMap*);
    TankFactory* createTankFactory() const;
    BuilderFactory* createBuilderFactory() const;
 //   template <class FactoryP> FactoryP* createFactory(FactoryP*) const;

private:
    static std::map <elements::Landscape, int> powerBonus;
    static std::map <elements::Landscape, int> defenceBonus;
    static std::map <elements::Landscape, int> digInBonus;
    static std::vector <actions::Actions> actionsToDO;
    Gamer* gamer;

};
/*
template <class FactoryP> FactoryP* Builder::createFactory(FactoryP* pointToFactory) const
{
    return new pointToFactory(getCell());
}
*/
#endif // BUILDER_H
