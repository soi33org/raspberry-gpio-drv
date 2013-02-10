/******************************************************************
 * File Name: sample.c
 *
 * Description: GPIO Driver Sample Program
 *
 * Author: soi33org
 * Copyright (c) 2013, soi33org. All rights reserved.
 *****************************************************************/
#include "gpio_drv.h"

int main(int argc, char *argv[])
{
    gpio_init();

    gpio_inout(7, E_GPIO_OUT);

    gpio_write(7, 1);
    sleep(5);
    gpio_write(7, 0);
    
    return 0;
}
