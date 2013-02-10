/******************************************************************
 * File Name: sample.c
 *
 * Description: GPIO Driver Sample Program
 *
 * Author: soi33org
 * Copyright (c) 2013, soi33org. All rights reserved.
 *****************************************************************/
#include <unistd.h>
#include "gpio_drv.h"

int main(int argc, char *argv[])
{
    int i;
    gpio_init();

    for(i = 7; i < 12; i++) {
        gpio_inout(i, E_GPIO_OUT);
    }
    
    for(i = 7; i < 12; i++) {
        gpio_write(i, 1);
        sleep(1);
        gpio_write(i, 0);
    }

    return 0;
}
