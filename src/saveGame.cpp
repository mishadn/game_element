#include "Unit.h"
#include <fstream>
#include "Gamer.h"
#include "Factory.h"
#include "Unit.h"


void saveUnit(Unit* unit)
{
    std::ofstream fileOut;
    fileOut.open("save001.ttt");
    fileOut << unit->toString();// << std::endl;
    fileOut.close();
}

template <class O>
void saveObjects(O* object, std::ofstream &fileOut, std::string gamerName)
{
    fileOut << gamerName << ";" << object->toString() << std::endl;
}

void saveGamer(Gamer* gamer, std::ofstream &fileOut)
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

