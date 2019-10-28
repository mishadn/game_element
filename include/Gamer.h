#ifndef GAMER_H
#define GAMER_H
#include <deque>
#include "Unit.h"
#include "Factory.h"
#include <string>
#include "Builder.h"
#include "BuilderFactory.h"
#include <iostream>
#include "Cell.h"
#include "CellsMap.h"
#include <fstream>
class Gamer
{
    public:
        Gamer(std::string, CellsMap*);
        virtual ~Gamer();
        std::string getName() const;
        void printInfo() const;
        void printObjectsStatusLine() const;
        template <class FactoryT> void createUnit (FactoryT*);
        void createBuilder(Cell*);
        //void createFactory ();
        void printUnits() const;
        void printFactores() const;
        void printFactoriesLine() const;
        void printUnitsLine() const;
        void pitUnits() const;
        void takeUnit(int);
        void takeFactory(int);
        int takeUnitAction();
        std::deque <Factory*>* getFactories() const;
        std::deque <Unit*>* getUnits() const;
        void selectGameObject();
        actions::Actions selectObjectAction();
        void makeObjectAction(int);
        void pushUnit(Unit*);
        void pushFactory(Factory*);


    private:
        std::deque <Unit*>* units;
        std::deque <Factory*>* factores;
        std::string const name;
        Unit* currUnit = nullptr;
        Factory* currFactory = nullptr;
        gameobj::Gameobj currObjectType;
        const CellsMap* cellsMap;


};

template <class FactoryT> void Gamer::createUnit(FactoryT* factory)
{
    units->push_back(factory->getUnit());
  //  std::cout << "!!!!!!!!!!!! tut !!!!!!!!" << std::endl;
};

#endif // GAMER_H
