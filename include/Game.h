#ifndef GAME_H
#define GAME_H

#include <string>
#include "Gamer.h"
#include <map>
#include "Cell.h"
#include "CellsMap.h"
#include <fstream>

class Game
{
    public:
        Game(std::string, CellsMap*);
        virtual ~Game();
    std::string getName() const;
    void createGamer(std::string, Cell*);
    void loadGamer(std::string);
    void printGamers() const;
    void takeGamer(std::string);
    Gamer* getCurrGamer() const;
    Game* loadGame(std::string);
    void saveGame(std::ofstream &);
    //   Gamer* getGamer(std::string) const;
    void startGame();
private:
    Unit* loadUnit(units::UnitTypes, units::Units, int, int, int, int, int, int, CellsMap*);
    Factory* loadFactory(factory::FactoryTypes, factory::Factorys, int, int, int, int, int, int, CellsMap*);
    std::string name;
    std::map <std::string, Gamer*>* gamers;
    Gamer* currGamer;
    CellsMap* cellsMap;
    void saveGamer(Gamer*, std::ofstream &);
    template <class O> void saveObjects(O* object, std::ofstream &fileOut, std::string gamerName)
    {
        fileOut << gamerName << ";" << object->toString() << std::endl;
    };

};

#endif // GAME_H
