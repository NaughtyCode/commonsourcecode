#include "Shader.h"
#include "PrimaryWindow.h"

static GLFWwindow* RenderWindow=0;

void CreatePrimaryWindow(const int width, const int height, const char* name, const int depth){
	assert(glfwInit()!=0);
	glfwWindowHint(GLFW_DEPTH_BITS, depth);
	RenderWindow = glfwCreateWindow(width, height, name, NULL, NULL);
	assert(RenderWindow);
	glfwMakeContextCurrent(RenderWindow);
	glfwSwapInterval(1);
	assert(glewInit() == GLEW_OK);
}

void WindowSwapBuffers(){
	assert(RenderWindow);
	glfwSwapBuffers(RenderWindow);
}

void DispatchEvent(){
	assert(RenderWindow);
	glfwPollEvents();
}

void MainLoop(){
	assert(RenderWindow);

	CreateShader();
	
	while (!glfwWindowShouldClose(RenderWindow))
	{
		RenderFrame();
		WindowSwapBuffers();
		DispatchEvent();
	}


	DestroyPrimaryWindow();
	printf(" Õ∑≈‰÷»æ¥∞ø⁄\n");
}

void DestroyPrimaryWindow(){
	assert(RenderWindow);
	glfwDestroyWindow(RenderWindow);
	glfwTerminate();
	RenderWindow = 0;
}
