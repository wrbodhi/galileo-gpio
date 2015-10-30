/* gpioutils.c -  GPIO utility routines */

/*
 * Copyright (c) 2015, Wind River Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined(CONFIG_STDOUT_CONSOLE)
#include <stdio.h>
#define PRINT           printf
#else
#include <misc/printk.h>
#define PRINT           printk
#endif

#include <zephyr.h>
#include <gpio.h>

#include "galileo2GPIO.h"

/* PCAL9535A GPIO Expander pin numbering */
#define P0(pin) (pin)
#define P1(pin) ((pin)+8)

/*
 * gpio_output_set - set the output value of a pin
 *
 * output_pin: Arduino connector pin number
 * value: 0=set output to low, otherwise set high
 *
 * Returns DEV_OK if the operation succeeded, otherwise DEV_FAIL.
 *
 * Note: comments below "gpioXX" refer to the Linux GPIO naming convention
 */

int gpio_output_set (int output_pin, int value)
    {

    int status = DEV_OK;

    switch (output_pin)
        {
        case 0:
            /* gpio11=signal */

            status = gpio_pin_write(gpio07, 3, value);

            break;

        case 1:
            /* gpio12=signal */

            status = gpio_pin_write(gpio07, 4, value);

            break;

        case 2:
            /* gpio13=signal */

            status = gpio_pin_write(gpio07, 5, value);

            break;

        case 3:
            /* gpio14=signal */

            status = gpio_pin_write(gpio07, 6, value);

            break;

        case 4:
            /* gpio6=signal */

            status = gpio_pin_write(gpio_sus, 4, value);

            break;

        case 5:
            /* gpio0=signal */

            status = gpio_pin_write(gpioLegacy, 0, value);

            break;

        case 6:
            /* gpio1=signal */

            status = gpio_pin_write(gpioLegacy, 1, value);

            break;

        case 7:
            /* gpio38=signal */

            status = gpio_pin_write(gpioEXP1, P0(6), value);

            break;

        case 8:
            /* gpio40=signal*/

            status = gpio_pin_write(gpioEXP1, P1(0), value);

            break;

        case 9:
            /* gpio4=signal */

            status = gpio_pin_write(gpio_sus, 2, value);

            break;

        case 10:
            /* gpio10=signal */

            status = gpio_pin_write(gpio07, 2, value);

            break;

        case 11:
            /* gpio5=signal */

            status = gpio_pin_write(gpio_sus, 3, value);

            break;

        case 12:
            /* gpio15=signal*/

            status = gpio_pin_write(gpio07, 7, value);

            break;

        case 13:
            /* gpio7=signal */

            status = gpio_pin_write(gpio_sus, 5, value);

            break;

        default:
            status = DEV_FAIL;
            break;
        }

    if (status != DEV_OK)
        {
        PRINT("GPIO output set error %d!!\n", status);
        }

    return status;
    }

/*
 * gpio_input_get - get value of a pin
 *
 * input_pin: Arduino connector pin number
 * val_ptr: Address to write the logic value of the pin
 *          (0 if low, 1 if high)
 *
 * Returns DEV_OK if the operation succeeded, otherwise DEV_FAIL.
 *
 * Note: comments below "gpioXX" refer to the Linux GPIO naming convention
 */

int gpio_input_get (int input_pin, int *val_ptr)
    {
    int value;
    int status = DEV_OK;

    switch (input_pin)
        {
        case 0:
            /* gpio11=signal */

            status = gpio_pin_read(gpio07, 3, &value);

            break;

        case 1:
            /* gpio12=signal */

            status = gpio_pin_read(gpio07, 4, &value);

            break;

        case 2:
            /* gpio13=signal*/

            status = gpio_pin_read(gpio07, 5, &value);

            break;

        case 3:
            /* gpio14=signal */

            status = gpio_pin_read(gpio07, 6, &value);

            break;

        case 4:
            /* gpio6=signal */

            status = gpio_pin_read(gpio_sus, 4, &value);

            break;

        case 5:
            /* gpio0=signal*/

            status = gpio_pin_read(gpioLegacy, 0, &value);

            break;

        case 6:
            /* gpio1=signal */

            status = gpio_pin_read(gpioLegacy, 1, &value);

            break;

        case 7:
            /* gpio38=signal */

            status = gpio_pin_read(gpioEXP1, P0(6), &value);

            break;

        case 8:
            /* gpio40=signal */

            status = gpio_pin_read(gpioEXP1, P1(0), &value);

            break;

        case 9:
            /* gpio4=signal */

            status = gpio_pin_read(gpio_sus, 2, &value);

            break;

        case 10:
            /* gpio10=signal */

            status = gpio_pin_read(gpio07, 2, &value);

            break;

        case 11:
            /* gpio5=signal */

            status = gpio_pin_read(gpio_sus, 3, &value);

            break;

        case 12:
            /* gpio15=signal */

            status = gpio_pin_read(gpio07, 7, &value);

            break;

        case 13:
            /* gpio7=signal */

            status = gpio_pin_read(gpio_sus, 5, &value);

            break;

        default:
            status = DEV_FAIL;
            break;
        }

    if (value == 0)
        *val_ptr = 0;
    else
        *val_ptr = 1;

    if (status != DEV_OK)
        {
        PRINT("GPIO read error %d!!\n", status);
        }

    return status;

    }

