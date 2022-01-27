#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
void framebuffer_size_callback(GLFWwindow*window, int width, int height);//ע��ص����������ڵ������ڴ�С
void processInput(GLFWwindow* window);


int main() {
	//ʵ����GLFW����
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//�������ڶ���
	GLFWwindow* window = glfwCreateWindow(800, 600, "learnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//ע��ص����������ڵ������ڴ�С
	//���ǻ����Խ����ǵĺ���ע�ᵽ�����ܶ�Ļص������С�
	//����˵�����ǿ��Դ���һ���ص������������ֱ�����仯�����������Ϣ�ȡ�
	//���ǻ��ڴ�������֮����Ⱦѭ����ʼ��֮ǰע����Щ�ص�������
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//��ʼ��GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout<< "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	////������Ⱦ���ڣ����ӿڣ�Viewport��,���ô��ڵ�ά��
	//glViewport(0, 0, 800, 600);

	

	//��Ⱦѭ��(Render Loop)
	while (!glfwWindowShouldClose(window)) {
		//����û��Ƿ����˷��ؼ�(Esc)
		processInput(window);

		//��Ⱦָ�����glClear�����������Ļ����ɫ���壩
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//�����û�д���ʲô�¼������´���״̬�������ö�Ӧ�Ļص�����
		glfwSwapBuffers(window);
		//������ɫ����
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}


//ע��ص����������ڵ������ڴ�С
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

//���뺯��,������escape���˳�����
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}