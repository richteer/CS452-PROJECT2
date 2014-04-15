#include "renderer.h"
#include <cmath>
#include <cstdio>

RenderObject::RenderObject(COORD_TYPE* points, int sz)
{
	int i;

	this->data = new COORD_TYPE[sz];
	if (this->data == NULL) return;

	for (i = 0; i < sz; i++)
		this->data[i] = points[i];
	this->size = sz;

	this->pos.x = 0;
	this->pos.y = 0;
	
	this->mot.x = 0;
	this->mot.y = 0;
	
	this->angle = 0;
}

RenderObject::~RenderObject()
{
	if (this->data != NULL)
		delete this->data;
}

void RenderObject::modPosition(float mod)
{
	pos.x += cos(this->angle)*mod;
	pos.y += sin(this->angle)*mod;


}

void RenderObject::modMotion(float mod)
{
	mot.x += cos(this->angle)*mod;
	mot.y += sin(this->angle)*mod;

}

void RenderObject::move(void)
{
	this->pos.x += this->mot.x;
	this->pos.y += this->mot.y;
	printf("moving to (%d,%d)\n",this->pos.x,this->pos.y);

	/* REDUCE MOTION HERE BASED ON WEIGHT? */

}
