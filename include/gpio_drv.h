/******************************************************************
 * File Name: gpio_drv.h
 *
 * Description: GPIO Driver Header for Raspberry Pi
 *
 * Author: soi33org
 * Copyright (c) 2013, soi33org. All rights reserved.
 *****************************************************************/
#ifndef __GPIO_DRV_H_
#define __GPIO_DRV_H_

typedef enum {
    E_GPIO_IN = 0,
    E_GPIO_OUT
}GPIO_INOUT;

void gpio_init(void);
void gpio_inout(int port_no, GPIO_INOUT);
void gpio_write(int port_no, int data);
int gpio_read(int port_no);

#endif /* __GPIO_DRV_H_ */
