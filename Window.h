#pragma once
#include <SDL.h>
#include <GL\glew.h>

class Window
{
public:
	Window(const char* title, int x, int y, int w, int h);
	~Window();

	SDL_Window* getSDLWindow() const;

	void display();

private:
	SDL_Window* m_window;
	SDL_GLContext m_context;
};

