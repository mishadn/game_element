#ifndef CELL_H
#define CELL_H

#include "gameSets.h"
#include "Element.h"

class Cell
{
    public:
        ~Cell();
   //     Cell(elements::Elements, int, int, int);
        Cell(Element*, elements::Landscape, int, int, int, int);
    //    std::string getCellType();
        Element* getCellElementType() const;
        elements::Landscape getCellLandscape() const;
        void setBusy();
        void setEmpty();
        bool getBusy();
        void printInfo() const;
        int getX();
        int getY();
        int getZ();
        int getHight() const;

    private:
     //   elements::Elements cellType = elements::Earth;
        Element* cellElementType;
        elements::Landscape landscape;
        int x;
        int y;
        int z;
        int hight;
        bool busy = false;
};

#endif // CELL_H
