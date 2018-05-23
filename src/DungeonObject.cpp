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

#define GOBLINPROMPT ".//data//GoblinArt.txt"
#define MURLOCKPROMPT ".//data//MurlockArt.txt"
#define WRAITHPROMPT ".//data//WraithArt.txt"

using namespace std;
/*-------------------------------------------------------------
 Object DungeonObject
object creates monsters, prints intro, displays encounter text,
And moves player within dungeon maze.
--------------------------------------------------------------*/
// Constructor initializes all monster stats, as well as creating the maze, and inserting the player into maze
DungeonObject::DungeonObject()
{
    playerAccess = &Person;
    mazeAccess = &Maze;

    Maze.loadMaze();

    Person.setsymbol(PERSON);
    Maze.insertInMaze(Person.getxlocation(),Person.getylocation(),Person.getsymbol());

    Goblin1.setMonsterStats(30,10,5,"Dagger","Quick Stab","Goblin");
    Goblin2.setMonsterStats(30,20,5,"Dagger","Quick Stab","Goblin");
    Goblin3.setMonsterStats(30,20,5,"Dagger","Quick Stab","Goblin");

    Murlock1.setMonsterStats(40,20,10,"Trident","Water Spear","Murlock");
    Murlock2.setMonsterStats(40,25,10,"Trident","Water Spear","Murlock");
    Murlock3.setMonsterStats(40,25,10,"Trident","Water Spear","Murlock");
    Murlock4.setMonsterStats(40,25,10,"Trident","Water Spear","Murlock");
    Murlock5.setMonsterStats(40,25,10,"Trident","Water Spear","Murlock");

    Wraith1.setMonsterStats(20,6,30,"Poltergeist","Life Drain","Wraith");
    Wraith2.setMonsterStats(20,5,30,"Poltergeist","Life Drain","Wraith");
    Wraith3.setMonsterStats(20,5,30,"Poltergeist","Life Drain","Wraith");
    Wraith4.setMonsterStats(20,5,30,"Poltergeist","Life Drain","Wraith");
    Wraith5.setMonsterStats(20,5,30,"Poltergeist","Life Drain","Wraith");
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
    Person.setheroName(nameTemp);
    cout << endl << "Welcome, " << Person.getheroName() << " to the DARING DUNGEON!" << endl << endl;

    while (!goodInput)
    {
        cout << "Please enter the number of your desired HERO class: " << endl << endl;
        cout << "1. Warrior Lord" << endl << "2. Arch Mage" << endl << "3. Master Thief" << endl;
        cin >> classInt;

        switch(classInt)
        {
            case '1':
                cout << "You have chosen Warrior Lord !" << endl << endl;
                Person.setPlayerStats(30,110,10,"Sword","Shield", "Shield Bash");
                Person.setCharType("Warrior Lord");
                goodInput = true;
                break;
            case '2':
                cout << "You have chosen Arch Mage !" << endl << endl;
                Person.setPlayerStats(10,80,50,"Staff","Dagger", "Incinerate");
                Person.setCharType("Arch Mage");
                goodInput = true;
                break;
            case '3':
                cout << "You have chosen Master Thief !" << endl << endl;
                Person.setPlayerStats(20,70,40,"Short Sword","Shuriken", "Shadow Slice");
                Person.setCharType("Master Thief");
                goodInput = true;
                break;
            default:
                cout << "Invalid Input" << endl;
                goodInput = false;
                break;
        }

    }

    cout << Person.getheroName() << " your starting stats are as follows: " << endl << endl;
    Person.showStats();

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
    cout <<"Prepare thine self " << Person.getheroName() << ", you may now enter my lair! MWAHAHAHAHAA" << endl << endl;
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
    Maze.killlook();
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
            if (Maze.lookUp() == FLOOR)
            {
                Person.moveup(SPEED);
            } else hit_symbol = Maze.lookUp();
            break;
        case 'D':
            if (Maze.lookDown() == FLOOR)
            {
                Person.movedown(SPEED);
            } else hit_symbol = Maze.lookDown();
            break;
        case 'L':
            if (Maze.lookLeft() == FLOOR)
            {
                Person.moveleft(SPEED);
            } else hit_symbol = Maze.lookLeft();
            break;
        case 'R':
            if (Maze.lookRight() == FLOOR)
            {
                Person.moveright(SPEED);
            } else hit_symbol = Maze.lookRight();
            break;
    }
    Maze.moveInMaze(Person.getxlocation(),Person.getylocation(),Person.getsymbol());
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