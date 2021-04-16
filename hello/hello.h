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

struct Size {
	float width, height;
};

struct IShell {
	virtual ~IShell();
	virtual bool process_events() = 0;
	virtual Size start_frame() = 0;
	virtual void end_frame() = 0;
};

IShell *new_Shell();

constexpr const char *title = "Hello";
constexpr Size initial_size{ 960, 540 };
