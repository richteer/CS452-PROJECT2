#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>

#include "renderer.h"


void render(RenderObject * obj)
{
	GLuint vao, vbo;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*obj->size, obj->data, GL_STATIC_DRAW); 

	glDrawArrays(GL_TRIANGLES, 0, obj->size);

	glFlush();
}
