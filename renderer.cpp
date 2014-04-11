#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
#include "renderer.h"


void render(RenderObject * obj)
{
	GLuint vao, vbo;
	glClear(GL_COLOR_BUFFER_BIT);

	glUniform1f(0,obj->getAngle());

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*obj->size, obj->data, GL_STATIC_DRAW); 

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0, NULL);
	
	glDrawArrays(GL_LINE_STRIP, 0, 4);


	std::cout << "Rendered!\n";
	glFlush();
}
