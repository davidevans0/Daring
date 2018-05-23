#include "MazeObject.h"
#include "types.h"

#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>

#define MAZELOCATION ".//data//MazeData.txt"

using namespace std;

/*-------------------------------------------------------------
 Object MazeObject
Controls loading and drawing the maze, also controls
moving characters within the maze
--------------------------------------------------------------*/
MazeObject::MazeObject()
{
}

void MazeObject::insertInMaze(int x, int y, char c)
{
    Maze[x][y] = c;
}

char MazeObject::getFromMaze(int x, int y)
{
    return Maze[x][y];
}

// returns the character above current position
char MazeObject::lookUp(int x, int y)
{
    return Maze[x - SPEED][y];
}
// returns the character below current position
char MazeObject::lookDown(int x, int y)
{
    return Maze[x + SPEED][y];
}
// returns the character to the right current position
char MazeObject::lookRight(int x, int y)
{
    return Maze[x][y + SPEED];
}
// returns the character to the left current position
char MazeObject::lookLeft(int x, int y)
{
    return Maze[x][y - SPEED];
}

void MazeObject::killlook()
{
    Maze[look_x][look_y] = FLOOR;
}

//Loads a maze from a data file
bool MazeObject::loadMaze()
{
    string oneLine;
    ifstream MazeFile;

    MazeFile.open(MAZELOCATION);

    if (!MazeFile)
    {
        cout << "Maze file not found" << endl;
        return(0);
    }
    else
    {
        for (int x = 0; x < MAZEX; x++)
        {
            getline(MazeFile,oneLine);
            for (int y = 0; y < MAZEY; y++)
            {
                Maze[x][y] = oneLine[y];
            }
        }
    }
    MazeFile.close();
    return(1);
}

//Displays the maze
void MazeObject::displayMaze()
{
    //First, clear the console
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    cout << endl << endl;
    for (int x = 0; x < MAZEX; x++)
    {

        for (int y = 0; y < MAZEY; y++)
        {
            if (Maze[x][y] == PERSON)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                cout << Maze[x][y];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            }
            else if (Maze[x][y] == MURMONSTER)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
                cout << Maze[x][y];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            }
            else if (Maze[x][y] == GOMONSTER)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
                cout << Maze[x][y];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            }
            else if (Maze[x][y] == WRMONSTER)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
                cout << Maze[x][y];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            }
            else
            {
                cout << Maze[x][y];
            }
        }
        cout << endl;
    }
}
