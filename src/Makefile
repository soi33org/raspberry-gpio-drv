##################################################################
# File Name: Makefile
#
# Description: GPIO Driver Makefile
#
# Author: soi33org
# Copyright (c) 2013, soi33org. All rights reserved.
##################################################################

CC = gcc
AR = ar
INC = -I../include
CFLAGS = -Wall -O2 $(INC)
ARFLAGS = vr

ARC = gpio_drv.a
OBJS = gpio_drv.o
SRCS = gpio_drv.c

.SUFFIXES: .c .o

all: $(ARC)

$(ARC): $(OBJS)
	$(AR) $(ARFLAGS) $(ARC) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(ARC) $(OBJS)
