#ifndef POINT_H
#define POINT_H

#include "Location.h"

class Point : public Location {
protected:
    bool visible;

public:
    Point(int init_x1, int init_y1);
    ~Point();
    virtual void show();
    virtual void hide();
    virtual void move_to(int new_x, int new_y);
};

#endif // POINT_H