// renderer.cc

#include "hello.h"
#include "es2ld.h"

IRenderer::~IRenderer() {
}

void mirror_y(unsigned char *p, int width, int height) {
	size_t row_length = width * 4;
	unsigned char *from = p, *to = p + row_length * (height - 1);
	for (int y = 0; y < height / 2; y++) {
		for (size_t i = 0; i < row_length; i++) {
			unsigned char tmp = to[i];
			to[i] = from[i];
			from[i] = tmp;
		}
		from += row_length;
		to -= row_length;
	}
}

GLuint load_texture(const char *tag) {
	AssetData asset = get_asset(tag);
	if (!asset.p)
		throw Error("load_texture: get_asset failed for %s", tag);
	constexpr int width{128}, height{64}, size{width * height * 4};
	if (asset.n != size)
		throw Error("load_texture: image size not supported for for %s", tag);
	unsigned char data[size];
	std::memcpy(data, asset.p, size);
	mirror_y(data, width, height);
	GLuint id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	return id;
}
	
char info_log[1024];

GLuint compile_shader(GLenum type, const char *src) {
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (!status) {
		glGetShaderInfoLog(shader, sizeof(info_log) - 1, nullptr, info_log);
		std::fprintf(stderr, "* Shader *\n%s\n", src);
		std::fprintf(stderr, "* InfoLog *\n%s\n", info_log);
		throw Error("glCompileShader failed");
	}
	return shader;
}

GLuint create_program(const char *vertex_src, const char *fragment_src) {
	GLuint vertex_shader = compile_shader(GL_VERTEX_SHADER, vertex_src);
	GLuint fragment_shader = compile_shader(GL_FRAGMENT_SHADER, fragment_src);
	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);
	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (!status) {
		glGetProgramInfoLog(program, sizeof(info_log) - 1, NULL, info_log);
		std::fprintf(stderr, "* InfoLog *\n%s\n", info_log);
		throw Error("glLinkProgram failed");
	}
	return program;
}

const char *vertex_src = R"(
uniform mat4 u_mvp;

attribute vec2 a_pos;
attribute vec2 a_uv;

varying vec2 v_uv;

void main() {
	gl_Position = u_mvp * vec4(a_pos, 0, 1);
	v_uv = a_uv;
}
)";

const char *fragment_src = R"(
#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D u_tex;

varying vec2 v_uv;

void main() {
	gl_FragColor = texture2D(u_tex, v_uv);
}
)";

struct Vertex {
	vec2 pos;
	vec2 uv;
};

class Shader {
private:
	GLuint prg;
	GLint u_mvp;
	GLint u_tex;
	GLint a_pos;
	GLint a_uv;
public:
	Shader() {
		prg = create_program(vertex_src, fragment_src);
		u_mvp = glGetUniformLocation(prg, "u_mvp");
		u_tex = glGetUniformLocation(prg, "u_tex");
		a_pos = glGetAttribLocation(prg, "a_pos");
		a_uv = glGetAttribLocation(prg, "a_uv");
	}
	void render_triangles(const ortho &mvp, GLuint tex, const vector<Vertex> &v) {
		glUseProgram(prg);
		glUniformMatrix4fv(u_mvp, 1, GL_FALSE, mvp);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex);
		glUniform1i(u_tex, 0);
		glVertexAttribPointer(a_pos, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), &v[0].pos[0]);
		glVertexAttribPointer(a_uv, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), &v[0].uv[0]);
		glEnableVertexAttribArray(a_pos);
		glEnableVertexAttribArray(a_uv);
		glDrawArrays(GL_TRIANGLES, 0, v.size());
	}
};


class Renderer : public IRenderer {
private:
	Shader shader;
	GLuint t_charmap;
	vector<Vertex> v;
	void quad(vec2 pos, vec2 size, vec2 uv = vec2(0, 0), vec2 delta_uv = vec2(1, 1)) {
		v.push_back(Vertex{pos, uv});
		v.push_back(Vertex{pos + vec2(size.x, 0), uv + vec2(delta_uv.x, 0)});
		v.push_back(Vertex{pos + size, uv + delta_uv});
		v.push_back(Vertex{pos, uv});
		v.push_back(Vertex{pos + size, uv + delta_uv});
		v.push_back(Vertex{pos + vec2(0, size.y), uv + vec2(0, delta_uv.y)});
	}
	void character(vec2 &cursor, char c) {
		static constexpr vec2 size = vec2(7, 9);
		float du = size.x / 128, dv = size.y / 64.0;
		if (c == '\n') {
			cursor.x = 0;
			cursor.y += size.y;
			return;
		}
		if (!std::isprint(c))
			return;
		c -= 32;
		float col = c % 18, row = c / 18;
		quad(cursor, size, vec2(col * du, 1 - (row * dv)), vec2(du, -dv));
		cursor.x += size.x;
	}
	void render_controller(float aspect, const string &s) {
		ortho mvp{0.0f, 180.0f * aspect, 180.0f, 0.0f};
		v.clear();
		vec2 cursor(0);
		for (char c : s)
			character(cursor, c);
		shader.render_triangles(mvp, t_charmap, v);
	}
public:
	Renderer() {
		t_charmap = load_texture("charmap");
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	}
	void render(ivec2 size, const State &state) {
		glViewport(0, 0, size.x, size.y);
		glClear(GL_COLOR_BUFFER_BIT);
		float aspect = size.x / (float)size.y;
		render_controller(aspect, state.controller_info);
	}
};

IRenderer *new_Renderer() {
	return new Renderer();
}
