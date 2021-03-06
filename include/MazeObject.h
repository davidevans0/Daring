#ifndef MAZEOBJECT_H
#define MAZEOBJECT_H

#include "types.h"

class MazeObject
{
    public:
        MazeObject();
        ~MazeObject() {}
        bool loadMaze();
        void displayMaze();
        void insertInMaze(int,int,char);
        char getFromMaze(int,int);
        char lookUp(int, int);
        char lookDown(int, int);
        char lookRight(int, int);
        char lookLeft(int, int);
        void killlook();

    private:
        char Maze[MAZEX][MAZEY];
        int cur_x;
        int cur_y;
        int pre_x;
        int pre_y;
        int look_x;
        int look_y;
        char pre_symbol;
};

#endif // MAZEOBJECT_H
