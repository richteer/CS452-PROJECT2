#define GL_GLEXT_PROTOTYPES

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <time.h>

#include "init_stuff.h"
#include "renderobject.h"
#include "bulletmap.h"
#include "renderer.h"
#include "ship.h"

#define BULLET_RATE 20

unsigned char keys[128] = {0};

RenderObject * players[2];
BulletMap * bullets = new BulletMap();;
int p1bul = 0, p2bul = 0;
int end;

void init(void)
{
	int ship, bull;	

	ship = init_program(4, "vshader.glsl", GL_VERTEX_SHADER,"fshader.glsl", GL_FRAGMENT_SHADER);
	if (ship < 0) {
		fprintf(stderr,"Error: could not initialize program, bailing...\n");
		exit(1);
	}
	
	bull = init_program(4, "vbullets.glsl", GL_VERTEX_SHADER, "fbullets.glsl", GL_FRAGMENT_SHADER);
	if (bull < 0) {
		fprintf(stderr,"Error: could not initialize program, bailing...\n");
		exit(1);
	}

	init_renderer(ship, bull);

	players[0] = genShip();
	players[1] = genShip();


	// Set player colors
	players[0]->color[0] = 1.0f;
	players[0]->color[1] = 0.0f;
	players[0]->color[2] = 0.0f;
	players[0]->color[3] = 1.0f;

	players[1]->color[0] = 0.0f;
	players[1]->color[1] = 1.0f;
	players[1]->color[2] = 0.0f;
	players[1]->color[3] = 1.0f;

	// Set intial positions	
	players[0]->pos = {-WINDOW_X/2,WINDOW_Y/2};
	players[1]->pos = {-WINDOW_X/2,-WINDOW_Y/2};


}

void move_stuff()
{
	clock_t derp;

//	if (keys['w']) players[0]->modMotion(0.1f);
//	if (keys['s']) players[0]->modMotion(-0.1f);

	if (keys['w'] && !(p1bul--)) p1bul = BULLET_RATE,players[0]->shoot(bullets);
	if (keys['a']) players[0]->modAngle(0.01f);
	if (keys['d']) players[0]->modAngle(-0.01f);
	
//	if (keys['k']) players[1]->modMotion(0.1f);
//	if (keys['j']) players[1]->modMotion(-0.1f);
	if (keys['j'] && !(p2bul--)) p2bul = BULLET_RATE,players[1]->shoot(bullets);
	if (keys['h']) players[1]->modAngle(0.01f);
	if (keys['l']) players[1]->modAngle(-0.01f);

	players[0]->move();
	players[1]->move();

	bullets->move();	
	if (bullets->check_collision(players[0]->pos.x,players[0]->pos.y)) end = 2;
	if (bullets->check_collision(players[1]->pos.x,players[1]->pos.y)) end = 1;

	glutPostRedisplay();

	if (end) {
		fprintf(stderr,"Game Over, player %d wins!\n",end);
		exit(0);
	}

	derp = clock();
	while (clock() - derp <= 2000);

}

void show_stuff(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	render(players, 2);
	render(bullets);
	glFlush();
}

void on_key(unsigned char c, int x, int y)
{
/*	switch(c) {

		// Player 1

	//	case 'w': players[0]->modPosition(4.0f);  break;
		case 'w': players[0]->modMotion(0.1f);  break;
	//	case 's': players[0]->modPosition(-4.0f); break;
		case 's': players[0]->modMotion(-0.1f); break;
		case 'a': players[0]->modAngle(0.1f);   break;
		case 'd': players[0]->modAngle(-0.1f);  break;		



		// Player 2
		case 'k': players[1]->modMotion(0.1f);  break;
		case 'j': players[1]->modMotion(-0.1f); break;
		case 'h': players[1]->modAngle(0.1f);   break;
		case 'l': players[1]->modAngle(-0.1f);  break;
	}*/
	keys[c] = 1;

}

void up_key(unsigned char c, int x, int y)
{
	keys[c] = 0;


}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(WINDOW_X,WINDOW_Y);
	glutCreateWindow("Spacewar");

	glutInitContextVersion(4,3);
	glutInitContextProfile(GLUT_CORE_PROFILE | GLUT_COMPATIBILITY_PROFILE);

	init();

//	glutTimerFunc(30, move_stuff, -1);	
	glutIdleFunc(move_stuff);	
	glutDisplayFunc(show_stuff);
	glutKeyboardFunc(on_key);
	glutKeyboardUpFunc(up_key);
	glutMainLoop();

	return 0;
}

