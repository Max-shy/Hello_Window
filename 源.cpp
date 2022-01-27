#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
void framebuffer_size_callback(GLFWwindow*window, int width, int height);//注册回调函数，用于调整窗口大小
void processInput(GLFWwindow* window);


int main() {
	//实例化GLFW窗口
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//创建窗口对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "learnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//注册回调函数，用于调整窗口大小
	//我们还可以将我们的函数注册到其它很多的回调函数中。
	//比如说，我们可以创建一个回调函数来处理手柄输入变化，处理错误消息等。
	//我们会在创建窗口之后，渲染循环初始化之前注册这些回调函数。
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout<< "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	////设置渲染窗口，即视口（Viewport）,设置窗口的维度
	//glViewport(0, 0, 800, 600);

	

	//渲染循环(Render Loop)
	while (!glfwWindowShouldClose(window)) {
		//检查用户是否按下了返回键(Esc)
		processInput(window);

		//渲染指令（调用glClear函数来清空屏幕的颜色缓冲）
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//检查有没有触发什么事件、更新窗口状态，并调用对应的回调函数
		glfwSwapBuffers(window);
		//交换颜色缓冲
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}


//注册回调函数，用于调整窗口大小
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

//输入函数,若输入escape，退出窗口
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}