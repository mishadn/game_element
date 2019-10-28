#include "Element.h"
#include <iostream>
/*
Element::Element()
{
    std::cout << "Element::Element() elementType = " << elType << std::endl;
}
*/
Element::Element(elements::Elements eT) : elementType(eT)
{
    std::cout << "Element::Element(Elements::Elements eT) : elType(eT) = " << elementType << std::endl;

}

Element::~Element()
{
    std::cout << "Element::~Element()" << std::endl;
}
/*
std::string Element::getElementType() const
{
    std::string res = "";
    switch(elementType)
    {
        case elements::Air :
        {
            res = "Air";
            break;
        }
        case elements::Water :
        {
            res = "Water";
            break;
        }
        case elements::Earth :
        {
            res = "Earth";
            break;
        }
        case elements::Fire :
        {
            res = "Fire";
            break;
        }
        default :
        {
            res = "No Type of Element";
            break;
        }
    }
    return res;
}
*/

elements::Elements Element::getElementType() const
{
    return elementType;
}
