#ifndef ROAD_H
#define ROAD_H

#include "Point.h"

class Road : public Point
{
protected:
    int x2, y2, x1s, x2s;

public:
    Road(int init_x1, int init_y1, int init_x2, int init_y2, int init_xs, int init_ys);
    ~Road();

	virtual void show();
    virtual void hide(int xs1, int x2s);
};

#endif // ROAD_H