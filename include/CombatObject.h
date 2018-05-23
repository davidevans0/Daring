#ifndef COMBATOBJECCT_H_INCLUDED
#define COMBATOBJECCT_H_INCLUDED

#include "cPlayer.h"
#include "Monster.h"
#include "RandomObject.h"

class CombatObject
{
    public:

        CombatObject(){}
       ~CombatObject(){}

       string combatPrompt(cPlayer); //
       bool doCombat(cPlayer*,Monster);


    private:
        RandomObject randomMachine;
};

#endif // COMBATOBJECCT_H_INCLUDED
