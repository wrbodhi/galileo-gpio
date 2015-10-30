/* galileo2GPIO.c - Monitor GPIO digital values */

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

/*
 * Microkernel version of GPIO demo runs an endless loop blinking the on-board
 * LED (D13).  It also monitors a switch connected to connector pin D3 turning
 * on or off an LED attached to D4 to indicate the value of the switch.
 *
 */

#include <zephyr.h>
#include <gpio.h>

#include "galileo2GPIO.h"

/* specify which Arduino connector pin is used as input, output and LED */
#define INPUT_PIN   3
#define OUTPUT_PIN  4
#define GREEN_LED  13  // D13 is the on-board LED

/* specify delay between greetings (in ms); compute equivalent in ticks */

#define SLEEPTIME  500
#define SLEEPTICKS (SLEEPTIME * sys_clock_ticks_per_sec / 1000)


/*
 * main - GPIO demo
 *
 */
void main(void)
    {

    bool flag;
    int value;

    if (setup() != DEV_OK)
        return;

    flag = true;    // alternating true/false flag

    while (1)
        {
        if (flag)
            {
            //PRINT("D%d on\n", outputPin);
            gpio_output_set(GREEN_LED, 1);
            flag = false;
            }
        else
            {
            //PRINT("D%d off\n", outputPin);
            gpio_output_set(GREEN_LED, 0);
            flag = true;
            }

        if (gpio_input_get(INPUT_PIN, &value) == DEV_OK)
            {
            if (value == 0)
                {
                PRINT("D%d = Low\n", INPUT_PIN);
                gpio_output_set(OUTPUT_PIN, 0);
                }
            else
                {
                PRINT("D%d = High\n", INPUT_PIN);
                gpio_output_set(OUTPUT_PIN, 1);
                }
            }

        /* wait a while, then loop again */
        task_sleep(SLEEPTICKS);
        }
    }


