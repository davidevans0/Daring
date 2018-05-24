#ifndef CPLAYER_H_INCLUDED
#define CPLAYER_H_INCLUDED

#include <iostream>

#include "PersonObject.h"

using namespace std;

class cPlayer : public PersonObject
{
    public:

       cPlayer() {}
       ~cPlayer(){}

        void showStats();
        void setPlayerStats(int, int, int, string, string, string);
        void setheroName(string sHN) {heroName = sHN;}
        void setCharType(string sCT) {charType = sCT;}
        void setHealth(int sH) {Health = sH;}
        void setAttackDmg(int sAD) {AttackDmg = sAD;}
        void setMagicDmg(int sMD) {MagicDmg = sMD;}
        void setRightHand(string sRH) {RightHand = sRH;}
        void setLeftHand(string sLH) {LeftHand = sLH;}
        void setSpell(string sS) {Spell = sS;}

        string getheroName() {return heroName;}
        string getCharType() {return charType;}
        int getHealth() {return Health;}
        int getAttackDmg() {return AttackDmg;}
        int getMagicDmg() {return MagicDmg;}
        string getRightHand() {return RightHand;}
        string getLeftHand() {return LeftHand;}
        string getSpell() {return Spell;}

    private:
        string heroName;
        string charType;
        int Health;
        int AttackDmg;
        int MagicDmg;
        string RightHand;
        string LeftHand;
        string Spell;
        string Weapon;
};


#endif // CPLAYER_H_INCLUDED
