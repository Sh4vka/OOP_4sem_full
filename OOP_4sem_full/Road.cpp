#include "Road.h"
#include "windows.h"

extern HDC hdc;

Road::Road(int init_x1, int init_y1, int init_x2, int init_y2, int init_x1s, int init_x2s)
    : Point(init_x1, init_y1), x2(init_x2), y2(init_y2), x1s(init_x1s), x2s(init_x2s) {}

Road::~Road() {}


void Road::show()
{
    int newx1 = x1;
    while (newx1 <= x2) //длина сапога
    {
        Point APoint = Point(newx1, y1);
        Point BPoint = Point(newx1, y2);
        APoint.show();
        BPoint.show();
        newx1++;
    }
}

void Road::hide(int x1s, int x2s)
{
    int newx1 = x1s;
    while (newx1 <= x2s) //длина сапога
    {
        Point APoint = Point(newx1, y1);
        APoint.hide();
        newx1++;
    }
}