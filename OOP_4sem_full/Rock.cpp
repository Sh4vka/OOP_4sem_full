#include "Rock.h"
#include "windows.h"

extern HDC hdc;

Rock::Rock(int init_x1, int init_y1, int init_x2, int init_y2)
    : Boots(init_x1, init_y1, init_x2, init_y2) {}

Rock::~Rock() {}

void Rock::show()
{
    int newx1 = x1;
    while (newx1 <= x2) //длина сапога
    {
        Point ABoots = Point(newx1, y1);
        Point BBoots = Point(newx1, y2);
        ABoots.show();
        BBoots.show();
        newx1++;
    }

    int newy1 = y1;
    while (newy1 <= y2) // высота сапога
    {
        Point ABoots = Point(x1, newy1);
        Point BBoots = Point(x2, newy1);
        ABoots.show();
        BBoots.show();
        newy1++;
    }
}