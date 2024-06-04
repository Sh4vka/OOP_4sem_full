#ifndef BOOTS_H
#define BOOTS_H

#include "Point.h"

class Boots : public Point {
protected:
    int x2, y2;

public:
    Boots(int init_x1, int init_y1, int init_x2, int init_y2);
    ~Boots();

    virtual int GetX() const;
    virtual int GetY() const;

    void show_body();
    void show_kabluc();
    void show_nose();
    virtual void show();

    void hide_body();
    void hide_kabluc();
    void hide_nose();
    virtual void hide();

    virtual void move_to(int newx1, int newy1);
};

#endif // BOOTS_H
