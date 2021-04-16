#! /usr/bin/python3

import fileinput
from os.path import expandvars

assets = {}

for line in fileinput.input():
	tag, mode, filename = line.split()
	with open(expandvars(filename), "rb") as f_blob:
		assets[tag] = f_blob.read()

print("""\
// generated by assets.py - do not edit

#include "hello.h"

#include <cstring>

// clang-format off
""")
for tag in assets:
	print("static const uint8_t @[] = {".replace("@", tag))
	tail = assets[tag]
	while len(tail) > 0:
		head, tail = tail[:16], tail[16:]
		print("\t", end="")
		for b in head:
			print("%d," % b, end="")
		print()
	print("};\n")
print("""\
// clang-format on

AssetData get_asset(const char *tag) {
	AssetData d;
	if (false) {""")
for tag in assets:
	print("""\
	} else if (!std::strcmp(tag, "@")) {
		d.p = @;
		d.n = sizeof(@);""".replace("@", tag))
print("""\
	} else {
		d.p = nullptr;
		d.n = 0;
	}
	return d;
}""")
