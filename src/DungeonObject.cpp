#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "types.h"

#include "PersonObject.h"
#include "CombatObject.h"
#include "DungeonObject.h"

using namespace std;
/*-------------------------------------------------------------
Object DungeonObject
object creates monsters, prints intro, displays encounter text,
And moves player within dungeon maze.
--------------------------------------------------------------*/
// Constructor initializes all monster stats, as well as creating the maze, and inserting the player into maze
DungeonObject::DungeonObject()
{
    playerAccess = &PlayerOne;
    mazeAccess = &Maze;
    bool in_ok = false;
    int in_type = 0;
    char c_type;

    Maze.loadMaze();

    PlayerOne.initialize(mazeAccess,STARTX,STARTY,PERSON);

    //Populate the dungeon with monsters
    for (int x = 0; x < MON_POPULATION; x++)
    {
        in_type = rnd.rand_1to3();
        switch (in_type)
       {
            case 1:
                monsterArray[x].setMonsterStats(30,10,5,"Dagger","Quick Stab","Goblin");
                c_type = GOMONSTER;
                break;
            case 2:
                monsterArray[x].setMonsterStats(40,20,10,"Trident","Water Spear","Murlock");
                c_type = MURMONSTER;
                break;
           case 3:
                monsterArray[x].setMonsterStats(20,6,30,"Poltergeist","Life Drain","Wraith");
                c_type = WRMONSTER;
                break;
        }

        in_ok = false;
        while (!in_ok)
        {
            in_ok = monsterArray[x].initialize(mazeAccess, rnd.rand_location_x(), rnd.rand_location_y(), c_type);
        }
    }

    Goblin1.setMonsterStats(30,10,5,"Dagger","Quick Stab","Goblin");
    Murlock1.setMonsterStats(40,20,10,"Trident","Water Spear","Murlock");
    Wraith1.setMonsterStats(20,6,30,"Poltergeist","Life Drain","Wraith");
}

DungeonObject::~DungeonObject()
{
}

// Prints out beginning prompts and art, asks player for unique inputs about character
void DungeonObject::intro()
{
    char classInt;
    string nameTemp;
    bool goodInput = false;

    cout << "Please enter name of your HERO: ";
    getline (cin, nameTemp);
    PlayerOne.setheroName(nameTemp);
    cout << endl << "Welcome, " << PlayerOne.getheroName() << " to the DARING DUNGEON!" << endl << endl;

    while (!goodInput)
    {
        cout << "Please enter the number of your desired HERO class: " << endl << endl;
        cout << "1. Warrior Lord" << endl << "2. Arch Mage" << endl << "3. Master Thief" << endl;
        cin >> classInt;

        switch(classInt)
        {
            case '1':
                cout << "You have chosen Warrior Lord !" << endl << endl;
                PlayerOne.setPlayerStats(30,110,10,"Sword","Shield", "Shield Bash");
                PlayerOne.setCharType("Warrior Lord");
                goodInput = true;
                break;
            case '2':
                cout << "You have chosen Arch Mage !" << endl << endl;
                PlayerOne.setPlayerStats(10,80,50,"Staff","Dagger", "Incinerate");
                PlayerOne.setCharType("Arch Mage");
                goodInput = true;
                break;
            case '3':
                cout << "You have chosen Master Thief !" << endl << endl;
                PlayerOne.setPlayerStats(20,70,40,"Short Sword","Shuriken", "Shadow Slice");
                PlayerOne.setCharType("Master Thief");
                goodInput = true;
                break;
            default:
                cout << "Invalid Input" << endl;
                goodInput = false;
                break;
        }

    }

    cout << PlayerOne.getheroName() << " your starting stats are as follows: " << endl << endl;
    PlayerOne.showStats();

    system("PAUSE");
    // start of the game
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    cout <<"p---------------------------,--.--"<< endl;
    cout <<"p--------------------------{    }-"<< endl;
    cout <<"p--------------------------K,   }-"<< endl;
    cout <<"p-------------------------/  `Y`--"<< endl;
    cout <<"p---------------------_  /   /----"<< endl;
    cout <<"p--------------------{_'-K._/-----"<< endl;
    cout <<"p---------------------`/-.__L._---"<< endl;
    cout <<"p---------------------/  ' /`\\_}-"<< endl;
    cout <<"p--------------------/  ' /-------"<< endl;
    cout <<"p------------____ --/  ' /--------"<< endl;
    cout <<"p-----,-'~~~~    ~~/  ' /_--------"<< endl;
    cout <<"p---,'             ``~~~%%',------"<< endl;
    cout <<"p--(                     %  Y-----"<< endl;
    cout <<"p-{                      %% I-----"<< endl;
    cout <<"p{      -                 %  `----"<< endl;
    cout <<"p|       ',                %  )---"<< endl;
    cout <<"p|        |   ,..__      __. Y----"<< endl;
    cout <<"p|    .,_./  Y ' / ^Y    J   )|---"<< endl;
    cout <<"p-\\           |' /   |   |   ||---"<< endl;
    cout <<"p--\\          L_/    . _ (_,.'(---"<< endl;
    cout <<"p---\\,   ,      ^^""' / |     )-----"<< endl;
    cout <<"p-----\\_  \\          /,L]    /----"<< endl;
    cout <<"p-----'-_`-,       ` `    ./`-----"<< endl;
    cout <<"p-------`-(_             )--------"<< endl;
    cout <<"p----------^^\\..___,.--`----------"<< endl << endl;
    cout <<"Prepare thine self " << PlayerOne.getheroName() << ", you may now enter my lair! MWAHAHAHAHAA" << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
    system("PAUSE");
}

