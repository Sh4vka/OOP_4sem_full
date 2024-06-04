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

	void show_new_body();
	void show_new_nose();
	virtual void show();

	void hide_new_body();
	void hide_new_nose();
	virtual void hide();
};

#endif // KED_H
