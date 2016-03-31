LIBS =
GCC = gcc
CFLAGS = -O -pthread

all: msh

msh: hw3.c
		${GCC} ${CFLAGS} -o msh hw3.c ${LIBS}

clean:
	rm -f *.o core msh