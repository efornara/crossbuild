/*
  hello_world_sdl2.c
  Written by Emanuele Fornara

  This is free and unencumbered software released into the public domain.

  Anyone is free to copy, modify, publish, use, compile, sell, or
  distribute this software, either in source code form or as a compiled
  binary, for any purpose, commercial or non-commercial, and by any
  means.

  In jurisdictions that recognize copyright laws, the author or authors
  of this software dedicate any and all copyright interest in the
  software to the public domain. We make this dedication for the benefit
  of the public at large and to the detriment of our heirs and
  successors. We intend this dedication to be an overt act of
  relinquishment in perpetuity of all present and future rights to this
  software under copyright law.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.

  For more information, please refer to <http://unlicense.org/>
*/

#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>

#include "es2ld.h"

void usage() {
	fprintf(stderr, "usage: hello_world_sdl2 [es2|gl2]\n");
	exit(1);
}

void fatal(const char *msg) {
	fprintf(stderr, "%s.\n", msg);
	exit(1);
}

char info_log[1024];

GLuint compile_shader(GLenum type, const char *src) {
	GLuint shader;
	GLint status;

	shader = glCreateShader(type);
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (!status) {
		glGetShaderInfoLog(shader, sizeof(info_log) - 1, NULL, info_log);
		fprintf(stderr, "* Shader *\n%s\n", src);
		fprintf(stderr, "* InfoLog *\n%s\n", info_log);
		fatal("glCompileShader failed");
	}
	return shader;
}

GLuint create_program(const char *vertex_src, const char *fragment_src) {
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint program;
	GLint status;

	vertex_shader = compile_shader(GL_VERTEX_SHADER, vertex_src);
	fragment_shader = compile_shader(GL_FRAGMENT_SHADER, fragment_src);
	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (!status) {
		glGetProgramInfoLog(program, sizeof(info_log) - 1, NULL, info_log);
		fprintf(stderr, "* InfoLog *\n%s\n", info_log);
		fatal("glLinkProgram failed");
	}
	return program;
}

const char *vert_shader_src = "attribute vec4 pos;\n"
							  "void main() {\n"
							  "  gl_Position = pos;\n"
							  "}\n";

const char *frag_shader_src = "#ifdef GL_ES\n"
							  "precision mediump float;\n"
							  "#endif\n"
							  "void main() {\n"
							  "  gl_FragColor = vec4(0.9, 0.9, 0.9, 1.0);\n"
							  "}\n";

GLuint prog;
GLint pos;

void init() {
	printf("GL_VENDOR: %s\n", glGetString(GL_VENDOR));
	printf("GL_RENDERER: %s\n", glGetString(GL_RENDERER));
	printf("GL_VERSION: %s\n", glGetString(GL_VERSION));
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	prog = create_program(vert_shader_src, frag_shader_src);
	pos = glGetAttribLocation(prog, "pos");
}

#define WIDTH 400
#define HEIGHT 400

GLfloat verts[] = {
	0.0f, 0.6f, -0.7f, -0.6f, 0.7f, -0.6f
};

void render() {
	glViewport(0, 0, WIDTH, HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(prog);
	glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, verts);
	glEnableVertexAttribArray(pos);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(int argc, char *argv[]) {
	SDL_Window *window = NULL;
	int use_es2 = 1;
	int quit = 0;
	SDL_Event event;

	if (argc == 2) {
		if (!strcmp(argv[1], "es2"))
			use_es2 = 1;
		else if (!strcmp(argv[1], "gl2"))
			use_es2 = 0;
		else
			usage();
	} else if (argc > 2) {
		usage();
	}

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		fatal("SDL_Init failed");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	if (use_es2) {
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
							SDL_GL_CONTEXT_PROFILE_ES);
	} else {
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
							SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	}

	if ((window = SDL_CreateWindow("hello_world_sdl2", SDL_WINDOWPOS_UNDEFINED,
								   SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
								   SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN)) ==
		NULL)
		fatal("SDL_CreateWindow failed");

	SDL_GLContext context = SDL_GL_CreateContext(window);
	es2_init(SDL_GL_GetProcAddress, use_es2);
	init();

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = 1;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
				break;
			}
		}
		render();
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
