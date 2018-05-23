#ifndef PERSONOBJECT_H
#define PERSONOBJECT_H

#define STARTX 18
#define STARTY 4

class PersonObject
{
    public:
        PersonObject();
        ~PersonObject() {}
        void moveup(int);
        void movedown(int);
        void moveleft(int);
        void moveright(int);
        void setsymbol(char);
        char getsymbol();
        void setlocation(int,int);
        int getxlocation();
        int getylocation();

    private:
        int xLoc;
        int yLoc;
        char Symbol;
};

#endif // PERSONOBJECT_H
