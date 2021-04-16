// main.cc

#include "hello.h"

#include <cstdarg>
#include <cstdlib>
#include <cstring>

Error::Error(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	std::fprintf(stderr, "hello: ");
	std::vfprintf(stderr, format, ap);
	std::fprintf(stderr, ".\n");
	va_end(ap);
	std::exit(1);
}

[[noreturn]] static void usage() {
	printf(R"(
usage: hello [options]

options:
  -h              show this message and exit
  -l              show license and exit
  -t component    show third party license and exit (? for list)

)");
	std::exit(0);
}

[[noreturn]] static void show_license(const char *tag) {
	string s = get_license(tag);
	printf("%s", s.c_str());
	std::exit(0);
}

static void parse_args(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		const char *s = argv[i];
		if (!std::strcmp(s, "-h")) {
			usage();
		} else if (!std::strcmp(s, "-l")) {
			show_license(nullptr);
		} else if (!std::strcmp(s, "-t")) {
			if (++i == argc)
				usage();
			const char *tag = argv[i];
			show_license(tag);
		} else {
			usage();
		}
	}
}

int main(int argc, char *argv[]) {
	parse_args(argc, argv);
	ptr<IShell> shell(new_Shell());
	ptr<ISim> sim(new_Sim());
	while (shell->process_events()) {
		shell->start_frame();
		printf("bullet: %f\n", sim->step());
		shell->end_frame();
	}
}
