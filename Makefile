CC = gcc
OBJS = rpn.o
CFLAGS = -lm -Wall
PREFIX = usr/local

default: rpn

rpn: $(OBJS)
	$(CC) -o rpn $(OBJS) $(CFLAGS)

install:
	install -m 557 $(CURDIR)/rpn $(PREFIX)/bin/rpn

clean:
	rm $(PREFIX)/bin/rpn
