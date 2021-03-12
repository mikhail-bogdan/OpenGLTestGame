#pragma once

#include "Graphics.h"

class Input
{
	enum MouseState
	{
		Pressed = 0,
		Press = 1,
		Released = 2,
		Release = 3,
	};

public:
	static void Init();
	static void Update();
	static void UpdateEvent(SDL_Event* event);
	static void Destroy();

	static Vector2 GetMousePosition();
	static Vector2 GetPrevMousePosition();
	static Vector2 GetMouseDeltaPosition();

	static bool GetMouseButtonDown(int mouseButton);
	static bool GetMouseButton(int mouseButton);
	static bool GetMouseButtonUp(int mouseButton);


private:
	static int windowHeight;
	static byte* keys;
	static MouseState mouseKeys[5];
	static Vector2 mousePos;
	static Vector2 prevMousePos;
	static Vector2 mouseScrollDelta;
};