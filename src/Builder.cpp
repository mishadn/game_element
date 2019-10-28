#include "Builder.h"
#include "gameSets.h"
//#include "BuilderBF.h"
#include <iostream>
#include "BuilderFactory.h"
#include <vector>
#include "Cell.h"


std::map <elements::Landscape, int> Builder::powerBonus = {{elements::WaterLand, 1}, {elements::SandLand, 1},{elements::ForestLand, 1}, {elements::MountLand, 1}, {elements::EarthLand, 2}};
std::map <elements::Landscape, int> Builder::defenceBonus = {{elements::WaterLand, 10}, {elements::SandLand, 10},{elements::ForestLand, 10}, {elements::MountLand, 10}};
std::map <elements::Landscape, int> Builder::digInBonus = {{elements::WaterLand, 100}, {elements::SandLand, 100},{elements::ForestLand, 100}, {elements::MountLand, 100}};
std::vector <actions::Actions> Builder::actionsToDO = {actions::Move, actions::BuildBuilderFactory, actions::BuildTankFactory};


void Builder::doAction(actions::Actions act, CellsMap* cellsMap)
{
    switch(act)
    {
    case actions::BuildBuilderFactory :
        {
            createBuilderFactory();
            break;
        }
    case actions::BuildTankFactory :
        {
            createTankFactory();
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
            setCell(cellsMap->cell[x][y][1]);
            break;
        }
    }
}

actions::Actions Builder::getAction() const
{
    actions::Actions res = actions::Move;
    for(int i = 0; i < Builder::actionsToDO.size(); i++)
    {
        std::cout << i << " - " << actions::getActionName(Builder::actionsToDO[i]) << std::endl;
    }
    while (true)
    {
        int i = 0;
        std::cin >> i;
        if (i>=0 && i <= Builder::actionsToDO.size())
            {
                res = Builder::actionsToDO[i];
                break;
            }
    }
    return res;
}
/*
Builder::Builder(Gamer* g, Cell* c) : Civil(units::Builder, c, units::BUILDER_SOUND, units::BUILDER_HEALTH, units::BUILDER_POWER), gamer(g)
{
    std::cout << "Builder::Builder() Civil(units::Builder)" << std::endl;
}
Builder::Builder (Gamer* g, Cell* c, int h, int p, bool isDigIn) : Civil(units::Builder, c, units::BUILDER_SOUND, h, p), gamer(g)
{
    std::cout << "Builder::Builder (Cell* cell, int h, int p, bool isDigIn)" << std::endl;
    if(isDigIn)
    {
        digIn();
    }
}*/

Builder::Builder(Cell* c) : Civil(units::Builder, c, units::BUILDER_SOUND, units::BUILDER_HEALTH, units::BUILDER_POWER)
{
    std::cout << "Builder::Builder() Civil(units::Builder)" << std::endl;
}
Builder::Builder (Cell* c, int h, int p, bool isDigIn) : Civil(units::Builder, c, units::BUILDER_SOUND, h, p)
{
    std::cout << "Builder::Builder (Cell* cell, int h, int p, bool isDigIn)" << std::endl;
    if(isDigIn)
    {
        digIn();
    }
}


Builder::~Builder()
{
    std::cout << "Builder::~Builder()" << std::endl;
}
//---------------------------------------------------
TankFactory* Builder::createTankFactory() const
{
    return new TankFactory(getCell());
}

BuilderFactory* Builder::createBuilderFactory() const
{
    return new BuilderFactory(getCell());
}
//---------------------------------------------------
int Builder::getPowerBonus() const
{
    /*Cell* cell = nullptr;
    cell = getCell();
    int res = 0;
    if (cell)
        res = Builder::powerBonus[cell->getCellLandscape()];
    else
        std::cout << "You are not in cell." << std::endl;
    return res;*/
    return Builder::powerBonus[getCell()->getCellLandscape()];
}

int Builder::getDefenceBonus() const
{
    /*
    Cell* cell = nullptr;
    cell = getCell();
    int res = 0;
    if (cell)
        res = Builder::defenceBonus[cell->getCellType()];
    else
        std::cout << "You are not in cell." << std::endl;
    return res;*/
    return Builder::defenceBonus[getCell()->getCellLandscape()];
}

int Builder::getDigInBonus() const
{
    /*Cell* cell = nullptr;
    cell = getCell();
    int res = 0;
    if (cell)
        res = Builder::digInBonus[cell->getCellType()];
    else
        std::cout << "You are not in cell." << std::endl;
    return res;*/
    return Builder::digInBonus[getCell()->getCellLandscape()];
}
