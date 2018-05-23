#include <iostream>
#include <cstdlib>
#include "cPlayer.h"
#include "DungeonObject.h"

using namespace std;
/*-------------------------------------------------------------
 Object cPLayer
 object is used to create individual player and set their
 characteristics used in motion and combat.
--------------------------------------------------------------*/
void cPlayer::showStats() //used to print out unique hero stats
{
    cout << "ATTACK DMG: " << AttackDmg << endl << "HEALTH: " << Health << endl << "MAGIC DMG: " << MagicDmg << endl;
    cout << "LEFT HAND WPN: " << LeftHand << endl << "RIGHT HAND WPN: " << RightHand << endl << "SPELL: " << Spell << endl << endl;
}

//sets hero stats
void cPlayer::setPlayerStats(int statDMG, int statHEL, int statMAG, string statLFT, string statRIT, string statSPL)
{
    AttackDmg = statDMG;
    Health = statHEL;
    MagicDmg = statMAG;
    LeftHand = statLFT;
    RightHand = statRIT;
    Spell = statSPL;
}


