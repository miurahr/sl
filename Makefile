#==========================================
#    Makefile: makefile for sl 5.0
#	Copyright 1993, 1998, 2013
#                 Toyoda Masashi 
#		  (mtoyoda@acm.org)
#                 2014 Hiroshi Miura
#                 (miurahr@acm.org)
#	Last Modified: 2014/ 3/ 27
#==========================================

CC=gcc
CFLAGS=-O
LDFLAGS=-lncurses

OS=unknown
DRIVER=generic
ifeq ($(OS),Windows_NT)
    OS = win32
    DRIVER = waveout
    LDFLAGS += -lwaveout
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        OS = linux
        DRIVER = alsa
        LDFLAGS += -lasound
    endif
    ifeq ($(UNAME_S),Darwin)
       OS = darwin
       DRIVER = darwin
    endif
    ifeq ($(UNAME_S),Solaris)
        OS = solaris
        DRIVER = audio
    endif
endif

sl: sl.c sl.h sl-whistle-$(DRIVER).o
	$(CC) $(CFLAGS) -o sl sl.c sl-whistle-$(DRIVER).o $(LDFLAGS)

sl-whistle-$(DRIVER).o: sl-whistle-$(DRIVER).c sl-whistle.h
	$(CC) $(CFLAGS) -c sl-whistle-$(DRIVER).c

