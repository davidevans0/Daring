#ifndef PERSONOBJECT_H
#define PERSONOBJECT_H

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
