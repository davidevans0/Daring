#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <iostream>

#include "PersonObject.h"

using namespace std;

class Monster : public PersonObject
{
    public:

        Monster(){};
        ~Monster(){}

        void setMonsterStats(int, int, int , string , string, string);
        void showStats();
        void setMonName(string sMN) {MonName = sMN;}
        void setHealth(int sH) {Health = sH;}
        void setAttackDmg(int sAD) {AttackDmg = sAD;}
        void setMagicDmg(int sMD) {MagicDmg = sMD;}
        void setWeapon(string sW) {Weapon = sW;}
        void setSpell(string sS) {Spell = sS;}

        string getMonName() {return MonName;}
        int getHealth() {return Health;}
        int getAttackDmg() {return AttackDmg;}
        int getMagicDmg() {return MagicDmg;}
        string getWeapon() {return Weapon;}
        string getSpell() {return Spell;}

    private:
        string MonName;
        int Health;
        int AttackDmg;
        int MagicDmg;
        string Spell;
        string Weapon;
};


#endif // MONSTER_H_INCLUDED
