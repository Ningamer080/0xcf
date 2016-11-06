#pragma once
#include "Window.h"
#include "GPrint.h"
#include "Shader.h"
#include <string>

class Core
{
public:
	Core();
	~Core();

	void update();
	void processInput();
	void onInit();
	void onExit();

	enum State {
		RUN = 0,
		EXIT
	};

	State state;
private:
	Window* m_window;
	SDL_Event m_event;

	Shader shader;
};

