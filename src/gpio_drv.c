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

#define GPIO_IN(g)                                          \
    (*(gpio_addr + ((g) / (10))) &= ~(7 < (((g)%10) * 3)) )

#define GPIO_OUT(g) do {                                         \
        GPIO_IN(g);                                              \
        (*(gpio_addr + ((g)/ (10))) |= (1 < ((g)%10 * 3)) );     \
    } while(0)

#define GPIO_SET *(gpio_addr + 7)
#define GPIO_CLR *(gpio_addr + 10)
#define GPIO_GET *(gpio_addr + 13)

#define MAX_PORT (25)
static char valid_port[] =
{
    1,1,0,0,  0,0,0,1,
    1,1,1,1,  0,0,1,1,
    0,1,1,0,  0,1,1,1,
    1,1
};

#define IS_VALID_PORT(port) ((port < 0 || 25 < port) ? 0 : (int)valid_port[port] )

void gpio_init(void)
{
    int mem_fd;
    char *gpio_map;
#ifndef NO_MALLOC
    char *gpio_mem;
#endif

    if((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        printf("Cannot open\n");
        exit(-1);
    }

#ifndef NO_MALLOC
    if((gpio_mem = malloc(PAGE_SIZE + (BLOCK_SIZE -1))) == NULL) {
        printf("Cannot allocate\n");
        exit(-1);
    }
    
    if((unsigned int)gpio_mem % PAGE_SIZE) {
        gpio_mem += (PAGE_SIZE - (unsigned int)gpio_mem % PAGE_SIZE);
    }
    
    gpio_map = (char *)mmap(
        (caddr_t)gpio_mem,
        BLOCK_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_FIXED,
        mem_fd,
        GPIO_BASE);
#else
    gpio_map = (char *)mmap(
        NULL,
        BLOCK_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        mem_fd,
        GPIO_BASE);
#endif /* NO_MALLOC */

    if((long)gpio_map < 0) {
        printf("mmap error\n");
        exit(-1);
    }
    gpio_addr = (volatile unsigned *)gpio_map;
}

void gpio_inout(int port_no, GPIO_INOUT inout)
{
    if(!(IS_VALID_PORT(port_no) && gpio_addr)) return;
    switch(inout) {
    case E_GPIO_IN:
        GPIO_IN(port_no);
        break;
    case E_GPIO_OUT:
        GPIO_OUT(port_no);
        break;
    default:
        break;
    }
    
}

void gpio_write(int port_no, int data)
{
    if(!(IS_VALID_PORT(port_no) && gpio_addr)) return;
    if(data > 0) {
        GPIO_SET = 1 << (port_no);
    } else {
        GPIO_CLR = 1 << (port_no);
    }
}

int gpio_read(int port_no)
{
    if(!(IS_VALID_PORT(port_no) && gpio_addr)) return 0;
    return (GPIO_GET & (1 << port_no) ? 1 : 0);
}



