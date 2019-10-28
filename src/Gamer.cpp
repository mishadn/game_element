#include "Gamer.h"
#include <string>
#include <iostream>
#include "BuilderFactory.h"
#include "Builder.h"
#include "Unit.h";
#include <typeinfo>
#include "Factory.h"
#include "gameSets.h"
#include "CellsMap.h"

Gamer::Gamer(std::string n, CellsMap* cm) : name(n), cellsMap(cm)
{
    std::cout << "Gamer::Gamer(std::string n) = " << name << std::endl;
    units = new std::deque <Unit*>;
    factores = new std::deque <Factory*>;
}

Gamer::~Gamer()
{
    std::cout << "Gamer::~Gamer()" << std::endl;
}

std::string Gamer::getName() const
{
    return name;
}

void Gamer::printInfo() const
{
    std::cout << "name = " << name << std::endl;
}

void Gamer::createBuilder(Cell* c)
{
    if (units->empty())
    {
        Builder* builder = new Builder(c);
        units->push_back(builder);
        takeUnit(0);
    }
}

void Gamer::printUnits() const
{
    std::cout << "number of units is " << units->size() << std::endl;
    for (int i = 0 ; i < units->size(); i++)
    {
        std::cout << " ------ unit " << i << " -------------" << std::endl;
        units->at(i)->printInfo();
        std::cout << " ------ unit " << i << " -------------" << std::endl << std::endl;
    }
}

void Gamer::pitUnits() const
{
    int i = 0;
    for(std::deque<Unit*>::iterator u = units->begin(); u != units->end(); u++, i++)
    {
        (*u)->printInfo();
        //std::cout << " JJJJJJJJJJJJJJJJj " << *u << std::endl;
    }
}

void Gamer::printUnitsLine() const
{
    int i = 0;
    std::cout << "number of units is " << units->size() << std::endl;
    for(std::deque<Unit*>::iterator u = units->begin(); u != units->end(); u++, i++)
    {
        std::cout << " - unit: " << i << " - ";
        std::cout << (*u)->printInfoLine();
        std::cout << std::endl;
        //std::cout << " JJJJJJJJJJJJJJJJj " << *u << std::endl;
    }
}

void Gamer::printFactores() const
{
    int i = 0;
    std::cout << "number of factories is " << factores->size() << std::endl;
    for(std::deque<Factory*>::iterator f = factores->begin(); f != factores->end(); f++, i++)
    {
        std::cout << " ------- factory " << i << " ---------------- " << std::endl;
        (*f)->printInfo();
        std::cout << " ------- factory " << i << " ---------------- " << std::endl << std::endl;
    }

}

void Gamer::printFactoriesLine() const
{
    //std::string res;
    int i = 0;
    std::cout << "number of factories is " << factores->size() << std::endl;
    for(std::deque<Factory*>::iterator f = factores->begin(); f != factores->end(); f++, i++)
    {
        std::cout << " - factory :" << i << "; ";
        std::cout << (*f)->printInfoLine();
        std::cout << std::endl << std::endl;
    }
}

void Gamer::takeUnit(int i)
{
    currUnit = nullptr;
    if (i < units->size())
    {
        currUnit = units->at(i);
        currObjectType = gameobj::Unit;
        //currUnit->printInfo();
        //std::cout << " type = " << typeid(*currUnit).name() << std::endl;
    }
}

void Gamer::takeFactory(int i)
{
    currFactory = nullptr;
    if (i < factores->size())
    {
        char yN='Y';
        currFactory = factores->at(i);
        currObjectType = gameobj::Factory;
    }
}

