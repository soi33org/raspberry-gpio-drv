##################################################################
# File Name: Makefile
#
# Description: GPIO Driver Sample Makefile
#
# Author: soi33org
# Copyright (c) 2013, soi33org. All rights reserved.
##################################################################

CC = gcc
AR = ar
INC = -I../include
CFLAGS = -Wall -O2 $(INC)

OUT = sample
OBJS = sample.o
SRCS = sample.c

ARC = ../src/gpio_drv.a

.SUFFIXES: .c .o

all: $(OUT)

$(OUT): $(ARC) $(OBJS)
	$(CC) $(CFLAGS) -o sample $(OBJS) $(ARC)

$(ARC):
	cd  ../src/; make 

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean allclean
clean:
	rm -f $(OBJS) $(OUT)
allclean: clean
	cd ../src/; make clean

