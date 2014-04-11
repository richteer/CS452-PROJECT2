#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "init_stuff.h"
#include "renderobject.h"
#include "renderer.h"

unsigned int prog;

float temp[12] = {
	-0.5f,-0.5f,0.0f,
	-0.5f, 0.5f,0.0f,
	 0.5f, 0.5f,0.0f,
	 0.5f,-0.5f,0.0f
};

RenderObject *test = new RenderObject(temp,12);

void init(void)
{
	prog = init_program(4, "vshader.glsl", GL_VERTEX_SHADER,"fshader.glsl", GL_FRAGMENT_SHADER);
	if (prog < 0) {
		fprintf(stderr,"Error: could not initialize program, bailing...\n");
		exit(1);
	}

	glUseProgram(prog);
}

void show_stuff(void)
{
	render(test);
}

void on_key(unsigned char c, int x, int y)
{
	switch(c) {
		case 'a':
			test->modAngle(-0.1f);
			break;		
		case 'd':
			test->modAngle(0.1f);
			break;		
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutCreateWindow("Blerp");

	glutInitContextVersion(4,3);
	glutInitContextProfile(GLUT_CORE_PROFILE | GLUT_COMPATIBILITY_PROFILE);

	init();
	
	glutDisplayFunc(show_stuff);
	glutKeyboardFunc(on_key);
	glutMainLoop();

	return 0;
}

