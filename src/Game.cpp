#include "Game.h"
#include <string>
#include "Factory.h"
#include "BuilderFactory.h"
#include "Builder.h"
#include "Unit.h"
#include "Cell.h"
#include "CellsMap.h"
#include <fstream>
#include <string.h>


void Game::saveGame(std::ofstream &fileOut)
{

}

void Game::saveGamer(Gamer* gamer, std::ofstream &fileOut)
{
    std::deque<Unit*>* units = gamer->getUnits();
    for(std::deque<Unit*>::iterator u = units->begin(); u != units->end(); u++)
    {
        saveObjects((*u), fileOut, gamer->getName());
    }

    std::deque<Factory*>* factories = gamer->getFactories();
    for(std::deque<Factory*>::iterator f = factories->begin(); f != factories->end(); f++)
    {
        saveObjects((*f), fileOut, gamer->getName());
    }
    //outFile.close();
}


Unit* Game::loadUnit(units::UnitTypes unitType, units::Units unit, int x, int y, int z, int health, int power, int isDigIn, CellsMap* cellsMap)
{
    std::cout << "create unit..." << std::endl;
    Unit* res;
    switch(unit)
    {
    case units::Tank :
    {
        res = new Tank(cellsMap->cell[x][y][z], health, power, isDigIn);
        std::cout << "unit Tank created" << std::endl;
        break;
    }
    case units::Builder :
    {
        res = new Builder(cellsMap->cell[x][y][z], health, power, isDigIn);
        std::cout << "unit Builder created" << std::endl;
        break;
    }
    }
    return res;
}

Factory* Game::loadFactory(factory::FactoryTypes factoryType, factory::Factorys factory, int x, int y, int z, int health, int power, int isDigIn, CellsMap* cellsMap)
{
    std::cout << "create factory..." << std::endl;
    Factory* res;
    switch(factory)
    {
    case factory::Tank:
    {
        res = new TankFactory(cellsMap->cell[x][y][z], health, power, isDigIn);
        std::cout << "Tank factory created" << std::endl;
        break;
    }
    case factory::Builder :
    {
        res = new BuilderFactory(cellsMap->cell[x][y][z], health, power, isDigIn);
        std::cout << "Builder factory created" << std::endl;
        break;
    }
    }
    return res;

}

Game* Game::loadGame(std::string fileInName)
{
    //Game* game = new Game("first game", cellsMap);
    std::ifstream fileIn;
    std::cout << "fileInName = " << fileInName << std::endl;
    fileIn.open(fileInName);
    while(!fileIn.eof())
    {
        //  std::string strIn;
        char buff[100];
        char* pch;
        pch = "";
        char* gamerName;
        gamerName = "";
        fileIn.getline(buff, 100);
        std::string strBuff = buff;
        //strBuff.lenght();
        if(strBuff.empty())
        {
            break;
        }
        std::string strGamerName = "";
        std::string strCurrGamerName = "";
        //    strIn = buff;
        std::cout << " load game buff = " << buff << std::endl << std::endl;
        pch = strtok(buff, ";");
        strGamerName = pch;
        std::cout << " gamer is " << strGamerName << std::endl;
        std::cout << " gamerName before if " << strCurrGamerName << std::endl;
        if(strGamerName != strCurrGamerName)
        {
            std::cout << " old gamer is " << strCurrGamerName << std::endl;
            std::cout << " gamer is " << strGamerName << std::endl;
            strCurrGamerName = strGamerName;
            loadGamer(strCurrGamerName);
            std::cout << "after create gamer " << std::endl;
            pch = strtok(nullptr, ";");
            takeGamer(strCurrGamerName);
        }


        std::cout << " For gamer  " << strCurrGamerName << std::endl;
   //     pch = strtok(nullptr, ";");
        if (strcmp(pch, "Unit") == 0)
            //while (pch)
        {
            std::cout << pch << " - Unit" << std::endl;
            //std::cout << "NULL = " << NULL << std::endl;
            pch = strtok(nullptr, ";");
            units::UnitTypes unitType = units::intToUnitTypes(atoi(pch));
            std::cout << "unitType = " << units::getUnitTypeName(unitType) << std::endl;
            pch = strtok(nullptr, ";");
            units::Units unit = units::intToUnits(atoi(pch));
            std::cout <<units::getUnitName(unit) << std::endl;
            pch = strtok(nullptr, ";");
            int x = atoi(pch);
            std::cout << "x = " << x << std::endl;
            pch = strtok(nullptr, ";");
            int y = atoi(pch);
            std::cout << "y = " << y << std::endl;
            pch = strtok(nullptr, ";");
            int z = atoi(pch);
            std::cout << "z = " << z << std::endl;
            pch = strtok(nullptr, ";");
            int health = atoi(pch);
            std::cout << "health = " << health << std::endl;
            pch = strtok(nullptr, ";");
            int power = atoi(pch);
            std::cout << "power = " << power << std::endl;
            pch = strtok(nullptr, ";");
            bool isDigIn = atoi(pch);
            std::cout << "isDigIn = " << std::boolalpha << isDigIn << std::endl;

            getCurrGamer()->pushUnit(loadUnit(unitType, unit, x, y, z, health, power, isDigIn, cellsMap));

            //Unit* u01 = loadUnit(unitType, unit, x, y, z, health, power, isDigIn, cellsMap);
            //u01->printInfo();
            //    std::cout << "u01->getPowerBonus() = " << u01->getPowerBonus() << std::endl;

        }
        else
        {
        if (strcmp(pch, "Factory") == 0)
        {
            std::cout << pch << " - Factory " << std::endl;
            //std::cout << "NULL = " << NULL << std::endl;
            pch = strtok(nullptr, ";");
            factory::FactoryTypes FactoryType = factory::intToFactoryTypes(atoi(pch));
            std::cout << factory::getFactoryTypeName(FactoryType) << std::endl;
            pch = strtok(nullptr, ";");
            factory::Factorys factoryName = factory::intToFactory(atoi(pch));
            std::cout << factory::getFactoryName(factoryName) << std::endl;
            pch = strtok(nullptr, ";");
            int x = atoi(pch);
            std::cout << "x = " << x << std::endl;
            pch = strtok(nullptr, ";");
            int y = atoi(pch);
            std::cout << "y = " << y << std::endl;
            pch = strtok(nullptr, ";");
            int z = atoi(pch);
            std::cout << "z = " << z << std::endl;
            pch = strtok(nullptr, ";");
            int health = atoi(pch);
            std::cout << "health = " << health << std::endl;
            pch = strtok(nullptr, ";");
            int power = atoi(pch);
            std::cout << "power = " << power << std::endl;
            pch = strtok(nullptr, ";");
            bool isDigIn = atoi(pch);
            std::cout << "isDigIn = " << std::boolalpha << isDigIn << std::endl;

            getCurrGamer()->pushFactory(loadFactory(FactoryType, factoryName, x, y, z, health, power, isDigIn, cellsMap));

           // game->getCurrGamer()->pushUnit(loadUnit(unitType, unit, x, y, z, health, power, isDigIn, cellsMap));

        }
        }
    }
    fileIn.close();
    std::cout << "close file" << std::endl;
    return this;

}

