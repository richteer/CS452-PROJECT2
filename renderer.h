#ifndef _renderer_h_
#define _renderer_h_

#define WINDOW_X 800
#define WINDOW_Y 600

#include "renderobject.h"

//bool init(void);
void init_renderer(int,int);
void render(RenderObject**,int);
void render(BulletMap*);


#endif