int Gamer::takeUnitAction()
{
    char* res;
    res[0] = '0';
    if (currUnit)
    {
        std::cout << "Select from available unit-" << units::getUnitName(currUnit->getUnitName()) << " actions:" << std::endl;

        switch(currUnit->getUnitName())
        {
        case units::Builder :
        {
            std::cout << "set Cell - 1" << std::endl;
            std::cout << "create Tank factory - 2" << std::endl;
            std::cout << "create Builder factory - 3" << std::endl;
            break;
        }
        case units::Tank :
        {
            std::cout << "set Cell - 1" << std::endl;
            std::cout << "attack - 2" << std::endl;
            break;
        }
        }
        std::cin >> res;
    }
    return atoi(res);
}
/*
void Gamer::createFactory ()
{
    switch(currUnit->getUnitName())
    {
    case units::Builder :
    {
        //  Builder* cUnit = (Builder*)currUnit;
        factory::Factorys nameOfFactory;
        int intNameOfFactory = 0;
        std::cout << "Builder create factory" << std::endl; //factory::getFactoryName(pointToFactory->getFactoryName());
        std::cout << " select factory to create:" << std::endl;
        std::cout << "             Builder Factory: 2" << std::endl;
        std::cout << "                Tank Factory: 3" << std::endl;
        std::cin >> intNameOfFactory;
        //std::cout << " -------------- " << intNameOfFactory;
        nameOfFactory = factory::intToFactoryName(intNameOfFactory);
        switch(nameOfFactory)
        {
        case factory::Builder :
        {
            factores->push_back(((Builder*)currUnit)->createBuilderFactory());
            break;
        }
        case factory::Tank :
        {
            factores->push_back(((Builder*)currUnit)->createTankFactory());
            break;
        }
        default :
        {
            std::cout << "Can not create selected factory" << std::endl;
        }
        }
        //std::cout <<  factory::getFactoryName(nameOfFactory) << " ------- 11111111 " <<std::endl;

        break;
    }
    default :
    {
        std::cout << "Current unit can not build a factory" << std::endl;
    }
    }
}
*/
std::deque <Factory*>* Gamer::getFactories() const
{
    return factores;
}

std::deque <Unit*>* Gamer::getUnits() const
{
    return units;
}


void Gamer::printObjectsStatusLine() const
{

        std::cout << std::endl << " ----------------------------------------------- " << std::endl;
        std::cout << "Current status of Gamer:" << getName() << std::endl;
        std::cout << " ----- Factories ------------------------------------------ " << std::endl;
        printFactoriesLine();
        std::cout << " ----- Units---- ------------------------------------------ " << std::endl;
        printUnitsLine();
        std::cout << " ----------------------------------------------- "<< std::endl << std::endl;
}

void Gamer::selectGameObject()
{
    char cinObjType;
    //printFactoriesLine();
    //std::cout << std::endl;
    //printUnitsLine();
    //std::cout << std::endl;
    while(true)
    {
        std::cout << std::endl << "Gamer " << name << std::endl;
        std::cout << "select type of object Factory (F) or Unit (U). Exit (E)";
        std::cin >> cinObjType;
        if (cinObjType == 'E')
        {
            break;
        }
        switch (cinObjType)
        {
        case 'F':
        {
            std::cout << "Factories:" << std::endl;
            printFactoriesLine();
            std::cout << std::endl;
            int i;
            std::cout << "select factory:";
            std::cin >> i;
            if (i>=0 && i<factores->size())
            {
                takeFactory(i);
                //currObjectType = gameobj::Factory;
                currFactory->printInfoLine();
            }
            else
            {
                std::cout << "can not select factory #" << i << std::endl;
            }
            break;
        }
        case 'U':
        {
            std::cout << "Units:" << std::endl;
            printUnitsLine();
            std::cout << std::endl;
            int i;
            std::cout << "select unit:";
            std::cin >> i;
            if (i>=0 && i<units->size())
            {
                takeUnit(i);
                //currObjectType = gameobj::Unit;
                std::cout << currUnit->printInfoLine() << std::endl;
            }
            else
            {
                std::cout << "can not select unit #" << i << std::endl;
            }
            break;
        }
        }
    }
}

actions::Actions Gamer::selectObjectAction()
{
    actions::Actions res = actions::Move;
    switch (currObjectType)
    {
    case gameobj::Unit :
    {
        res = currUnit->getAction();
        switch(res)
        {
        case actions::BuildBuilderFactory :
        {
            factores->push_back(((Builder*)currUnit)->createBuilderFactory());
            break;
        }
        case actions::BuildTankFactory :
        {
            factores->push_back(((Builder*)currUnit)->createTankFactory());
            break;
        }
        case actions::Move :
        {
            int x;
            int y;
            std::cout << "x = ";
            std::cin >> x;
            std::cout << "y = ";
            std::cin >> y;
            currUnit->setCell(cellsMap->cell[x][y][1]);
            break;
        }

        }
        //currUnit->doAction(res, cellsMap);
        break; // End of Unit actions
    }
    case gameobj::Factory :
    {
        res = currFactory->getAction();
        switch (res)
        {
        case actions::MakeUnit :
            {
                units->push_back(currFactory->getUnit());
                break;
            }
        }
        break; // End of Factory
    }
    default :
    {
        std::cout << "can not make selected action" << std::endl;
    }
    }
    return res;
}

void Gamer::pushUnit(Unit* u)
{
    units->push_back(u);
}

void Gamer::pushFactory(Factory* f)
{
    factores->push_back(f);
}
