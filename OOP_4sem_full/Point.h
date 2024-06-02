#ifndef POINT_H
#define POINT_H

#include "Location.h"
#include "Interface.h"

class Point : public Location, public Interface {
protected:
    bool visible;

public:
    Point(int init_x1, int init_y1);
    ~Point();
    virtual void show() override;
    virtual void hide() override;
    virtual void move_to(int new_x, int new_y) override;
    int GetX() const override { return x1; }
    int GetY() const override { return y1; }
};

#endif // POINT_H