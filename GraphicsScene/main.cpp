#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <cstdio>

int main() {
	if (!glfwInit()){
		return -1;
	}

	//Game goes here
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Computer Grapgics", nullptr, nullptr);

	if (window == nullptr) {
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	//print the openGl number
	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	//loop goes here
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}