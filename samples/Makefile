# Salad Samples Makefile

# Compiler options
CC      = gcc
INCPATH = -I../include
LIBPATH = -L..
CFLAGS  = -ansi -g -pedantic -pipe -O2 -Wall

# Linker options
LIBS1   = -lsalad
LIBS2   = -lsalad_daemon
LINK    = gcc

# Build rules
all: daemon list vector

daemon:
	$(CC) $(CFLAGS) -o daemon $(LIBPATH) $(INCPATH) $(LIBS1) $(LIBS2) daemon.c

list:
	$(CC) $(CFLAGS) -o list $(LIBPATH) $(INCPATH) $(LIBS1) list.c

vector:
	$(CC) $(CFLAGS) -o vector $(LIBPATH) $(INCPATH) $(LIBS1) vector.c

clean:
	rm -f *.o daemon list vector
