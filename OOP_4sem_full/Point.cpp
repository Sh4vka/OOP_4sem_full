#include "Point.h"
#include <windows.h>

extern HDC hdc;

Point::Point(int init_x1, int init_y1) : Location(init_x1, init_y1), visible(false) {}

Point::~Point() {}

void Point::show() 
{
    visible = true;

    SetPixel(hdc, x1, y1, RGB(0, 0, 0));
    SetPixel(hdc, x1 + 1, y1, RGB(0, 0, 0));
    SetPixel(hdc, x1, y1 + 1, RGB(0, 0, 0));
    SetPixel(hdc, x1 + 1, y1 + 1, RGB(0, 0, 0));
}

void Point::hide() 
{
    visible = false;
    SetPixel(hdc, x1, y1, RGB(255, 255, 255)); // ставим пиксели белыми
    SetPixel(hdc, x1 + 1, y1, RGB(255, 255, 255));
    SetPixel(hdc, x1, y1 + 1, RGB(255, 255, 255));
    SetPixel(hdc, x1 + 1, y1 + 1, RGB(255, 255, 255));
}

void Point::move_to(int new_x, int new_y) 
{
    hide();
    x1 = new_x;
    y1 = new_y;
    show();
}
