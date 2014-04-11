#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "init_stuff.h"
#include "renderobject.h"
#include "renderer.h"

unsigned int prog;

float temp[8] = {
	-0.5f,-0.5f,
	-0.5f, 0.5f,
	 0.5f, 0.5f,
	 0.5f,-0.5f
};

RenderObject *test = new RenderObject(temp,8);


void init(void)
{
	prog = init_program(2, "vshader.glsl", GL_VERTEX_SHADER);
	if (prog < 0) {
		fprintf(stderr,"Error: could not initialize program, bailing...\n");
		exit(1);
	}

	glUseProgram(prog);
	glEnable(GL_DEPTH_TEST);
}

void show_stuff(void)
{
	render(test);

}


int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutCreateWindow("Lab 2");

	glutInitContextVersion(4,3);
	glutInitContextProfile(GLUT_CORE_PROFILE | GLUT_COMPATIBILITY_PROFILE);

	init();
	
	glutDisplayFunc(show_stuff);
	//glutKeyboardFunc(on_key);
	glutMainLoop();

	return 0;
}

