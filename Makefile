# Salad Makefile

# Compiler options
CC      = gcc
INC     = -Iinclude
CFLAGS  = $(INC) -ansi -fPIC -g -pedantic -pipe -O2 -Wall

# Linker options
LIBS    =
LINK    = gcc
LDFLAGS = -shared

# Files
HEADERS = include/salad/config.h \
          include/salad/list.h \
          include/salad/memory.h \
          include/salad/network.h \
          include/salad/string.h \
          include/salad/time.h \
          include/salad/types.h \
          include/salad/vector.h
SOURCES = src/list.c \
          src/memory.c \
          src/network.c \
          src/string.c \
          src/time.c \
          src/vector.c
OBJECTS = src/list.o \
          src/memory.o \
          src/network.o \
          src/string.o \
          src/time.o \
          src/vector.o

TARGET_LIB1 = libsalad.so
TARGET_LIB2 = libsalad_daemon.so

# Build rules
all: $(TARGET_LIB1) $(TARGET_LIB2) subsystem

$(TARGET_LIB1): $(OBJECTS)
	$(LINK) $(LDFLAGS) -o $(TARGET_LIB1) $(OBJECTS) $(LIBS)

$(TARGET_LIB2): src/daemon.o
	$(LINK) $(LDFLAGS) -o $(TARGET_LIB2) src/daemon.o $(LIBS)

subsystem:
	cd samples && $(MAKE)

clean:
	rm -f $(OBJECTS) $(TARGET_LIB1) $(TARGET_LIB2) src/daemon.o && cd samples && $(MAKE) clean
