// shell.cc

#include "hello.h"
#include "es2ld.h"

#include <SDL.h>
#include <SDL_gamecontroller.h>

IShell::~IShell() {
}

class Shell : public IShell {
private:
	SDL_Window *window;
	SDL_GameController *controller = nullptr;
	bool fullscreen = false;
	ivec2 size;

public:
	Shell() {
		size = initial_size;
		constexpr int use_es2 = 1;
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK) < 0)
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
		if (!(window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN)))
			throw Error("SDL_CreateWindow failed");
		SDL_GL_CreateContext(window);
		es2_init(SDL_GL_GetProcAddress, use_es2);
		printf("GL_VENDOR: %s\n", glGetString(GL_VENDOR));
		printf("GL_RENDERER: %s\n", glGetString(GL_RENDERER));
		printf("GL_VERSION: %s\n", glGetString(GL_VERSION));
		for (int i = 0; i < SDL_NumJoysticks(); i++) {
			if (!SDL_IsGameController(i))
				continue;
			if (!(controller = SDL_GameControllerOpen(i)))
				throw Error("SDL_GameControllerOpen %d failed", i);
			break;
		}
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
	string controller_info() {
		if (!controller)
			return "No controllers.";
		string s;
		s = SDL_GameControllerName(controller);
		s += '\n';
		for (int i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
			s += SDL_GameControllerGetButton(controller, (SDL_GameControllerButton)i) ? 'X' : '.';
		s += '\n';
		for (int i = 0; i < SDL_CONTROLLER_AXIS_MAX; i++) {
			char buf[32];
			snprintf(buf, sizeof(buf), "%d\n", SDL_GameControllerGetAxis(controller, (SDL_GameControllerAxis)i));
			s += buf;
		}
		return s;
	}
	ivec2 start_frame() {
		return size;
	}
	void end_frame() {
		SDL_GL_SwapWindow(window);
	}
};

IShell *new_Shell() {
	return new Shell();
}
