
#include "types.h"
#include "PersonObject.h"

/*-------------------------------------------------------------
 Object PersonObject
 object is used to create player and implements motion once
 within the maze.
--------------------------------------------------------------*/
PersonObject::PersonObject()
{
    xLoc = STARTX;
    yLoc = STARTY;
    Symbol = '0'; //default symbol
}

void PersonObject::moveup(int amount)
{
    xLoc = xLoc - amount;
}

void PersonObject::movedown(int amount)
{
    xLoc = xLoc + amount;
}

void PersonObject::moveleft(int amount)
{
    yLoc = yLoc - amount;
}

void PersonObject::moveright(int amount)
{
    yLoc = yLoc + amount;
}

void PersonObject::setsymbol (char xx)
{
    Symbol = xx;
}

char PersonObject::getsymbol ()
{
    return Symbol;
}

void PersonObject::setlocation(int x, int y)
{
    xLoc = x;
    yLoc = y;
}

int PersonObject::getxlocation()
{
    return xLoc;
}

int PersonObject::getylocation()
{
    return yLoc;
}

