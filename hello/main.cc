// main.cc

#include "hello.h"

#include <cstdarg>
#include <cstdlib>

Error::Error(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	std::fprintf(stderr, "hello: ");
	std::vfprintf(stderr, format, ap);
	std::fprintf(stderr, ".\n");
	va_end(ap);
	std::exit(1);
}

int main(int argc, char *argv[]) {
	ptr<IShell> shell(new_Shell());
	while (shell->process_events()) {
		shell->start_frame();
		shell->end_frame();
	}
}
