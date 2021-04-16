// licenses.cc

#include "hello.h"

#include <cstring>

namespace licenses {

struct Definition {
	const char *tag;
	const char *description;
} definitions[]{
	{ "bullet", "Bullet Continuous Collision Detection and Physics Library" },
	{ "es2", "ES 2.0 Loader by Emanuele Fornara" },
	{ "sdl2", "Simple DirectMedia Layer" },
	{ "stb", "stb_image from http://nothings.org/stb" },
};

string get(const char *tag) {
	if (!tag)
		return (const char *)get_asset("license_self").p;
	if (!std::strcmp(tag, "?")) {
		string s = "thirdparty components used by this software:\n\n";
		for (auto d : definitions) {
			s += d.tag;
			s += " - ";
			s += d.description;
			s += "\n";
		}
		s += "\n";
		return s;
	}
	for (auto d : definitions) {
		if (!std::strcmp(tag, d.tag)) {
			string s = "The license for '";
			s += d.description;
			s += "' follows:\n\n";
			string asset_tag = "license_";
			asset_tag += d.tag;
			s += (const char *)get_asset(asset_tag.c_str()).p;
			return s;
		}
	}
	return get("?");
}

} // namespace licenses

string get_license(const char *tag) {
	return licenses::get(tag);
}
