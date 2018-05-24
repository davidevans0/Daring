#ifndef PERSONOBJECT_H
#define PERSONOBJECT_H

#include "MazeObject.h"

class PersonObject
{
    public:
        PersonObject();
        ~PersonObject() {}

        void initialize(MazeObject*, int, int, char);
        bool moveup(MazeObject*,int, char&);
        bool movedown(MazeObject*,int, char&);
        bool moveleft(MazeObject*,int, char&);
        bool moveright(MazeObject*,int, char&);
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
