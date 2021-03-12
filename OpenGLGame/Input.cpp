#include "Input.h"

int Input::windowHeight;
byte* Input::keys;
Input::MouseState Input::mouseKeys[5];
Vector2 Input::mousePos;
Vector2 Input::prevMousePos;
Vector2 Input::mouseScrollDelta;

void Input::Init()
{
	if (!Graphics::IsGraphicsInit()) return;

	Input::windowHeight = Graphics::getGraphics()->GetWindowSize().y;
	Input::keys = new byte[256];
	for (int i = 0; i < 5; i++)
	{
		Input::mouseKeys[i] = MouseState::Release;
	}

	//SDL_SetRelativeMouseMode(SDL_TRUE);
	//SDL_ShowCursor(SDL_ENABLE);

}

void Input::Update()
{
	for (int i = 0; i < 5; i++)
	{
		if (Input::mouseKeys[i] == MouseState::Pressed)
			Input::mouseKeys[i] = MouseState::Press;
		if (Input::mouseKeys[i] == MouseState::Released)
			Input::mouseKeys[i] = MouseState::Release;
	}
}

void Input::UpdateEvent(SDL_Event* event)
{

	if (event->type == SDL_MOUSEMOTION)
	{
		int x, y;
		int mouseState = SDL_GetMouseState(&x, &y);
		int buttonNum = SDL_BUTTON(mouseState);
		Input::prevMousePos = Input::mousePos;
		Input::mousePos.x = x;
		Input::mousePos.y = Input::windowHeight - y;
		for (int i = 0; i < 5; i++)
		{
			Input::mouseKeys[i] = MouseState::Release;
		}
	}
	else if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		int mouseState = SDL_GetMouseState(NULL, NULL);
		for (int i = 0; i < 5; i++)
		{
			if (Input::mouseKeys[i] == MouseState::Release || Input::mouseKeys[i] == MouseState::Released)
			{
				if (SDL_BUTTON(i + 1) & mouseState)
				{
					Input::mouseKeys[i] = MouseState::Pressed;
				}
			}
		}
	}
	else if (event->type == SDL_MOUSEBUTTONUP)
	{
		int mouseState = SDL_GetMouseState(NULL, NULL);

		for (int i = 0; i < 5; i++)
		{
			if (Input::mouseKeys[i] == MouseState::Press || Input::mouseKeys[i] == MouseState::Pressed)
			{
				if (!(SDL_BUTTON(i + 1) & mouseState))
				{
					Input::mouseKeys[i] = MouseState::Released;
				}
			}
		}
	}
}



void Input::Destroy()
{
}

Vector2 Input::GetMousePosition()
{
	return Input::mousePos;
}

Vector2 Input::GetPrevMousePosition()
{
	return Input::prevMousePos;
}

Vector2 Input::GetMouseDeltaPosition()
{
	return Input::mousePos - Input::prevMousePos;
}

bool Input::GetMouseButtonDown(int mouseButton)
{
	return Input::mouseKeys[mouseButton] == MouseState::Pressed;
}

bool Input::GetMouseButton(int mouseButton)
{
	return Input::mouseKeys[mouseButton] == MouseState::Press;
}

bool Input::GetMouseButtonUp(int mouseButton)
{
	return Input::mouseKeys[mouseButton] == MouseState::Released;
}
