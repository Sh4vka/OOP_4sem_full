#ifndef KED_H
#define KED_H

#include "Boots.h"

class Ked : public Boots
{
protected:
	int distanse;
	//y1 = y1 + distanse;

public:
	Ked(int init_x1, int init_y1, int init_x2, int init_y2, int init_distance);
	~Ked();

	virtual void show_new_body();
	virtual void show_new_nose();
	virtual void show();

	virtual void hide_new_body();
	virtual void hide_new_nose();
	virtual void hide();
};

class NewKed : public Ked
{
public:
	NewKed(int init_x1, int init_y1, int init_x2, int init_y2, int init_distance);
	~NewKed();

	void show_new_dirty_body();
	virtual void show();

	void hide_new_dirty_body();
	virtual void hide();
};

#endif // KED_H
