/******************************************************************
 * File Name: gpio_drv.c
 *
 * Description: GPIO Driver Main Program for Raspberry Pi
 *
 * Author: soi33org
 * Copyright (c) 2013, soi33org. All rights reserved.
 *****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "gpio_drv.h"
#include "gpio_reg.h"

static volatile unsigned int *gpio_addr = 0;

#define PAGE_SIZE (4*1024)
#define BLOCK_SIZE (4*1024)

void gpio_init(void)
{
    int mem_fd;
    char *gpio_mem, *gpio_map;

    if((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        printf("Cannot open\n");
        exit(-1);
    }

    if((gpio_mem = malloc(PAGE_SIZE + (BLOCK_SIZE -1))) == NULL) {
        printf("Cannot allocate\n");
        exit(-1);
    }
    
    if((unsigned long)gpio_mem % PAGE_SIZE) {
        gpio_mem += (PAGE_SIZE - (unsigned long)gpio_mem % PAGE_SIZE);
    }
    
    gpio_map = (char *)mmap(
        (caddr_t)gpio_mem,
        BLOCK_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_FIXED,
        mem_fd,
        GPIO_BASE);
    
    if((long)gpio_map < 0) {
        printf("mmap error\n");
        exit(-1);
    }
    
    gpio_addr = (volatile unsigned *)gpio_map;
}
