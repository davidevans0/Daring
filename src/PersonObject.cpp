
#include "types.h"
#include "PersonObject.h"

/*-------------------------------------------------------------
 Object PersonObject
 object is used to create player and implements motion once
 within the maze.
--------------------------------------------------------------*/
PersonObject::PersonObject(MazeObject* inMaze)
{
    xLoc = STARTX;
    yLoc = STARTY;
    Symbol = '0'; //default symbol
    inMaze->insertInMaze(xLoc,yLoc,Symbol);

}

bool PersonObject::moveup(MazeObject* inMaze, int amount, char& c)
{
    bool moved = false;

    c = inMaze->lookUp();
    if (c == FLOOR)
    {
        inMaze->insertInMaze(xLoc, yLoc, FLOOR)
        xLoc = xLoc - amount;
        inMaze->insertInMaze(xLoc, yLoc, FLOOR)
        moved = true;
    }
    else
    {
        moved = false;
    }
    return moved;
}

void PersonObject::movedown(MazeObject* inMaze, int amount)
{
    xLoc = xLoc + amount;
}

void PersonObject::moveleft(MazeObject* inMaze, int amount)
{
    yLoc = yLoc - amount;
}

void PersonObject::moveright(MazeObject* inMaze, int amount)
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

