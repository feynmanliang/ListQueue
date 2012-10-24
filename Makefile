CC=gcc
CFLAGS= -ansi -Wall -pedantic -g

CFILES=myQueue.c shop.c
HFILES=myQueue.h
OFILES=myQueue.o shop.o

all:	shop

%.o:	%.c $(HFILES)
	$(CC) -c $(CFLAGS) $< -o $@

shop:	$(OFILES) $(HFILES)
	$(CC) $(CFLAGS) $(OFILES) -o bin/shop

clean:	
	rm -f *~ bin/shop $(OFILES)
