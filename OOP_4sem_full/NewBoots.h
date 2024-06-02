#ifndef NEWBOOTS_H
#define NEWBOOTS_H

#include "Boots.h"

class NewBoots : public Boots
{
public:
	NewBoots(int init_x1, int init_y1, int init_x2, int init_y2);
	~NewBoots();

	void show_new_nose();
	void show();

	void hide_new_nose();
	void hide();
};

#endif // NEWBOOTS_H
