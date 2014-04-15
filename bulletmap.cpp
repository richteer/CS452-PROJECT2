#include <iostream>
#include <cmath>
#include "bulletmap.h"
#include "renderer.h"

BulletMap::BulletMap(void)
{
}

void BulletMap::move(void)
{
	std::list<std::list<bullet>::iterator> todelete;

	for (std::list<bullet>::iterator it = this->bullets.begin(); it != this->bullets.end(); it++) {
		it->x += BULLET_SPEED * cos(it->a);
		it->y += BULLET_SPEED * sin(it->a);
		if (check_bounds(it)) todelete.push_front(it);
	} 

	for (std::list<std::list<bullet>::iterator>::iterator it = todelete.begin(); it != todelete.end(); it++) {
		bullets.erase(*it);
		std::cout << "deleted a bullet" << std::endl;
	}
}

void BulletMap::addBullet(float x, float y, float a)
{
	std::cout << "added a bullet" << std::endl;
	this->bullets.push_back(bullet(x,y,a));	
}

bool BulletMap::check_bounds(std::list<bullet>::iterator it)
{
	return ((abs(it->x) >= WINDOW_X) || (abs(it->y) >= WINDOW_Y));
}

int BulletMap::check_collision(float x, float y)
{
	for (std::list<bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
		if (sqrt(powf(x - it->x,2) + powf(y - it->y,2)) < 5) return true;

	return false;
}

