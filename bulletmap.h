#define BULLET_SPEED 3
#ifndef _bulletmap_h_
#define _bulletmap_h_

#include <list>

struct bullet {
	bullet(float nx, float ny, float na) { x = nx; y = ny; a = na; };
	float x;
	float y;
	float a;
};

class BulletMap {

	public:
		std::list<bullet> bullets;
		int end;	
	
		BulletMap();

		void move(void);
		void addBullet(float,float,float);
		bool check_bounds(std::list<bullet>::iterator);
		int check_collision(float,float);


};

#endif
