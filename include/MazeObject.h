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
        void moveInMaze(int,int,char);
        char lookUp();
        char lookDown();
        char lookRight();
        char lookLeft();
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
