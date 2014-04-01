#include "renderer.h"
//#include <cmath>


RenderObject::RenderObject(COORD_TYPE* points, int sz)
{
	int i;

	this->data = new COORD_TYPE[sz];
	if (this->data == NULL) return;

	for (i = 0; i < sz; i++)
		this->data[i] = points[i];
}

RenderObject::~RenderObject()
{
	if (this->data != NULL)
		delete this->data;
}

void RenderObject::move(void)
{
	pos.x += mot.x;
	pos.y += mot.y;

	/* REDUCE MOTION HERE BASED ON WEIGHT? */

}
