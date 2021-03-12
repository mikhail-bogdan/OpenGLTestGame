#include <memory>
#include "Graphics.h"
#include <winnt.h>
#include <chrono>

#include "SpriteRenderer.h"
#include "AudioManager.h"
#include "AudioListener.h"
#include "AudioSource.h"
#include "Input.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpCmdLine, int nCmdShow) {

	/*char name[] = "test", classname[] = "mytestclassname";
	WNDCLASS cl;
	HWND hWnd = NULL;
	MSG msg;
	
	
	memset(&cl, 0, sizeof(WNDCLASS));

	cl.lpfnWndProc = WndProc;
	cl.lpszClassName = classname;
	cl.hInstance = hInst;
	cl.style = CS_HREDRAW | CS_VREDRAW;
	cl.hbrBackground = GetStockBrush(WHITE_BRUSH);

	RegisterClass(&cl);

	hWnd = CreateWindow(classname, name, WS_OVERLAPPEDWINDOW, 0, 0, 500, 500, 0, 0, hInst, 0);


	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);
	*/

	//SDL_GL_CreateContext()

	//SDL_Init();



	Graphics::Init();
	Input::Init();

	GameObject gameObject;

	SpriteRenderer * renderer = new SpriteRenderer(&gameObject);

	Material* material = new Material();

	Shader* shader = new Shader("vertex.glsl", "fragment.glsl");

	material->setShader(shader);

	//material->setColor(255, 0, 0);

	renderer->setMaterial(material);

	Texture2D texture("test.jpg");
	

	//texture.resize(texture.getWidth() / 2, texture.getHeight() / 2);

	Sprite* sprite = new Sprite(&texture);

	renderer->setSprite(sprite);

	int a = 0;

	while (!Graphics::getGraphics()->isWindowShouldClose())
	{
		static std::chrono::high_resolution_clock clock;
		static std::chrono::steady_clock::time_point prev;
		prev = clock.now();


		
		SDL_Event* event = nullptr;
		Input::Update();
		while((event = Graphics::getGraphics()->PollEvent()) != nullptr) Input::UpdateEvent(event);
		
		for (int i = 0; i < texture.getWidth(); i++)
			texture.setPixel(i, Input::GetMousePosition().y / 600 * texture.getHeight(), 255, 0, 0);


		Vector3 pos(Input::GetMouseButtonDown(0) ? 100 : 300, 200, 0);
		gameObject.getTransform()->SetPosition(pos);

		Graphics::getGraphics()->Update(event);

		
		auto delta = clock.now() - prev;
		std::ofstream stream("test_time.txt", std::ios::app);
		stream << 1 / ((long double)delta.count() / 1000000000) << std::endl;
	}

	delete renderer;

	Graphics::DeInit();
	
	/*
	Wave_Header header;
	Data_Chunk chunk;

	load_wav_file("test.wav", &header, &chunk);

	ALCdevice* device = alcOpenDevice(alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER));
	ALCcontext* context = alcCreateContext(device, NULL);
	alcMakeContextCurrent(context);
	alGetError();
	ALuint buffer;
	alGenBuffers(1, &buffer);


	alBufferData(buffer, AL_FORMAT_STEREO8, chunk.samples, chunk.datasize, header.nSamplesPerSec);

	int a = alGetError();

	ALuint source;
	alGenSources(1, &source);
	alSourcei(source, AL_BUFFER, buffer);

	ALfloat listenerPos[] = { 0.0,0.0,0.0 };
	ALfloat listenerVel[] = { 0.0,0.0,0.0 };
	ALfloat listenerOri[] = { 0.0,0.0,-1.0, 0.0,1.0,0.0 }; // Position ...
	*/
	/*alListenerfv(AL_POSITION,listenerPos);
	alListenerfv(AL_VELOCITY, listenerVel);
	alListenerfv(AL_ORIENTATION,listenerOri);

	alSourcef(source, AL_PITCH, 1.0f); 
	alSourcef(source,AL_GAIN,1.0f);
	alSourcefv(source,AL_POSITION,listenerPos);
	alSourcefv(source,AL_VELOCITY,listenerVel);*/
	/*alSourcei(source,AL_LOOPING,AL_TRUE);

	alSourcePlay(source);

	while (true);

	ALCcontext* context2 = alcGetCurrentContext();
	ALCdevice* dev = alcGetContextsDevice(context2);

	alcMakeContextCurrent(NULL);
	*/
	
	/*
	Graphics::Init();
	AudioManager::Init();

	GameObject gameObject;

	AudioListener* listener = new AudioListener(&gameObject);

	AudioSource* source = new AudioSource(&gameObject, new Audio("test.wav"));

	source->Play();

	while (source->getCurrentState() != AudioSourceState::Stopped);

	AudioManager::DeInit();
	Graphics::DeInit();
	*/
	/*while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UnregisterClass(classname, hInst);*/
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	if (message == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wparam, lparam);
}
