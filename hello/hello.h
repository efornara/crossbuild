// hello.h

#include <memory>
#include <string>
#include <vector>

#include <cstddef>
#include <cstdint>
#include <cstdio>

using std::string;
using std::vector;

template <typename T>
using ptr = std::unique_ptr<T>;

using std::printf;

#include <glm/glm.hpp>

using vec2 = glm::vec2;
using vec3 = glm::vec3;
using vec4 = glm::vec4;
using mat4 = glm::mat4;
using ivec2 = glm::ivec2;

struct Error {
	Error(const char *format, ...)
#ifdef __GNUC__
			__attribute__((format(gnu_printf, 2, 3)))
#endif
			;
};

struct AssetData {
	const uint8_t *p;
	size_t n;
};

AssetData get_asset(const char *tag);
string get_license(const char *tag);

struct IShell {
	virtual ~IShell();
	virtual bool process_events() = 0;
	virtual ivec2 start_frame() = 0;
	virtual void end_frame() = 0;
};

IShell *new_Shell();

struct ISim {
	virtual ~ISim();
	virtual float step() = 0;
};

ISim *new_Sim();

constexpr const char *title = "Hello";
constexpr ivec2 initial_size = ivec2(960, 540);
