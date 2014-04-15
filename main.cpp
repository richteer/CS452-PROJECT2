#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "init_stuff.h"
#include "renderobject.h"
#include "renderer.h"
#include "ship.h"

unsigned int prog;

RenderObject * players[2];

void init(void)
{
	prog = init_program(4, "vshader.glsl", GL_VERTEX_SHADER,"fshader.glsl", GL_FRAGMENT_SHADER);
	if (prog < 0) {
		fprintf(stderr,"Error: could not initialize program, bailing...\n");
		exit(1);
	}

	glUseProgram(prog);
	
	init_renderer(prog);

	players[0] = genShip();
	players[1] = genShip();

}

void show_stuff(void)
{
//	players[0]->move();
//	players[1]->move();
	printf("(%f,%f)\n",players[0]->pos.x,players[0]->pos.y);
	render(players, 2);
}

void on_key(unsigned char c, int x, int y)
{
	switch(c) {

		// Player 1

		case 'w': players[0]->modPosition(0.1f);  break;
		case 's': players[0]->modPosition(-0.1f); break;
		case 'a': players[0]->modAngle(0.1f);   break;
		case 'd': players[0]->modAngle(-0.1f);  break;		



		// Player 2
		case 'k': players[1]->modPosition(0.1f);  break;
		case 'j': players[1]->modPosition(-0.1f); break;
		case 'h': players[1]->modAngle(0.1f);   break;
		case 'l': players[1]->modAngle(-0.1f);  break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutCreateWindow("Spacewar");

	glutInitContextVersion(4,3);
	glutInitContextProfile(GLUT_CORE_PROFILE | GLUT_COMPATIBILITY_PROFILE);

	init();
	
	glutDisplayFunc(show_stuff);
	glutKeyboardFunc(on_key);
	glutMainLoop();

	return 0;
}

