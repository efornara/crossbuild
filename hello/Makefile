VPATH = $(HOME)/git/crossbuild/hello

ifndef HOST
HOST=x86_64-linux-gnu
TAG=linux-x86_64
endif

ifndef TARGET
TARGET=debug
endif

CXX = $(HOST)-g++
CXXFLAGS = -std=c++17 -Wall $(ARCHFLAGS)
LDFLAGS =
LIBS =
OBJS = \
	main.o \
	renderer.o \
	shell.o \
	licenses.o \
	assets.o \
	es2ld.o \
	#

EXTRA_PATH = $(HOME)/crossbuild/build/$(TAG)

ifeq ($(TARGET),debug)
CXXFLAGS += -ggdb -DDEBUG
LDFLAGS += -ggdb
endif

ifeq ($(TARGET),release)
CXXFLAGS += -O2
LDFLAGS += -s -static-libgcc -static-libstdc++
endif

ifeq ($(TARGET),final)
CXXFLAGS += -O2 -flto
LDFLAGS += -s -static-libgcc -static-libstdc++ -flto
endif

CXXFLAGS += \
  -I$(HOME)/git/crossbuild/hello \
  -I$(HOME)/crossbuild/thirdparty/stb \
  #

SDL2_CONFIG = $(HOME)/crossbuild/local/$(TAG)/bin/sdl2-config
CXXFLAGS +=  `$(SDL2_CONFIG) --cflags`
LIBS += `$(SDL2_CONFIG) --static-libs`

BIN=hello-$(TAG).bin

all: $(BIN)

clean:
	rm -f *.o *.bin

format:
	clang-format -i *.h *.cc

$(BIN): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(BIN) $(OBJS) $(EXTRA_OBJS) $(LIBS)

assets.cc: assets.txt
	python3 $(HOME)/git/crossbuild/hello/assets.py <$< >$@

$(OBJS): hello.h
