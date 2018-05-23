#include <iostream>
#include <cstdlib>

#include "Monster.h"

using namespace std;
/*-------------------------------------------------------------
 Object Monster
 object is used to create individual monsters and set their
 characteristics used in maze and combat.
--------------------------------------------------------------*/
void Monster::showStats() //used to print out unique monster stats
{
    cout << "ATTACK DMG: " << AttackDmg << endl << "HEALTH: " << Health << endl << "MAGIC DMG: " << MagicDmg << endl;
    cout << "WEAPON: " << Weapon << endl << "SPELL: " << Spell << endl << endl;
}
//sets monster stats
void Monster::setMonsterStats(int monHealth, int monAtt, int monMag, string monWep, string monSpell, string monName)
{
    MonName = monName;
    Health = monHealth;
    AttackDmg = monAtt;
    MagicDmg = monMag;
    Weapon = monWep;
    Spell = monSpell;
}