// after encounter is detected
bool DungeonObject::displayEncounter()
{
    ifstream monsterArt;
    string artLine, monString;
    bool playerDead = false;
    playerState = 1;

    switch (encounter)
    {
        case GOMONSTER: // opens ACII art for Goblin encounter
            monString = "Goblin";
            monsterArt.open(GOBLINPROMPT);
            if (!monsterArt)
            {
                cout << "Monster file not found" << endl;
            }
            else
            {
                for (int x = 0; x < 13; x++)
                {
                    getline(monsterArt,artLine);
                    cout << artLine << endl;
                }
                monsterArt.close();
            }
            cout << "   A " << monString << " suddenly appears!!" << endl;
            monsterAccess = &Goblin1;
            playerDead = Combat.doCombat(playerAccess,Goblin1); // unique monster combat call
            if(playerDead)
            {
                playerState = 0;
            }
            break;

        case MURMONSTER: // opens ACII art for Murlock encounter
            monString = "Murlock";

            monsterArt.open(MURLOCKPROMPT);
            if (!monsterArt)
            {
                cout << "MurlockArt file not found" << endl;
            }
            else
            {
                for (int x = 0; x < 13; x++)
                {
                    getline(monsterArt,artLine);
                    cout << artLine << endl;
                }
                monsterArt.close();
            }
            cout << "   A " << monString << " suddenly appears!!" << endl;
            monsterAccess = &Murlock1;
            playerDead = Combat.doCombat(playerAccess,Murlock1); // unique monster combat call
            if(playerDead)
            {
                playerState = 0;
            }
            break;

        case WRMONSTER: // opens ACII art for Wraith encounter
            monString = "Wraith";

            monsterArt.open(WRAITHPROMPT);
            if (!monsterArt)
            {
                cout << "WraithArt file not found" << endl;
            }
            else
            {
                for (int x = 0; x < 13; x++) // prints out the art
                {
                    getline(monsterArt,artLine);
                    cout << artLine << endl;
                }
                monsterArt.close();
            }
            cout << "   A " << monString << " suddenly appears!!" << endl;
            monsterAccess = &Wraith1;
            playerDead = Combat.doCombat(playerAccess,Wraith1); // unique monster combat call
            if(playerDead)
            {
                playerState = 0;
            }
            break;

        case EXIT:
            cout << endl;
            playerState = 2;
    }
    return playerDead;
}

void DungeonObject::DungeonDisplay()
{
    Maze.displayMaze();
}

//Will move the passed in person in the dungeon. Will return true if they encountered something.
bool DungeonObject::MovePerson(char str)
{
    bool encountered = false;
    char hit_symbol = ' ';

    switch (str)
    {
        case 'U':
            PlayerOne.moveup(mazeAccess, SPEED, hit_symbol);
            break;
        case 'D':
            PlayerOne.movedown(mazeAccess, SPEED, hit_symbol);
            break;
        case 'L':
            PlayerOne.moveleft(mazeAccess, SPEED, hit_symbol);
            break;
        case 'R':
            PlayerOne.moveright(mazeAccess, SPEED, hit_symbol);
            break;
    }
    //We hit the wall which is not an encounter
    if ((hit_symbol != WALL) && (hit_symbol != FLOOR) && (hit_symbol != HWALL) && (hit_symbol != UWALL))
    {
        encountered = true;
        encounter = hit_symbol; //member variable to pass out
    }
    return encountered;
}

InputActions DungeonObject::GetPlayerInput()
{
    InputActions x = MOVE;
    bool didWeEncounter = false;
    int c = 0;

    c = _getch();
    if (c == KEY_EXTRA) c = _getch(); //Strip out extra character input that happens when an arrow key is hit
    switch(c)
    {
        case KEY_UP:                            //key up
            didWeEncounter = MovePerson('U');
            break;
        case KEY_DOWN:
            didWeEncounter = MovePerson('D');   // key down
            break;
        case KEY_LEFT:
            didWeEncounter = MovePerson('L');  // key left
            break;
        case KEY_RIGHT:
            didWeEncounter = MovePerson('R');  // key right
            break;
        case 'q':
            //Quit the program
            x = QUIT;
            break;
        default:
            break;
    }
    if (didWeEncounter) x = ENCOUNTER;
    return x;
}
