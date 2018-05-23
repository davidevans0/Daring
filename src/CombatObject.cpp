#include "types.h"

#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "CombatObject.h"
#include "PersonObject.h"
#include "cPlayer.h"
/*-------------------------------------------------------------
 Object CombatObject
 object is used to resolve combat encounters from the maze
 determines if game continues or ends at end of combat.
--------------------------------------------------------------*/
bool CombatObject::doCombat(cPlayer* comPerson, Monster comMon)
{
    int dmgSave;
    string weaponSave;
    int dmgTempH;
    int healthTempH;
    int dmgTempM;
    int healthTempM;
    string nameTemp;
    char weaponChoice;
    string weaponReturn;

    bool choiceFlag = true;

    //Prompts user for choice of weapon used in combat below
   while (choiceFlag)
   {
        cout << "What weapon action would you like to use?" << endl;
        cout << "(R) for right hand, (L) for left, (S) for spell," << endl;
        cin >> weaponChoice;

        switch(weaponChoice)
        {
            case 'R':
            case 'r':
                cout << comPerson->getheroName() << " used " << comPerson->getRightHand() << endl << endl;
                dmgSave = comPerson->getAttackDmg();
                weaponSave = comPerson->getRightHand();
                break;

            case 'L':
            case 'l':
                cout << comPerson->getheroName() << " used " << comPerson->getLeftHand() << endl << endl;
                dmgSave = comPerson->getAttackDmg() - WEAKNESS;
                weaponSave = comPerson->getLeftHand();
                break;

            case 'S':
            case 's':
                cout << comPerson->getheroName() << " used " << comPerson->getSpell() << endl << endl;
                dmgSave = comPerson->getMagicDmg();
                weaponSave = comPerson->getSpell();
                break;

            default:
                cout << "Invalid input" << endl << endl;
        }
        choiceFlag = false;
    }
    system("cls");
    while((comPerson->getHealth() > 0) && (comMon.getHealth() > 0))
    {
        //Human Attacks
        dmgTempH = (dmgSave - randomMachine.rand_1to6());
        cout << weaponSave << " does " << dmgTempH << " points of DMG" << endl << endl;
        healthTempM = comMon.getHealth() - dmgTempH;
        if (healthTempM < 0) healthTempM = 0;
        comMon.setHealth(healthTempM);
        cout << comMon.getMonName() << "'s Health is set to " << comMon.getHealth() << endl << endl;

        //Monster Attacks
        dmgTempM = (comMon.getAttackDmg() - randomMachine.rand_1to6());
        cout << comMon.getMonName() << " now strikes back, doing " << dmgTempM << " points of DMG" << endl << endl;
        healthTempH = comPerson->getHealth() - dmgTempM ;
        if (healthTempH < 0) healthTempH = 0;
        comPerson->setHealth(healthTempH);
        cout << comPerson->getheroName() << "'s Health is set to " << comPerson->getHealth() << endl << endl;

        //Show results
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
        cout << comPerson->getheroName() << "'s stats are: "<< endl;
        comPerson->showStats();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        cout << comMon.getMonName() << "'s stats are: "<< endl;
        comMon.showStats();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        system("PAUSE");
        system("cls");
    }
    //returns true is player dies,  false for monster death
    if (comPerson->getHealth() <= 0) return true;
    else return false;
}
