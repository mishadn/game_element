#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include "gameSets.h"


class Element
{
    public:
 //       Element();

        virtual ~Element();
     //   virtual std::string getElementType() const;
        virtual elements::Elements getElementType() const;
    protected:
         Element(elements::Elements);
    private:
        const elements::Elements elementType;

};

#endif // ELEMENT_H
