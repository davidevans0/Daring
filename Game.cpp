#include <iostream>
#include <cstdlib>
#include "cPlayer.h"

using namespace std;
string Map[100000];

void showMap()
    {
        Map[1] =" _________________________|-----|__________________________";
        Map[2] =" |   ____________/                             |          |";
        Map[3] =" |  /                        X            _____       ?   |";
        Map[4] =" | /   ?                                 /     |    ______|";
        Map[5] =" |/________      _________      ________/      |   |      |";
        Map[6] =" |         |    |         |    |               |   |      |";
        Map[7] =" |         |    |         |    |               |   |      |";
        Map[8] =" |         |    |         |    |               |   |      |";
        Map[9] =" -\\        \\   \\          |    |               |   |      /";
        Map[10] =" --\\        \\   \\         |    |               |   |     /";
        Map[11] =" ---|       |   |         |    |               |   |    |";
        Map[13] =" ---|       |   |         |    |               |   |    |";
        Map[14] =" ---|       |   |         |    |               |   |    |";
        Map[15] =" ---|       |   |         |    |               |   |    |";
        Map[16] =" ---|       |   |         |    |_______        |   |    |";
        Map[17] =" ---|       |   |         |    |       |       /   /    |";
        Map[18] =" ---|       |   |         |         ?  |      /   /     |";
        Map[19] =" ---|      /    /         |    |_______|     /   /      |";
        Map[20] =" ---|     /    /          |    |             |   |      |";
        Map[21] ="-----\\    |    |          |    |             |   |     /";
        Map[22] ="------\\   |    |          |    |             |   |    / ";
        Map[23] ="------/   |    |          |    |             |   |    \\ ";
        Map[24] ="-----/   /    /           |    |             |   |     \\";
        Map[25] ="-----|   |    |           |    |             |   |      | ";
        Map[26] ="-----|   |    |___________|    |_____________|   |      | ";
        Map[27] ="-----|   |                                       |      | ";
        Map[28] ="-----|   |________________      _________________|      | ";
        Map[29] ="-----|                    |    |                        | ";
        Map[30] ="-----|                    |    |                        | ";
        Map[31] ="-----|____________________|    |________________________| ";
  }



/*struct Player
{
    string charType;
    int Health;
    int AttackDmg;
    int MagicDmg;
    string RightHand;
    string LeftHand;
    string Spell;
};*/

struct Goblin
{
    int Health;
    int AttackDmg;
    string Weapon;
}Gobo1, Gobo2;

struct Spirit
{
    int Health;
    int MagicDmg;
    string Spell;
}Spir1, Spir2;

struct Murlock
{
    int Health;
    int AttackDmg;
    string Weapon;
}Mur1, Mur2;

