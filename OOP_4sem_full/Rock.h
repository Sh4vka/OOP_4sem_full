#ifndef ROCK_H
#define ROCK_H

#include "Boots.h"

class Rock : public Boots
{
public:
    Rock(int init_x1, int init_y1, int init_x2, int init_y2);
    ~Rock();

    void show();
};

#endif // ROCK_H
