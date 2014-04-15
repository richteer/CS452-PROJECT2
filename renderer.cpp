#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
#include "renderer.h"
#include <list>

#if defined(WINDOW_X) && defined(WINDOW_Y)
#else
#error please define WINDOW_X and WINDOW_Y
#endif

GLuint vao, vbo;
int ship_program, bull_program;

void init_renderer(int ship, int bull)
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	
	ship_program = ship;
	bull_program = bull;
}


void render(RenderObject ** obj, int num)
{
	int ang_loc, pos_loc, win_loc, col_loc;
	point p;
	
	glUseProgram(ship_program);

	ang_loc = glGetUniformLocation(ship_program,"angle");
	pos_loc = glGetUniformLocation(ship_program,"position");
	win_loc = glGetUniformLocation(ship_program,"window");
	col_loc = glGetUniformLocation(ship_program,"color");
	
	for (int i = 0; i < num; i++) {
		p = obj[i]->getPosition();
//		std::cout << "object " << i << " at (" << p.x << "," << p.y << ")" << std::endl;

		glUniform1f(ang_loc,obj[i]->getAngle());
		glUniform2f(pos_loc,p.x,p.y); 
		glUniform2f(win_loc,(float) WINDOW_X,(float) WINDOW_Y);
		glUniform4fv(col_loc,1,obj[i]->color);	
	
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*obj[i]->size, obj[i]->data, GL_STATIC_DRAW); 

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0, NULL);
	
		glDrawArrays(GL_LINE_STRIP, 0, obj[i]->size/3);
	}

}

void render(BulletMap * bullets)
{
	float * bulletpoints = new float[bullets->bullets.size()*2];
	int i = 0;

	glUseProgram(bull_program);
	
	for (std::list<bullet>::iterator it = bullets->bullets.begin(); it != bullets->bullets.end(); it++) {
		bulletpoints[i++] = it->x/WINDOW_X;
		bulletpoints[i++] = it->y/WINDOW_Y;
	}

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*i, bulletpoints, GL_STATIC_DRAW); 

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, 0, NULL);

	glPointSize(4);
	glDrawArrays(GL_POINTS, 0, bullets->bullets.size());

	delete bulletpoints;
}
