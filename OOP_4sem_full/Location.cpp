#include "windows.h"
#include "Location.h"

Location::Location(int init_x1, int init_y1) : x1(init_x1), y1(init_y1) {}

Location::~Location() {}

void Location::move_to(int new_x, int new_y) 
{
    x1 = new_x;
    y1 = new_y;
}
