// shell.cc

#include "es2ld.h"
#include "hello.h"

#include <SDL.h>

IShell::~IShell() {
}

class Shell : public IShell {
private:
	SDL_Window *window;
	bool fullscreen = false;
	ivec2 size;

public:
	Shell() {
		size = initial_size;
		constexpr int use_es2 = 1;
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
			throw Error("SDL_Init failed");
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		if (use_es2) {
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
		} else {
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
		}
		if (!(window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN)))
			throw Error("SDL_CreateWindow failed");
		SDL_GL_CreateContext(window);
		es2_init(SDL_GL_GetProcAddress, use_es2);
		printf("GL_VENDOR: %s\n", glGetString(GL_VENDOR));
		printf("GL_RENDERER: %s\n", glGetString(GL_RENDERER));
		printf("GL_VERSION: %s\n", glGetString(GL_VERSION));
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	}
	bool process_events() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				return false;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					return false;
				case 'f':
					fullscreen = !fullscreen;
					SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
					break;
				}
				break;
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
					size.x = event.window.data1;
					size.y = event.window.data2;
				}
				break;
			default:
				break;
			}
		}
		return true;
	}
	ivec2 start_frame() {
		glViewport(0, 0, size.x, size.y);
		glClear(GL_COLOR_BUFFER_BIT);
		return size;
	}
	void end_frame() {
		SDL_GL_SwapWindow(window);
	}
};

IShell *new_Shell() {
	return new Shell();
}
