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
//	pos.x += cos(this->angle)*mod;
//	pos.y += sin(this->angle)*mod;
	motion m;
	m.x = mod*cos(angle);
	m.y = mod*sin(angle);

	this->modPosition(m);
}

void RenderObject::modPosition(motion m)
{
	float dx = pos.x + m.x;
	float dy = pos.y + m.y;

	pos.x = (abs(dx) >= WINDOW_X) ? -(dx/abs(dx)) * WINDOW_X : pos.x + m.x;
	pos.y = (abs(dy) >= WINDOW_Y) ? -(dy/abs(dy)) * WINDOW_Y : pos.y + m.y;

}

void RenderObject::modMotion(float mod)
{
	mot.x += cos(this->angle)*mod;
	mot.y += sin(this->angle)*mod;

}

void RenderObject::move(void)
{
//	this->modPosition(this->mot);
	this->modPosition(1.0f);
}

void RenderObject::shoot(BulletMap * bullets)
{
	bullets->addBullet(this->pos.x + 10*cos(this->angle), this->pos.y + 10*sin(this->angle), this->angle);
}
