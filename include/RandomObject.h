#ifndef RANDOMOBJECT_H
#define RANDOMOBJECT_H

#include <random>

class RandomObject
{
    public:
        RandomObject();
        ~RandomObject();
        bool rand_yesno();
        int rand_1to6();
        int rand_1to3();
        int rand_1to10();
        int rand_1to100();

        int rand_location_x();
        int rand_location_y();

    private:
};

#endif // RANDOMOBJECT_H
