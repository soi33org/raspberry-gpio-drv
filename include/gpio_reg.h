/******************************************************************
 * File Name: gpio_reg.h
 *
 * Description: GPIO Resister Header for Raspberry Pi
 *
 * Author: soi33org
 * Copyright (c) 2013, soi33org. All rights reserved.
 *****************************************************************/
#ifndef __GPIO_REG_H_
#define __GPIO_REG_H_

#define GPIO_BASE  (0x20200000)

#define GPIO_FSEL0 (GPIO_BASE + 0x0)
#define GPIO_FSEL1 (GPIO_BASE + 0x4)
#define GPIO_FSEL2 (GPIO_BASE + 0x8)
#define GPIO_FSEL3 (GPIO_BASE + 0xC)
#define GPIO_FSEL4 (GPIO_BASE + 0x10)
#define GPIO_FSEL5 (GPIO_BASE + 0x14)

#define GPIO_SET0 (GPIO_BASE + 0x1C)
#define GPIO_SET1 (GPIO_BASE + 0x20)

#define GPIO_CLR0 (GPIO_BASE + 0x28)
#define GPIO_CLR1 (GPIO_BASE + 0x2C)



#endif /* __GPIO_REG_H_ */
