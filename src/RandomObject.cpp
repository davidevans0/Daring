
#include <random>
#include <iostream>
#include <ctime>

#include "types.h"
#include "RandomObject.h"
/*--------------------------------------------------------------------------------------
 Random Object
 constructor sets the random function seed to a unique value
 Random sequences are achieved by setting the seed to the current time value on execution
 --------------------------------------------------------------------------------------*/
RandomObject::RandomObject()
{
    srand((int) time(0));
}

RandomObject::~RandomObject()
{
}
// generates a random 0 or 1 used in boolean true or false decisions
bool RandomObject::rand_yesno()
{
    return ((rand() % 2));
}
// random number from 1 to 6
int RandomObject::rand_1to6()
{
    return ((rand() % 6) + 1);
}
// random number from 1 to 3
int RandomObject::rand_1to3()
{
    return ((rand() % 3) + 1);
}
// random number from 1 to 10
int RandomObject::rand_1to10()
{
    return ((rand() % 10) + 1);
}
// random number from 1 to 100
int RandomObject::rand_1to100()
{
    return ((rand() % 100) + 1);
}

int RandomObject::rand_location_x()
{
    return ((rand() % MAZEX));
}

int RandomObject::rand_location_y()
{
    return ((rand() % MAZEY));
}


