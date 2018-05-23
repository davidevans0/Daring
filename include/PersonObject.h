#ifndef PERSONOBJECT_H
#define PERSONOBJECT_H

#include "MazeObject.h"

class PersonObject
{
    public:
        PersonObject(MazeObject*);
        ~PersonObject() {}
        void moveup(MazeObject*,int, char&);
        void movedown(MazeObject*,int, char&);
        void moveleft(MazeObject*,int, char&);
        void moveright(MazeObject*,int, char&);
        void setsymbol(char);
        char getsymbol();
        void setlocation(MazeObject*,int,int);
        int getxlocation();
        int getylocation();

    private:
        int xLoc;
        int yLoc;
        char Symbol;
};

#endif // PERSONOBJECT_H
