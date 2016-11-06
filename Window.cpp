#include "Window.h"



Window::Window(const char* title, int x, int y, int w, int h)
{
	m_window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	m_context = SDL_GL_CreateContext(m_window);
}


Window::~Window()
{
	SDL_DestroyWindow(m_window);
	SDL_GL_DeleteContext(m_context);
}


SDL_Window* Window::getSDLWindow() const {
	return m_window;
}

void Window::display() {
	SDL_GL_SwapWindow(m_window);
}