#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "types.h"
#include "MazeObject.h"
#include "PersonObject.h"
#include "DungeonObject.h"
#include "cPlayer.h"
#include "CombatObject.h"

using namespace std;

int main()
{
    InputActions xInput = STANDSTILL;
    DungeonObject Dare;

    Dare.intro();

    while (xInput != QUIT)
    {
        Dare.DungeonDisplay();
        xInput = Dare.GetPlayerInput();

        if (xInput == ENCOUNTER)
        {
            //Player State returns 0 if player died
            Dare.displayEncounter();
            if (Dare.getplayerState() == 0)
            {
                system("cls");
                // flashed red game over text five times
                for (int x=1; x<5; x++)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    cout << endl << endl << endl << endl;
                    cout << "YOU HAVE DIED" << endl;
                    Sleep(300);
                    system("cls"); // clears console
                    Sleep(300);
                }
                 break;
            }
             //Player State returns 2 if player wins
            else if (Dare.getplayerState() == 2)
            {
                system("cls");
                // flashed green game over text five times
                for (int x=1; x<5; x++)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
                    cout << endl << endl << endl << endl;
                    cout << "YOU WIN" << endl;
                    Sleep(300);
                    system("cls"); // clears console
                    Sleep(300);
                }
                break;
            }
        }
    }
}