//void saveGamer(Gamer*, std::ofstream &);

Game::Game(std::string n, CellsMap* cm) : name(n), cellsMap(cm)
{
    std::cout << "Game::Game(std::string n) : name(n) " << name << std::endl;
    gamers = new std::map <std::string, Gamer*>;

}

Game::~Game()
{
    std::cout << "Game::~Game()" << std::endl;
}

std::string Game::getName() const
{
    return name;
}

void Game::createGamer(std::string n, Cell* c)
{
    Gamer* gamer = new Gamer(n, cellsMap);
    gamers->insert(std::pair<std::string, Gamer*>(n, gamer));
    gamer->createBuilder(c);
}

void Game::loadGamer(std::string n)
{
    Gamer* gamer = new Gamer(n, cellsMap);
    gamers->insert(std::pair<std::string, Gamer*>(n, gamer));
}

void Game::printGamers() const
{
    int i = 0;
    std::cout << "number of gamers is: " << gamers->size() << std::endl;
    for(std::map<std::string, Gamer*>::iterator g = gamers->begin(); g != gamers->end(); g++, i++)
    {
        std::cout << " - gamer: " << i << " - ";
        std::cout << g->first << " : " << g->second->getName();

        g->second->printObjectsStatusLine();
        std::cout << std::endl;
    }
}

void Game::startGame()
{
    char yn = 'Y';
    while(true)
    {

    for(std::map<std::string, Gamer*>::iterator g = gamers->begin(); g != gamers->end(); g++)
    {
        std::cout << g->first << " : " << g->second->getName() << std::endl;
        currGamer = g->second;
        currGamer->printObjectsStatusLine();
        currGamer->selectGameObject();
        currGamer->selectObjectAction();

        //---------------------------------------------------

            std::ofstream outFile;
            std::ofstream &oFile = outFile;
            outFile.open("saveObjects001.ttt");

            for(std::map<std::string, Gamer*>::iterator g = gamers->begin(); g != gamers->end(); g++)
            {
               saveGamer(g->second, oFile);
            }
            outFile.close();
        //---------------------------------------------------

        currGamer->printObjectsStatusLine();
    }
    std::cout << " next step? (Y/N)";
        std::cin >> yn;
        if (yn == 'N' || yn == 'n')
        {
            std::cout << "yn = " << yn << std::endl;

            break;
        }
    }

    std::ofstream outFile;
    std::ofstream &oFile = outFile;
    outFile.open("saveObjects001.ttt");

    for(std::map<std::string, Gamer*>::iterator g = gamers->begin(); g != gamers->end(); g++)
    {
        saveGamer(g->second, oFile);
    }
    outFile.close();


}

void Game::takeGamer(std::string nameGamer)
{
    currGamer = gamers->at(nameGamer);
}

Gamer* Game::getCurrGamer() const
{
    return currGamer;
}