int main()
{
    char inputChar;
    int classInt;
    string nameTemp;
    bool goodInput = false;

    cPlayer playerOne;

    Gobo1.AttackDmg = 20;
    Gobo1.Health = 20;
    Gobo1.Weapon = "Crude Dagger";

    Gobo2.AttackDmg = 20;
    Gobo2.Health = 20;
    Gobo2.Weapon = "Crude Dagger";

    Spir1.Health = 30;
    Spir1.MagicDmg = 30;
    Spir1.Spell = "Life Drain";

    Spir2.Health = 30;
    Spir2.MagicDmg = 30;
    Spir2.Spell = "Life Drain";

    Mur1.Health = 15;
    Mur1.AttackDmg = 15;
    Mur1.Weapon = "Trident";

    Mur2.Health = 15;
    Mur2.AttackDmg = 15;
    Mur2.Weapon = "Trident";

    cout << "Please enter name of your HERO: " << endl;
    cin >> nameTemp;
    playerOne.setheroName(nameTemp);
    cout << "Welcome, " << playerOne.getheroName() << " to the lair of hell!" << endl << endl;

    while (!goodInput)
    {
        cout << "Please enter the number of your desired HERO class: " << endl << endl;
        cout << "1. Warrior Lord" << endl << "2. Arch Mage" << endl << "3. Master Thief" << endl;
        cin >> classInt;

        switch(classInt)
        {
            case 1:
                cout << "You have chosen Warrior Lord !" << endl << endl;
                playerOne.setCharType("Warrior Lord");
                playerOne.setHealth(110);
                playerOne.setAttackDmg(70);
                playerOne.setMagicDmg(10);
                playerOne.setLeftHand("Sword");
                playerOne.setRightHand("Shield");
                playerOne.setSpell("Shield Bash");
                goodInput = true;
                break;
            case 2:
                cout << "You have chosen Arch Mage !" << endl << endl;
                playerOne.setCharType("Arch Mage");
                playerOne.setHealth(80);
                playerOne.setAttackDmg(20);
                playerOne.setMagicDmg(100);
                playerOne.setRightHand("Staff");
                playerOne.setLeftHand("Dagger");
                playerOne.setSpell("Incinerate");
                goodInput = true;
                break;
            case 3:
                cout << "You have chosen Master Thief !" << endl << endl;
                playerOne.setCharType("Master Thief");
                playerOne.setHealth(70);
                playerOne.setAttackDmg(50);
                playerOne.setMagicDmg(40);
                playerOne.setRightHand("Short Sword");
                playerOne.setLeftHand("Dagger");
                playerOne.setSpell("Shadow Slice");
                goodInput = true;
                break;
            default:
                cout << "Invalid Input" << endl;
                goodInput = false;
                break;
        }

    }

    cout << playerOne.getheroName() << " your starting stats are as follows: " << endl << endl;
    playerOne.showStats();

    system("PAUSE");

    cout <<"Prepare thine self " << playerOne.getheroName() << ", you may now enter my lair! MWAHAHAHAHAA" << endl << endl;
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

    system("PAUSE");

    while(1)
    {
        cout << "Input action (M)'Map',(C)'combat',(S)'stats', or (Q)'to quit'" << endl;
        cin >> inputChar;


        switch(inputChar)
        {
            case 'M':
            case 'm':
                showMap();
                break;
            case 'C':
            case 'c':
                combatPrompt(playerOne.getheroName(),classInt);
                break;
            case 'S':
            case 's':
                playerOne.showStats();
                break;
            case 'Q':
            case 'q':
                return 0;
            default:
                cout << "Invalid Entry" << endl;
        }
        return 0;
    }
}



  /*
    cout << "You step through the door marked as 'HELL'S GATE' and as your eyes adjust to the darkness, you see three things" << endl;
    cout << "directly in front of you there is another large red door twice your height" << endl;
    cout << "to the right there is a dark crevice that you cant see down, and to the left there is a stairwell" << endl << endl;
    cout << "enter 1, 2, or 3 to choose the corresponding action, in order they occur" << endl;
    cin >> firstAction;


    if(firstAction == 1)
    {
        cout << "You decide to try to open the large red door, choose a number between 1-3 to test your luck" << endl << endl;
        cin >> doorLuck;

        if(doorLuck == 1)
        {
            cout << "You push the door open with ease and step inside" << endl << endl;
            system("PAUSE");
        }

        else if (doorLuck == 2)
        {
            cout << "You reach out to push the door open, and the surface is burning hot! take 5 DMG to HEALTH" << endl << endl;
            switch (classInt)
            {
                case 1:
                    WrL.wHealth = 105;
                    cout << "HEALTH: " << WrL.wHealth << endl;
                    system("PAUSE");
                    break;
                case 2:
                    ArM.mHealth = 75;
                    cout << "HEALTH: " << ArM.mHealth << endl;
                    system("PAUSE");
                    break;
                case 3:
                    Mth.tHealth = 65;
                    cout << "HEALTH: " << Mth.tHealth << endl;
                    system("PAUSE");
                    break;
                default:
                    cout << "Invalid Entry!" << endl;
            }
        }

        else if (doorLuck == 3)
        {
            cout << "The door seems to be unmovable, choose either 2, or 3 to continue" << endl << endl;
            cin >> firstAction;
        }

    }

    if(firstAction == 2)
    {
        cout << "You boldly choose to leap down the crevice without looking down!" << endl;
        cout << "Luckily there is a body of water at the bottom and you splash down, but you land hard on your right hand, take 3 points off of ATTACK DMG" << endl;
            if (classInt == 1)
            {
                WrL.wAttackDmg = 67;
                cout << "ATTACK DMG: " << WrL.wAttackDmg << endl;
                system("PAUSE");
            }

            if(classInt == 2)
            {
                ArM.mAttackDmg = 17;
                cout << "HEALTH: " << ArM.mAttackDmg << endl;
                system("PAUSE");
            }

            if(classInt == 3)
            {
                Mth.tAttackDmg = 47;
                cout << "HEALTH: " << Mth.tAttackDmg << endl;
                system("PAUSE");
            }
    }

    if(firstAction == 3)
    {
        cout << "You wisely choose to descend the staircase, and continue to the depths below" << endl << endl;
        system("PAUSE");
    }

    cout << "It seems all three entrances led to this dimly lit body of water a floor below, " << endl;
    cout << "The water is a sickly green and smells of rotted fish and decay, it's nauseating " << endl << endl;
    cout << "Suddenly, a splashing sound rings off the dungeons walls, and a figure emerges out of the water in front of you!" << endl << endl;

    */
