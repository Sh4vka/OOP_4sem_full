#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
public:
    //virtual ~Interface() = 0;
    virtual void show() = 0;
    virtual void hide() = 0;
    virtual void move_to(int new_x, int new_y) = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
};

#endif // INTERFACE_H