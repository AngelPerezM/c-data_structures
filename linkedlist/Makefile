#!/usr/bin/make -f

CC=gcc -Os

BUILD_DEBUG ?= yes #<-- ifndef define
CDEBUG =-g
CFLAGS = -Wall -Wextra -Werror -Wformat=2 -pipe \
    -Wnull-dereference -Wlogical-op -Wduplicated-cond -Wduplicated-branches -Wshadow
#ifdef
CFLAGS += -g -DDEBUG
#endif

SRCS_C = source/*.c

linkedlist.t: linkedlist.o linkedlist.t.o
	$(CC) $(CFLAGS) linkedlist.t.o linkedlist.o -o $@

linkedlist.t.o: source/linkedlist.t.c include/linkedlist.h
	$(CC) $(CFLAGS) -c source/linkedlist.t.c

linkedlist.o: include/linkedlist.h source/linkedlist.c
	$(CC) $(CFLAGS) -c source/linkedlist.c

.PHONY: clean
clean: ; rm -f *.o linkedlist
