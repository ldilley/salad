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
HEADERS = include/salad/daemon.h \
          include/salad/network.h \
          include/salad/string.h \
          include/salad/time.h \
          include/salad/types.h
SOURCES = src/daemon.c \
          src/network.c \
          src/string.c \
          src/time.c
OBJECTS = src/daemon.o \
          src/network.o \
          src/string.o \
          src/time.o
TARGET_LIB = libsalad.so

# Build rules
$(TARGET_LIB): $(OBJECTS)
	$(LINK) $(LDFLAGS) -o $(TARGET_LIB) $(OBJECTS) $(LIBS)

clean:
	rm -f $(OBJECTS) $(TARGET_LIB)
