//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "renderer.h"


void render(RenderObject * obj)
{
	GLuint vao, vbo;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(int), obj->data, GL_STATIC_DRAW); 

	glDrawArrays(GL_LINE_STRIP, 0, obj->datanum);

	glFlush();
}
