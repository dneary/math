
CC=gcc
CFLAGS=-I.
LIBS=-lm

all: estimate_pi

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

estimate_pi: estimate_pi.o
	gcc -o $@ $< $(LIBS)

clean:
	rm -f *.o estimate_pi
