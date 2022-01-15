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

template<typename T>
struct v2 {
	T x, y;
	constexpr v2(T xx = 0, T yy = 0) : x{xx}, y{yy} {}
	const T &operator[](size_t n) const { return (&x)[n]; }
	v2 operator+(v2 v) { return v2{x + v.x, y + v.y}; }
};

using vec2 = v2<float>;
using ivec2 = v2<int>;

struct ortho {
	float m[4][4]{};
	constexpr ortho(float l, float r, float b, float t) {
		m[0][0] = 2.0f / (r - l);
		m[1][1] = 2.0f / (t - b);
		m[2][2] = -1.0f;
		m[3][0] = -(r + l) / (r - l);
		m[3][1] = -(t + b) / (t - b);
		m[3][3] = 1.0f;
	}
	operator const float *() const { return &m[0][0]; }
};

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
	virtual string controller_info() = 0;
	virtual ivec2 start_frame() = 0;
	virtual void end_frame() = 0;
};

IShell *new_Shell();

struct State {
	string controller_info;
};

struct IRenderer {
	virtual ~IRenderer();
	virtual void render(ivec2 size, const State &state) = 0;
};

IRenderer *new_Renderer();

constexpr const char *title = "Hello";
constexpr ivec2 initial_size = ivec2(960, 540);
