
#include "types.h"
#include "PersonObject.h"
#include "MazeObject.h"

/*-------------------------------------------------------------
 Object PersonObject
 object is used to create player and implements motion once
 within the maze.
--------------------------------------------------------------*/
PersonObject::PersonObject()
{
}

bool PersonObject::initialize(MazeObject* inMaze, int x,int y,char c)
{
    if (inMaze->getFromMaze(x,y) == FLOOR)
    {
        xLoc = x;
        yLoc = y;
        Symbol = c; //default symbol
        inMaze->insertInMaze(xLoc,yLoc,Symbol);
        return true;
    }
    else return false;
}

bool PersonObject::moveup(MazeObject* inMaze, int amount, char& c)
{
    bool moved = false;

    c = inMaze->lookUp(xLoc, yLoc);
    if (c == FLOOR)
    {
        inMaze->insertInMaze(xLoc, yLoc, FLOOR);
        xLoc = xLoc - amount;
        inMaze->insertInMaze(xLoc, yLoc, Symbol);
        moved = true;
    }
    else
    {
        moved = false;
    }
    return moved;
}

bool PersonObject::movedown(MazeObject* inMaze, int amount, char& c)
{
    bool moved = false;

    c = inMaze->lookDown(xLoc, yLoc);
    if (c == FLOOR)
    {
        inMaze->insertInMaze(xLoc, yLoc, FLOOR);
        xLoc = xLoc + amount;
        inMaze->insertInMaze(xLoc, yLoc, Symbol);
        moved = true;
    }
    else
    {
        moved = false;
    }
    return moved;
}

bool PersonObject::moveleft(MazeObject* inMaze, int amount, char& c)
{
    bool moved = false;

    c = inMaze->lookLeft(xLoc, yLoc);
    if (c == FLOOR)
    {
        inMaze->insertInMaze(xLoc, yLoc, FLOOR);
        yLoc = yLoc - amount;
        inMaze->insertInMaze(xLoc, yLoc, Symbol);
        moved = true;
    }
    else
    {
        moved = false;
    }
    return moved;
}

bool PersonObject::moveright(MazeObject* inMaze, int amount, char& c)
{
    bool moved = false;

    c = inMaze->lookRight(xLoc, yLoc);
    if (c == FLOOR)
    {
        inMaze->insertInMaze(xLoc, yLoc, FLOOR);
        yLoc = yLoc + amount;
        inMaze->insertInMaze(xLoc, yLoc, Symbol);
        moved = true;
    }
    else
    {
        moved = false;
    }
    return moved;
}

void PersonObject::setsymbol (char xx)
{
    Symbol = xx;
}

char PersonObject::getsymbol ()
{
    return Symbol;
}

void PersonObject::setlocation(MazeObject* inMaze, int x, int y)
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

