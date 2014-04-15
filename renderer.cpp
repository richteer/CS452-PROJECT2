#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
#include "renderer.h"

GLuint vao, vbo;
int program_select;

void init_renderer(int program)
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	
	program_select = program;

}


void render(RenderObject ** obj, int num)
{
	int ang_loc, pos_loc;
	point p;
	glClear(GL_COLOR_BUFFER_BIT);

	ang_loc = glGetUniformLocation(program_select,"angle");
	pos_loc = glGetUniformLocation(program_select,"position");

	
	
	for (int i = 0; i < num; i++) {
		p = obj[i]->getPosition();
		std::cout << "object " << i << " at (" << p.x << "," << p.y << ")" << std::endl;

		glUniform1f(ang_loc,obj[i]->getAngle());
		glUniform2f(pos_loc,p.x,p.y); // TODO: remove dependence on this being public

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*obj[i]->size, obj[i]->data, GL_STATIC_DRAW); 

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0, NULL);
	
		glDrawArrays(GL_LINE_STRIP, 0, obj[i]->size/3);
	}

	glFlush();
}
