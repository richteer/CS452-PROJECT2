#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "renderobject.h"
#include "renderer.h"
#include "init_stuff.h"

int prog;

void init(void)
{
	prog = init_program(2, "vshader.glsl", GL_VERTEX_SHADER); //, "fshader.glsl", GL_FRAGMENT_SHADER);
	glUseProgram(prog);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
	GLFWwindow* window;

	float temp[8] = {
		-0.5f,-0.5f,
		-0.5f, 0.5f,
		 0.5f, 0.5f,
		 0.5f,-0.5f
	};

	RenderObject *test = new RenderObject(temp,8);


	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		render(test);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
