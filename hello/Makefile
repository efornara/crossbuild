VPATH = $(HOME)/git/crossbuild/hello

ifndef HOST
HOST=x86_64-linux-gnu
TAG=linux-x86_64
endif

ifndef TARGET
TARGET=debug
endif

CXX = $(HOST)-g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS =
LIBS =
OBJS = \
	main.o \
	shell.o \
	#

EXTRA_PATH = $(HOME)/crossbuild/build/$(TAG)

EXTRA_OBJS = $(EXTRA_PATH)/es2/es2ld.o

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
  -I$(HOME)/crossbuild/thirdparty/es2 \
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

$(OBJS): hello.h
