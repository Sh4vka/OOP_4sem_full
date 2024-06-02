#ifndef LOCATION_H
#define LOCATION_H

class Location {
protected:
    int x1, y1;

public:
    Location(int init_x1, int init_y1);
    ~Location();
    void move_to(int new_x, int new_y);
};

#endif // LOCATION_H
