#ifndef DUNGEONOBJECT_H
#define DUNGEONOBJECT_H

#include "types.h"
#include "MazeObject.h"
#include "Monster.h"
#include "CombatObject.h"
#include "cPlayer.h"

class DungeonObject
{
    public:
        DungeonObject();
        ~DungeonObject();

        void setplayerState(int ssP) {playerState = ssP;}
        int getplayerState() {return playerState;}

        void intro();
        void DungeonDisplay();
        bool MovePerson(char);
        char getencounter() {return encounter;}
        bool displayEncounter();
        void displayGoblinArt();
        void displayMurlockArt();
        void displayWraithArt();
        void setMonsterStats(Monster,int,int,int,string,string,string);
        InputActions GetPlayerInput();
        cPlayer* playerAccess;
        Monster* monsterAccess;
        MazeObject* mazeAccess;

    private:
        int playerState;

        MazeObject Maze;

        cPlayer PlayerOne;

        Monster monsterArray[MON_POPULATION];

        char encounter;

        Monster Goblin1;
        Monster Goblin2;
        Monster Goblin3;

        Monster Murlock1;
        Monster Murlock2;
        Monster Murlock3;
        Monster Murlock4;
        Monster Murlock5;

        Monster Wraith1;
        Monster Wraith2;
        Monster Wraith3;
        Monster Wraith4;
        Monster Wraith5;

        CombatObject Combat;
};

#endif // DUNGEONOBJECT_H
