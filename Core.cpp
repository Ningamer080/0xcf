#include "Core.h"

Core::Core()
{
	
}


Core::~Core()
{
	delete m_window;
}


void Core::update() {

	m_window->display();
}

void Core::processInput() {
	while (SDL_PollEvent(&m_event)) {
		if(m_event.type == SDL_QUIT) {
			state = State::EXIT;
		}
	}
}

void Core::onInit() {
	state = State::RUN;
	SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);
	m_window = new Window("0xcf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

	GLenum err;
	err = glewInit();
	if (GLEW_OK != err) {
		printerror("Failed to initialize glew !");
		std::cout << glewGetErrorString(err) << "\n";
		SDL_Quit();
		state = State::EXIT;
	}

	shader.createProgram("shader.frag", "shader.vert");
	shader.Bind();
	
}

void Core::onExit() {
	SDL_Quit();
}