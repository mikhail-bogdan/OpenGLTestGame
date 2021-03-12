#pragma once

#include <list>
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <GL/GLU.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>

#include "Matrix4x4.h"
#include "Renderer.h"

class Renderer;
class Vector2;

class Graphics
{
private:
	static Graphics* graphics;
	int width, height;
	SDL_Window* window = nullptr;
	//GLFWwindow* window;
	std::list<Renderer*> renderers;
	Matrix4x4 projection = Matrix4x4::genIdentity().setOrtho(0.0f, 800.0f, 0.0f, 600.0f, 0, 1);

public:
	Graphics();
	static void Init();
	SDL_Event* PollEvent();
	void Update(SDL_Event* event);
	static void DeInit();
	static Graphics* getGraphics();
	static bool IsGraphicsInit();
	void resizeWindow(int width, int height);
	bool isWindowShouldClose();

	Vector2 GetWindowSize() const;

private:
	void addRenderer(Renderer* renderer);
	void removeRenderer(Renderer* renderer);

	friend class Renderer;
};