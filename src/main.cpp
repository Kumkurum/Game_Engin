#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int g_window_SizeX = 640;
int g_window_SizeY = 480;
void glfw_window_size_callback(GLFWwindow* p_window, int width, int height) {
	g_window_SizeX = width;
	g_window_SizeY = height;
	glViewport(0, 0, g_window_SizeX, g_window_SizeY);
}
void glfw_Key_Callback(GLFWwindow* p_window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(p_window, GL_TRUE);
	}

}
int main(void) {

	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "glfw falled!" << std::endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* p_window = glfwCreateWindow(g_window_SizeX, g_window_SizeY, "Game Engin", nullptr, nullptr);
	if (!p_window) {
		std::cout << "glfwCreateWindow falled!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwSetWindowSizeCallback(p_window, glfw_window_size_callback);
	glfwSetKeyCallback(p_window, glfw_Key_Callback);
	/* Make the window's context current */
	glfwMakeContextCurrent(p_window);
	if (!gladLoadGL()) {
		std::cout << "Error!" << std::endl;
		return -1;
	}
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

	glClearColor(0, 1, 0, 1);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(p_window)) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(p_window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}